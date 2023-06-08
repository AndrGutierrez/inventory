#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Table.h"

class Client: public Table {
	private:
		int id;
		char nombre[45];

	public:
		Client(int id, char* nombre);

		char* getNombre();
		void setNombre(char* nombre);
};

#endif

