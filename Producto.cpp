#include "Producto.h"
#include <iostream>
#include <cstring>

Producto::Producto(int id, int id_proveedor, int stock, float precio, char* descripcion, int stock_minimo): Table(id) {
	this->id= id;
	this->id_proveedor= id_proveedor;
	this->precio= precio;
	strcpy(this->descripcion, descripcion);
	this->stock_min= stock_minimo;
	this->stock= stock;
}
