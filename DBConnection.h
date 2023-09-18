#ifndef DBCONNECTION
#define DBCONNECTION
#include "Table.h"
#include "User.h"
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

template <class T>
class DBConnection {

public:
	DBConnection(){};

	User getUserByName(char* inputName) {
		string DBFile="db/users.dat";
		ifstream in(DBFile, ios::binary);
		char empty[1]="";
		User user;
		while (in.read((char*)&user, sizeof(User))) {
			int userNameMatches = strcmp(user.getName(), inputName);
			if (userNameMatches == 0) {
				in.close();
				return user;
				// break;
				// out << "ID: " << user->getId() << ", Name: " << user->getName() << td::endl;
			}
		}
		in.close();
		return user;
	}
	T getById(string DBFile, int inputId){
		ifstream in(DBFile, ios::binary);
		T table;
		while (in.read((char*)&table, sizeof(T))) {
			if (table.getId()==inputId) {
				in.close();

				return table;
			}
		}
		in.close();
		T empty;
		return empty;
	}
	void storeInDB(string DBFile, T table){

		if(table.getId()==0) return;
		fstream outFile(DBFile, ios::binary | ios::app);
		if (!outFile) {
			std::cerr << "File could not be opened." << std::endl;
			return;
		}

		// T tables[] = {table};
		outFile.write((char*)&table, sizeof(T));
		outFile.close();
	}
	string selectAll(string DBFile){
		fstream arc;
		T buf;
		arc.open(DBFile,ios::binary | ios::in);
		string data;
		if(!arc) return "";
		while (true)
		{
			arc.read((char *)&buf,sizeof(buf));
			if (arc.eof()) break;
			 data+=buf.print()+"\n";
		}
		arc.close();
		return data;
	}
	vector<T> selectAllItems(string DBFile){
		fstream arc;
		T buf;
		vector<T> items;
		arc.open(DBFile,ios::binary | ios::in);
		string data;
		if(!arc) return items;
		while (true)
		{
			arc.read((char *)&buf,sizeof(buf));
			if (arc.eof()) break;
			if(buf.getId()!=0) items.push_back(buf);
		}
		arc.close();
		return items;
	}

	void update(string DBFile, int id){
		fstream arc;
		T buf;
		T table = getById(id);
		arc.open(DBFile,ios::binary | ios::in);
		while (true)
		{
			arc.read((char *)&buf,sizeof(buf));
			if (arc.eof()) break;
			buf.print();
		}
		arc.close();

	}
	int getLastItemId(string DBFile){
		fstream arc;
		arc.open(DBFile,ios::binary | ios::in);

		// if (!arc) {
		//     cerr << "Error: Unable to open input file\n";
		//     return 1;
		// }

		// determine the size of each record in the file
		if(!arc){
		// 	arc.open(DBFile,  fstream::in | fstream::out | fstream::trunc);
			arc <<"\n";
		}
		arc.seekg(0, ios::end);
		int record_size = arc.tellg() / sizeof(T);

		// extract the ID of the last record in the file
		T last_record;
		arc.seekg(-sizeof(T), ios::cur);
		arc.read((char*)&last_record, sizeof(T));
		int last_id = last_record.getId();
		if(last_id<0) last_id=0;

		arc.close();

		// cout << "The ID of the last record in the file is: " << last_id << endl;
		return last_id;

	}
	void deleteRecord(string DBFile, int id){
		fstream arc(DBFile, ios::binary | ios::in | ios::out);
		T table;
		streampos position =0;
		while (arc.read((char*)&table, sizeof(T))) {
			if (table.getId()==id) {
				// in.close();

				// printf("%s \n", table.getName());
				
				arc.seekp(position, ios::beg);
				T empty;
				arc.write((char*)&empty, sizeof(T));
				arc.put(0);
			}
			position=arc.tellg();
		}
		arc.close();
	}
	void updateRecord(string DBFile, int id, T updateData){

		fstream arc(DBFile, ios::binary | ios::in | ios::out);
		streampos position =0;
		T table;
		bool found=false;
		while (arc.read((char*)&table, sizeof(T))) {
			if (table.getId()==id) {
				// in.close();

				// printf("%s \n", table.getName());
				
				arc.seekp(position, ios::beg);
				// T empty;
				arc.write((char*)&updateData, sizeof(T));
				// arc.put(0);
				found = true;
			}
			position=arc.tellg();
		}
		if(!found){
			storeInDB(DBFile, updateData);
		}
		arc.close();
	}
	bool updateFromCSV(string fname){
		// cout<<"Enter the file name: ";
		// cin>>fname;
	 
		vector<vector<string>> content;
		vector<string> row;
		string line, word;
	 
		fstream file (fname, ios::in);
		if(file.is_open())
		{
			int single=0;
			while(getline(file, line))
			{
				row.clear();
	 
					if(single==0){
							single++;
							continue;
					}
				stringstream str(line);
	 
				while(getline(str, word, ',')){

					row.push_back(word);
				}
					content.push_back(row);

				
			}
		}
		else {
			cout << "**************************************"<<endl;
			cout << "El archivo seleccionado no se encontro"<<endl;
			cout << "**************************************"<<endl;
			return false;
		}
	 
		int proveedor_id;
		int stock;
		float precio;
		char* descripcion;
		int stock_minimo;
		for(int i=0;i<content.size();i++)
		{
				int rowId=stoi(content[i][0]);
				// if(rowId == id){
					proveedor_id=stoi(content[i][1]);
					stock=stoi(content[i][2]);
					precio=atof(content[i][3].c_str());
					descripcion=(char*)content[i][4].c_str();
					stock_minimo=stoi(content[i][5]);
				// }
				T product = {rowId, proveedor_id, stock, precio, descripcion, stock_minimo};
				// product.print();
				this->updateRecord("./db/product.dat", rowId, product);
		}
		return true;
	 
	};

	bool updateClientFromCSV(string fname){
		// cout<<"Enter the file name: ";
		// cin>>fname;
	 
		vector<vector<string>> content;
		vector<string> row;
		string line, word;
	 
		fstream file (fname, ios::in);
		if(file.is_open())
		{
			int single=0;
			while(getline(file, line))
			{
				row.clear();
	 
					if(single==0){
							single++;
							continue;
					}
				stringstream str(line);
	 
				while(getline(str, word, ',')){

					row.push_back(word);
				}
					content.push_back(row);

				
			}
		}
		else {
			cout << "**************************************"<<endl;
			cout << "El archivo seleccionado no se encontro"<<endl;
			cout << "**************************************"<<endl;
			return false;
		}
	 
		char* nombre;
		char* direccion;
		char* telefono;
		for(int i=0;i<content.size();i++)
		{
				int rowId=stoi(content[i][0]);
				// if(rowId == id){
					nombre=(char*)content[i][1].c_str();
					direccion=(char*)content[i][2].c_str();
					telefono=(char*)content[i][3].c_str();
				// }
				T client = {rowId, nombre, direccion, telefono};
				// product.print();
				this->updateRecord("./db/client.dat", rowId, client);
		}
		return true;
	 
	};
};
#endif
