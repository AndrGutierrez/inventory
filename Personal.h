#ifndef PERSONAL_H
#define PERSONAL_H
#include <iostream>
#include <cstring>
using namespace std;
#include "DBConnection.h"
#include "User.h"
#include "Producto.h"
class Personal{
public:
	void flow(){
			char nombre_archivo[24];
			cout << "Ingrese el nombre del archivo de actualizacion (los archivos deben encontrarse en la carpeta 'updatefiles', la extension del archivo se agregara automaticamente): ";
			cin.ignore();
			cin.getline(nombre_archivo, sizeof(nombre_archivo));
		
			string nombre_completo=string("./updatefiles/")+string(nombre_archivo) + ".csv";
			DBConnection<User> connection= DBConnection<User>();
			DBConnection<Producto> productConnection= DBConnection<Producto>();
			bool actualizado = productConnection.updateFromCSV(nombre_completo);
			productConnection.selectAll("./db/product.dat");
			if(actualizado){
				cout << "*****************************************************" << endl;
				cout << "* Se ha actualizado la base de datos de productos! * " <<endl;
				cout << "*****************************************************" << endl;

			}
	};
};
#endif
