#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "Table.h"
class Producto:public Table{
	private:
		int id;
		int id_proveedor;
		int stock;
		float precio;
		char descripcion[45];
		int stock_min;
	public:
		Producto(){};
		Producto(int id, int id_proveedor, int stock, float precio, char* descripcion, int stock_min);
		void setId(int);
		void setIdProveedor(int);
		void setStock(int stock);
		void setPrecio(float);
		void setDescripcion(char[]);
		void setStockMin(int);
		int getId();
		int getIdProveedor();
		int getStock();
		float getPrecio();
		char* getDescripcion();
		int getStockMin();
		void toString();		
		std::string print();
};
#endif
