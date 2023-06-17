#include "Producto.h"
#include <iostream>
#include <cstring>
using namespace std;

Producto::Producto(int id, int id_proveedor, int stock, float precio, char* descripcion, int stock_minimo): Table(id) {
	this->id= id;
	this->id_proveedor= id_proveedor;
	this->precio= precio;
	strcpy(this->descripcion, descripcion);
	this->stock_min= stock_minimo;
	this->stock= stock;
}
string Producto::print(){
	string data = to_string(this->id) + " " + to_string(this->id_proveedor) + " " + to_string(this->stock) + " " + to_string(this->precio) + " " + this->descripcion + " " + to_string(this->stock_min);
	printf("%s \n", data.c_str());
	return data;

}
int Producto::getId(){
	return this->id;
}
