// C++ Program to sort
// array of strings
 
#ifndef MERGESORT_H
#define MERGESORT_H
#include <bits/stdc++.h>
#include "Client.h"
#include "DBConnection.h"
using namespace std;
template <typename T>
 
// Function to compare 2 words

class MezclaDirecta {
public:
	DBConnection<Client> clientConnection= DBConnection<Client>();
	Client recorrer(int line, string filename){
		ifstream in(filename, ios::binary);
		Client buf;
		for(int i=1; i<=line; i++){
			in.read((char*)&buf, sizeof(T));
			if(i==line){
				return buf;
			}
		}
		in.close();
		return buf;
	}
	MezclaDirecta() {}
	int getRecordAmount(string filename) {

		std::ifstream file(filename, std::ios::binary);
		if (!file) {
			std::ofstream newfile(filename, std::ios::binary);
			newfile.close();
			// std::cerr << "Error opening file." << std::endl;
			std::fstream file(filename, std::ios::binary);
			file.close();
			return 1;
		}

		// Seek to the end of the file to determine its size
		file.seekg(0, std::ios::end);
		std::streampos fileSize = file.tellg();

		// Calculate the number of records
		int recordSize = sizeof(Client);  // Replace 'Record' with your actual record structure
		int numRecords = fileSize / recordSize;

		// std::cout << "Number of records: " << numRecords << std::endl;

		file.close();
		return numRecords;
	}

	bool isAlphabeticallySmaller(string str1, string str2){
		transform(str1.begin(), str1.end(), str1.begin(),
				  ::toupper);
		transform(str2.begin(), str2.end(), str2.begin(),
				  ::toupper);
		if (str1 < str2) {
			return true;
		}
		return false;
	}
	 
	void merge(string archivo1, string archivo2, string archivoAuxiliar){
		int m = getRecordAmount(archivo1);	
		int n = getRecordAmount(archivo2);
	 
	 
		int i = 1;
		int j = 1;
		// cout << "m: " << m << "n: " << n << endl;
		while (i <= m && j <= n) {
			Client cliente1=recorrer(i, archivo1);
			Client cliente2=recorrer(j, archivo2);
			// cout << cliente1.getNombre() << endl;
			// cout << cliente2.getNombre() << endl;
			if (isAlphabeticallySmaller(cliente1.getNombre(), cliente2.getNombre())) {
				// cout << "a" <<endl;
				clientConnection.storeInDB(archivoAuxiliar, cliente1);
				i++;
			}
			else {
				// cout << "b" <<endl;
				clientConnection.storeInDB(archivoAuxiliar, cliente2);
				j++;
			}
		}
		while (i <= m) {
				// cout << m <<endl;
			clientConnection.storeInDB(archivoAuxiliar, recorrer(i, archivo1));
			i++;
		}
		while (j <= n) {
				// cout << "d" <<endl;
			clientConnection.storeInDB(archivoAuxiliar, recorrer(j, archivo2));
			j++;
		}
		// string data = clientConnection.selectAll(archivoAuxiliar);
		// cout << data << endl;
	}
	 
	// Function to mergeSort 2 arrays
	 void mergeSort(string file, int lo, int hi){
		// cout << "lo: " << lo << "hi: " << hi << endl;
		if (lo == hi) {
			clientConnection.storeInDB(file, recorrer(lo, "db/client.dat"));
			// cout << "a" <<endl;
			return;
			// vector<string> A = { Arr[lo] };
			// return A;
		}
		int mid = lo + (hi - lo) / 2;
		mergeSort("db/archivo1.dat", lo, mid);
		mergeSort("db/archivo2.dat", mid + 1, hi);

		merge("db/archivo1.dat", "db/archivo2.dat", "db/auxiliar.dat");
		remove("db/archivo1.dat");
		remove("db/archivo2.dat");
		// string data = clientConnection.selectAll("db/auxiliar.dat");	
		// cout << data << endl;
		rename("db/auxiliar.dat", file.c_str());
		return;
	}
	 
	// Driver code
	int run(string filename)
	{
		// Client cliente = recorrer(3);
		// cout << cliente.getNombre()<<endl;
		// vector<string> Arr
		int N = getRecordAmount("./db/client_copy.dat");
		mergeSort("./db/client_copy.dat", 0, N);
		string data = clientConnection.selectAll("./db/client_copy.dat");	
		// string data = clientConnection.selectAll("./db/client.dat");	
		cout << data << endl;
		return 0;
		// string line = "";

	}
 
};
#endif
