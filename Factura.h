#ifndef FACTURA_H
#define FACTURA_H
#include <string>
using namespace std;
class Factura{
	private:
		int id;
		int idCliente;
		char fecha[12];
	public:
		Factura(){};
		Factura(int, int, char*);
		void setId(int);
		void setIdCliente(int);
		void setFecha(char*);
		int getId();
		int getIdCliente();
		char* getFecha();
		void toString();
		string print();
};
#endif
