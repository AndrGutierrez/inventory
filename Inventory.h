#include <cstdio>
#include <cstring>
#include <iostream>
#include "Client.h"
#include "User.h"
#include "Provider.h"
#include "DBConnection.h"
#include "Producto.h"
#include "Seller.h"
#include "Personal.h"
#include "Factura.h"
#include "Compra.h"
#include "Admin.h"

#define GET_VARIABLE_NAME(Variable) (#Variable)

class Inventory{
	public: 
		void run(){
			DBConnection<User> connection= DBConnection<User>();
			// User user={1, "admin", "admin", 0};
			// connection.storeInDB("./db/users.dat", user);
			// signup();
			// DBConnection<Producto> productConnection=DBConnection<Producto>();
			// productConnection.selectAll("./db/product.dat");
			 User user= welcome();	
			string rol;
			switch(user.getRole()){
				case 0:
					rol="Administrador";
					break;
				case 1:
					rol="Vendedor";
					break;
				case 2:
					rol="Personal";
					break;
			}
			printf("\n********************************************************** \n");
			printf("* Inicio de sesion exitoso. ");
			printf("Bienvenido %s (%s) *", user.getName(), rol.c_str());
			printf("\n********************************************************** \n");
			int userRole=user.getRole();
			Seller seller;
			Personal personal;
			Admin admin;
			int option;
			

			
			bool finished=false;
			int install;
			while(!finished){

				cout << "Desea crear una base de datos de prueba \n (Recomendado para el correcto funcionamiento de instalaciones nuevas): \n";
				cout << "1. Si \n2. No \nSeleccione: ";
				cin >> install;
				if(install==1){
					cargarDatosDePrueba();
				}
				finished=true;
			}
			finished=false;
			
			while(!finished){	
				if(userRole==0){
					admin.flow();
				}
				else if (userRole==1){
					seller.flow();
				}
				else if(userRole==2){
					personal.flow();
				}

				cout << "\nDesea seguir haciendo operaciones? \n1. Continuar\n2. Salir \nSeleccione: ";
				cin >> option;
				switch(option){
					case 1:
						finished=false;
						break;
					case 2:
						finished=true;
						break;
					default:
						cout << "La opcion seleccionada no es valida, se continuara con el flujo de operaciones" << endl;
				}
			}
		}



		User signup(){

			DBConnection<User> connection=DBConnection<User>();
		    char name[32];
			char password[128];
			int role;
			string DBFile="./db/users.dat";
			cout << "Ingrese su nombre: ";
			cin.ignore();
			cin.getline(name, sizeof(name));
			cout << "Ingrese su contrasena: ";
			cin.getline(password, sizeof(password));
			while(true){
				cout << "Ingrese el rol del usuario \n";
				cout << "Admin (0), Vendedor (1), Personal(2): ";
				cin >> role;
				if(role==0 || role==1 || role==2){
					break;
				}
				else{
					cout << "************************************************" << endl;
					cout << "El rol ingresado no es valido, intente de nuevo" << endl;
					cout << "************************************************" << endl;

					cin.ignore();
				}
			
			}
			

			int id=connection.getLastItemId(DBFile)+1;
			User user={id, name, password, role};
			connection.storeInDB("./db/users.dat", user);
			return user;
		}

		User login(){
			DBConnection<User> connection= DBConnection<User>();
		    char name[45];
			char password[128];
			int age;


			User user;
			
			bool logged_in = false;
			while(!logged_in){
				cout << "Ingrese su nombre: ";
				cin.ignore();
				cin.getline(name, sizeof(name));
				cout << "Ingrese su contrasena: ";
				cin.getline(password, sizeof(password));
				logged_in = user.login(name, password);
			}
			User currentUser= connection.getUserByName(name);
			return currentUser;
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

		void adminFlow(){
			
			
		}

		User welcome(){
			int option;
			printf("*************************************** \n");
			printf("* Bienvenido al sistema de inventario *\n");
			printf("*************************************** \n");
			User user;
			bool finished= false;
			while(!finished){	
				printf("1. Iniciar sesion \n");
				printf("2. Registrarse \n");
				printf("Ingrese la opcion deseada (1 o 2): ");
				cin >> option;
				switch(option){
					case 1:
						user = login();
						finished=true;
						break;
					case 2:
						user =signup();
						finished=true;
						break;
					default:
						cout << "************************************************" << endl;
						cout << "Opcion invalida por favor intente de nuevo" << endl;
						cout << "************************************************" << endl;
						
						break;
				}
			}
			return user;

		}
		void cargarDatosDePrueba(){
			DBConnection<Client> clientConnection=DBConnection<Client>();
			string clientFile="db/client.dat";
			char nombreCliente[45]="Pedro";
			char direccionCliente[70]="Las Acacias";
			char telefonoCliente[18]="0414-1234567";
			int idCliente=clientConnection.getLastItemId(clientFile)+1;
			Client cliente={idCliente, nombreCliente, direccionCliente, telefonoCliente};
			clientConnection.storeInDB(clientFile, cliente);

			
			string invoiceFile="db/invoice.dat";
			DBConnection<Factura> invoiceConnection=DBConnection<Factura>();
			int idFactura=invoiceConnection.getLastItemId(invoiceFile)+1;
			char fecha[12]="2020-12-12";
			Factura factura = {idFactura, idCliente, fecha};
			invoiceConnection.storeInDB(invoiceFile, factura);

			string providerFile="db/provider.dat";
			DBConnection<Provider> providerConnection=DBConnection<Provider>();
			int idProveedor=providerConnection.getLastItemId(providerFile)+1;
			char nombreProveedor[45]="Empresas Polar";
			char telefonoProveedor[30]="0212-1234567";
			Provider proveedor={idProveedor, nombreProveedor, telefonoProveedor};
			providerConnection.storeInDB(providerFile, proveedor);
			
			string productFile="db/product.dat";
			DBConnection<Producto> productConnection=DBConnection<Producto>();
			int idProducto=productConnection.getLastItemId(productFile)+1;
			int stockProducto=50;
			float precioProducto=100.0;
			int stockMinimoProducto=10;
			char descripcionProducto[45]="Pepsi Cola";
			Producto producto = {idProducto, idProveedor, stockProducto, precioProducto, descripcionProducto, stockMinimoProducto};
			productConnection.storeInDB(productFile, producto);

			string purchaseFile="db/purchase.dat";
			DBConnection<Compra> purchaseConnection=DBConnection<Compra>();
			int cantidadComprada=10;
			int idCompra = purchaseConnection.getLastItemId(purchaseFile)+1;
			Compra compra = {idCompra, idProducto, idFactura, cantidadComprada};	
			purchaseConnection.storeInDB(purchaseFile, compra);
			cout << "\n*****************************************" << endl;
			cout << "* Datos de prueba cargados exitosamente *" << endl;
			cout << "*****************************************" << endl;

		}
	
};
