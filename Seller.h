#ifndef SELLER_H
#define SELLER_H
#include <iostream>
#include <string>
#include "Client.h"
#include "DBConnection.h"
#include "Producto.h"


class Seller{
public: 
	void flow(){
			string clientFile="db/client.dat";
			string productFile="./db/product.dat";
		    char telefono[18];
			char direccion[70];
			char nombre[45];
			int idCliente;
			int idProducto;
			int cantidadProducto;
			cout << "Ingrese el id del cliente (cedula): ";
			cin >> idCliente;
			DBConnection<Client> clientConnection=DBConnection<Client>();
			DBConnection<Producto> productConnection=DBConnection<Producto>();
			Client client = clientConnection.getById(clientFile, idCliente);

			if(client.getId() !=idCliente){
				printf("%s", "\nEl ID no coincide con ningún usuario en la base de datos, \npor favor ingrese los datos del nuevo cliente. \n\n");

				cout << "Nombre: ";
				cin.ignore();
				cin.getline(nombre, sizeof(nombre));

				cout << "Direccion: ";
				cin.getline(direccion, sizeof(direccion));

				cout << "Telefono: ";
				cin.getline(telefono, sizeof(telefono));

				Client *newClient = new Client(idCliente, nombre, direccion, telefono);
				clientConnection.storeInDB(clientFile, *newClient);
			}
			cout << "Ingrese el ID del producto: ";
			cin >> idProducto;

			cout << "Ingrese la cantidad: ";
			cin >> cantidadProducto;
			
			Producto producto = productConnection.getById(productFile, idProducto);
			if(cantidadProducto > producto.getStock()){
				printf("%s", "\nLa cantidad ingresada es mayor a la cantidad disponible en el inventario.\n");
			}

			else{
				producto.setStock(producto.getStock() - cantidadProducto);
				printf("***********\n"); 
				printf("Reporte Guardado en reportes/reporte.txt\n");
				printf("***********\n");
				productConnection.updateRecord(productFile, idProducto, producto);
				imprimirReporte();
			}

	}
	void imprimirReporte(){
			DBConnection<Producto> productConnection=DBConnection<Producto>();
			string data= productConnection.selectAll("./db/product.dat").c_str();

			std::ofstream outfile ("reportes/reporte.txt");

			outfile << data << std::endl;
			outfile.close();

	}

};
#endif
