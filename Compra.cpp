#include "Compra.h"
#include <string>
using namespace std;
Compra::Compra(int id, int idProducto, int idFactura, int cantidad) {
	this->id = id;
	this->idProducto = idProducto;
	this->idFactura = idFactura;
	this->cantidad = cantidad;
}
int Compra::getId() {
	return this->id;
}
string Compra::print(){
	string data= to_string(id) + " " + to_string(idProducto) + " " + to_string(idFactura) + " " + to_string(cantidad);
	return data;
}
