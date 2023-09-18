#ifndef COMPRA_H
#define COMPRA_H
#include <string>
using namespace std;
class Compra {
	private:
		int id;
		int idProducto;
		int idFactura;
		int cantidad;
	
	public:
		Compra(){};
		Compra(int id, int idProducto, int idFactura, int cantidad);
		int getId();
		string print();
};
#endif
