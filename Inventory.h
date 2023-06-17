#include <cstdio>
#include <cstring>
#include <iostream>
#include "Client.h"
#include "User.h"
#include "Provider.h"
#include "DBConnection.h"
#include "Producto.h"
class Inventory{
	public: 
		void run(){
			DBConnection<User> connection= DBConnection<User>();
			// DBConnection<Provider> connection= DBConnection<Provider>();
			// User table= connection.getById(3);
			// string DBFile="db/users.dat";
			// connection.storeInDB(DBFile, table);
			// table.read();
			// signup();
			// connection.selectAll(DBFile);
			// connection.getLastItemId(DBFile);
			// createProvider();
			// connection.selectAll("db/provider.dat");
			// connection.deleteRecord("db/users.dat", 0);
			// char name[45] = "name";
			// char password[128] = "password";
			// User user= User(1, name, password, 1);
			// connection.updateRecord("db/users.dat", 0, user);
			// connection.selectAll("./db/users.dat");
			int userRole=0;
			if(userRole==0){
				adminFlow();

			}
			else if (userRole==1){
				sellerFlow();
			}
			else if(userRole==2){
				personalFlow();
		    }

		}
		void signup(){

		    char name[45];
			char password[128];
			int age;
			string DBFile="db/users.dat";
			std::cout << "Enter your name: ";
		    std::cin.getline(name, sizeof(name));

			std::cout << "Enter your password: ";
		    std::cin.getline(password, sizeof(password));

			DBConnection<User> connection=DBConnection<User>();
			int id=connection.getLastItemId(DBFile)+1;
			User* user=new User(id, name, password, 1);
			connection.storeInDB(DBFile, *user);
		}

		void login(){
		    char name[45];
			char password[128];
			int age;
			std::cout << "Enter your name: ";
		    std::cin.getline(name, sizeof(name));

			strcpy(password, "password");

			User* user = new User(1, name, password, 1);
			user->login(name, password);
		}

		void createProvider(){

		    char name[45]={"proveedor 1"};
			char phone[70]={"fasd"};
			string DBFile="db/provider.dat";

			DBConnection<Provider> connection=DBConnection<Provider>();
			int id=connection.getLastItemId(DBFile)+1;
			Provider* provider=new Provider(id, name, phone);
			connection.storeInDB(DBFile, *provider);
		}

		void sellerFlow(){
			string DBFile="db/clients.dat";
		    char telefono[18];
			char direccion[70];
			char nombre[45];
			int id;
			int idProducto;
			int cantidadProducto;
			cout << "Ingrese el id del cliente (cedula): ";
			cin >> id;
			DBConnection<Client> clientConnection=DBConnection<Client>();
			DBConnection<Producto> productConnection=DBConnection<Producto>();
			Client client = clientConnection.getById(DBFile, id);

			if(client.getId() !=id){
				printf("%s", "\nEl ID no coincide con ningún usuario en la base de datos, \npor favor ingrese los datos del nuevo cliente. \n\n");

				cout << "Nombre: ";
				cin.ignore();
				cin.getline(nombre, sizeof(nombre));

				cout << "Direccion: ";
				cin.getline(direccion, sizeof(direccion));

				cout << "Telefono: ";
				cin.getline(telefono, sizeof(telefono));

				Client *newClient = new Client(id, nombre, direccion, telefono);
				clientConnection.storeInDB(DBFile, *newClient);
			}
			cout << "Ingrese el ID del producto: ";
			cin >> idProducto;

			cout << "Ingrese la cantidad: ";
			cin >> cantidadProducto;

		}

		void adminFlow(){

		}

		void personalFlow(){

		}
	
	// void getOption(){
	//
	// }
};
