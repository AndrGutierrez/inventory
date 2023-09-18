#ifndef MEZCLA_NATURAL_H
#define MEZCLA_NATURAL_H
#include <iostream>
#include <cstring>
#include "Client.h"
#include "DBConnection.h"
#include "Utils.h"
using namespace std;
template <class T>
class MezclaNatural{

	string aux1= "aux_files/aux_1.dat";
	string aux2= "aux_files/aux_2.dat";
	string result_file="aux_files/result.dat";
	Utils<T> utils;
	DBConnection<T> db= DBConnection<T>();
public:
	MezclaNatural(){}
	string switchAux(string auxname){
		if(auxname==aux1){
			return aux2;
		}
		return aux1;
	}
	
	void mezcla(int record_amount, string filename){
		T vacio;
		vacio.setId(-1);
		string selected_aux=aux1;
		int cantidad = 0;
		for(int i=1; i<=record_amount; i++){
			T record =utils.recorrer(i, filename);
			T next_record = utils.recorrer(i+1, filename);
			string name = record.getNombre();
			string next_name = next_record.getNombre();
			if(utils.isAlphabeticallySmaller(name, next_name)){
				db.storeInDB(selected_aux, record);
			}
			else if(i!=1 && utils.recorrer(i-1, selected_aux).getId()!=-1){
				db.storeInDB(selected_aux, vacio);
				selected_aux =switchAux(selected_aux);
			}
		}
	}
	void comparar(){
		int indice_aux1 = 1;
		int indice_aux2 = 1;
		
		while(utils.getRecordAmount(result_file) < 60){
		//
			T registro1 = utils.recorrer(indice_aux1, aux1);
			T registro2 = utils.recorrer(indice_aux2, aux2);

			string nombre1 = registro1.getNombre();
			string nombre2 = registro2.getNombre();
			bool grupo1_terminado = registro1.getId()==-1;
			bool grupo2_terminado = registro2.getId()==-1;
			

			while(grupo1_terminado && !grupo2_terminado){
				db.storeInDB(result_file, registro2);
				indice_aux2++;
				registro2 = utils.recorrer(indice_aux2, aux2);
				grupo2_terminado = registro2.getId()==-1;
			}
			if(utils.isAlphabeticallySmaller(nombre1, nombre2) &&!grupo1_terminado){
				db.storeInDB(result_file, registro1);
				indice_aux1++;
			}
			else if(grupo2_terminado==false){
				db.storeInDB(result_file, registro2);
				indice_aux2++;
			}

		}
	}
	void run(string filename){
		int n = utils.getRecordAmount(filename);
		// cout << n << endl;
		// string data1= db.selectAll("aux_files/aux_1.dat");
		// string data2= db.selectAll("aux_files/aux_2.dat");
		// cout << data1 << endl;
		// cout << "*************";
		// cout << data2 << endl;
		// cout << db.selectAll(filename) << endl;
		bool registros_desordenados=true;
		mezcla(n, filename);
		comparar();
		remove(aux1.c_str());
		remove(aux2.c_str());
		// cout << utils.getRecordAmount(result_file) << endl;
		cout << db.selectAll(result_file) << endl;
		int i=0;
		// while(i<=10){

		// mezcla(n, result_file);
		// remove(result_file.c_str());
		// comparar();
		// remove(aux1.c_str());
		// remove(aux2.c_str());
		// 	i++;
		// }

		// cout << db.selectAll(result_file) << endl;
		// remove(result_file.c_str());
	
		// T record = utils.recorrer(2, result_file);
		// cout << record.getNombre() << endl;
		// mezcla(n, result_file);
		// remove(result_file.c_str());
		// comparar();
		// remove(aux1.c_str());
		// remove(aux2.c_str());
		// cout << utils.getRecordAmount(result_file) << endl;
		// cout << utils.getRecordAmount(result_file) << endl;
		// cout << db.selectAll(result_file) << endl;
		// cout << db.selectAll(aux1) << endl;
		// cout << "*************" << endl;
		// cout << db.selectAll(aux2) << endl;
		remove(result_file.c_str());


		// LOOP:while(registros_desordenados){
		// 	// cout <<", "<< endl;
		// 	mezcla(n, result_file);
		// 	remove(result_file.c_str());
		// 	comparar();
		// 	remove(aux1.c_str());
		// 	remove(aux2.c_str());
		// 	for(int i=1; i<n-1; i++){
		// 		// cout << utils.getRecordAmount(result_file) <<endl;
		// 		T record = utils.recorrer(i, result_file);
		// 		T next_record = utils.recorrer(i+1, result_file);
		// 		string name = record.getNombre();
		// 		string next_name = next_record.getNombre();
		// 		if(!utils.isAlphabeticallySmaller(name, next_name)){
		// 			// cout << name << ", " << next_name << endl;
		//
		// 			// cout << "*************" << endl;
		// // cout << db.selectAll(result_file) << endl;
		// // cout << utils.getRecordAmount(result_file) << endl;
		// 			goto LOOP;
		// 		}
		// 		// db.storeInDB(filename, record);
		// 	}
		// 	registros_desordenados=false;
		// }
		

	}
};
#endif
