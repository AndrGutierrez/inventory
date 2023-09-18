#ifndef PROVIDER_H
#define PROVIDER_H
#include "Table.h"
#include <string.h>
using namespace std;
class Provider:public Table{
	private:
		int id;	
		char nombre[45];
		char telefono[30];
	public:
		Provider(){};
		Provider(int id, char* nombre, char* telefono);
		string print();
		int getId();
};
#endif
