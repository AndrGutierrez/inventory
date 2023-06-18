
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "Provider.h"
using namespace std;

Provider::Provider(int id, char* nombre, char* telefono):Table(id){
			this->id=id;
			strcpy(this->nombre,nombre);
			strcpy(this->telefono,telefono);
}
string Provider::print(){
	string data= to_string(id) + " " + nombre + " " + telefono;
	return data;
}
int Provider::getId(){
	return this->id;
}
