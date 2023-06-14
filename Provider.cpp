
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "Provider.h"

Provider::Provider(int id, char* nombre, char* telefono):Table(id){
			this->id=id;
			strcpy(this->nombre,nombre);
			strcpy(this->telefono,telefono);
}
void Provider::print(){
	printf("%d %s %s\n", id, nombre, telefono);
}
