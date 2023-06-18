#include "Factura.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace::std;

Factura::Factura(int id, int idCliente, char* fecha){
	this->id = id;
	this->idCliente = idCliente;
	strcpy(this->fecha, fecha);
}
int Factura::getId(){
	return this->id;
}
string Factura::print(){
	string data=to_string(this->id) +" " + to_string(this->idCliente) +" "+this->fecha;
	return data;
}
