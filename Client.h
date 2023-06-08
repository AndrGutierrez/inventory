#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Table.h"
#include <iostream>
#include <fstream>
using namespace std;

const int NAME_SIZE = 45;
class Client: public Table {
	private:
		int id;
		char nombre[NAME_SIZE];
		char direccion[70];
		char telefono[18];

	public:
		Client(int id, char* nombre, char* direccion, char* telefono);

		char* getNombre();
		char* getDireccion();
		char* getTelefono();
		void setNombre(char* nombre);
		void storeInDB();
		void writePerson(const std::string& filename, const Client& person);

};


#endif
