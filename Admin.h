#include <string>
#include <iostream>
#include "DBConnection.h"
#include "Producto.h"
#include "Factura.h"
#include "Provider.h"
#include "Compra.h"
#include "Client.h"
using namespace std;

string tablas[] = {"Productos", "Compras", "Proveedores", "Clientes", "Facturas"};
class Admin{
public:
	void flow(){

		int accion;
		cout << "Seleccione Que Desea Hacer: " << endl;
		printf("1. Insertar\n2. Actualizar\n3. Eliminar\n4. Seleccionar Todo\n5. Salir\n Ingrese el Numero de correspondiente a la accion: ");
		cin >> accion;
		switch(accion){
			case 1:
				insert();
				break;
			case 2:
				update();
				break;
			case 3:
				remove();
				break;
			case 4:
				selectAll();
				break;
			case 5:
				break;
			default:
				cout << "Opcion Invalida" << endl;
				break;
		}
	}
	void update(){
		int table = selectTable();

		DBConnection<Client> clientConnection=DBConnection<Client>();
		string clientFile="./db/client.dat";
		char nombreCliente[45];
		char direccionCliente[70];
		char telefonoCliente[18];
		int idCliente=clientConnection.getLastItemId(clientFile)+1;

		
		string invoiceFile="db/invoice.dat";
		DBConnection<Factura> invoiceConnection=DBConnection<Factura>();
		int idFactura=invoiceConnection.getLastItemId(invoiceFile)+1;
		char fecha[12];

		string providerFile="db/provider.dat";
		DBConnection<Provider> providerConnection=DBConnection<Provider>();
		int idProveedor=providerConnection.getLastItemId(providerFile)+1;
		char nombreProveedor[45]="Empresas Polar";
		char telefonoProveedor[30]="0212-1234567";
		
		string productFile="db/product.dat";
		DBConnection<Producto> productConnection=DBConnection<Producto>();
		int idProducto=productConnection.getLastItemId(productFile)+1;
		int stockProducto;
		float precioProducto;
		int stockMinimoProducto;
		char descripcionProducto[45];

		string purchaseFile="db/purchase.dat";
		DBConnection<Compra> purchaseConnection=DBConnection<Compra>();
		int cantidadComprada=10;
		int idCompra = purchaseConnection.getLastItemId(purchaseFile)+1;

		if(table>5){
			cout << "Opcion Invalida" << endl;
			return;

		}
		int recordId;
		cout << "***************************************" << endl;
		cout << "Inserte el ID del Registro que desea actualizar\n Si no existe, se creara un registro con los mismos datos: " << endl;
		cout << "***************************************" << endl;
		cout << "ID: ";
		cin >> recordId;
		if(table==1){
			cout << "\nInsertar datos de producto: " << endl;
			cout << "1. Id Proveedor: ";
			cin >> idProveedor;
			cout << "\n2. Stock: ";
			cin >> stockProducto;
			cout << "\n3. Precio: ";
			cin >> precioProducto;
			cout << "\n4. Descripcion: ";
			cin >> descripcionProducto;
			cout << "\n5. stockMinimoProducto: ";
			cin >> descripcionProducto;
			Producto producto = {recordId, idProveedor, stockProducto, precioProducto, descripcionProducto, stockMinimoProducto};
			productConnection.updateRecord(productFile, recordId, producto);
				
		}
		else if(table==2){
			cout << "Insertar datos de la factura: " << endl;
			cout << "1. Id Cliente: ";
			cin >> idCliente;
			cout << "\n2. Fecha: ";
			cin >> fecha;
			Factura factura = {recordId, idCliente, fecha};
			invoiceConnection.updateRecord(invoiceFile, recordId, factura);
		}
		else if(table==3){
			cout << "Insertar datos de la compra: " << endl;
			cout << "1. Id producto: ";
			cin >> idProducto;
			cout << "\n2. Id factura: ";
			cin >> idFactura;
			cout << "\n3. Cantidad: ";
			cin >> cantidadComprada;
			Compra compra = {recordId, idProducto, idFactura, cantidadComprada};	
			Producto producto = productConnection.getById(productFile, idProducto);
			if(producto.getId()==idProducto){

				if(cantidadComprada <= producto.getStock()){
					producto.setStock(producto.getStock()-cantidadComprada);
					productConnection.updateRecord(productFile, idProducto, producto);
					purchaseConnection.updateRecord(purchaseFile, recordId, compra);
				}
				else{
					cout << "No hay suficiente stock" << endl;
				}
			}
			else{
				cout << "El producto que selecciono no existe"<<endl;
			}
		}
		else if(table==4){
			cout << "Insertar datos de Proveedor: " << endl;
			cout << "1. Nombre: ";
			cin >> nombreProveedor;
			cout << "\n2. Telefono: ";
			cin >> telefonoProveedor;
			Provider proveedor={recordId, nombreProveedor, telefonoProveedor};
			providerConnection.updateRecord(providerFile, recordId, proveedor);
		}
		else if(table==5){
			cout << "Insertar datos de Proveedor: " << endl;
			cout << "1. Nombre: ";
			cin >> nombreCliente;
			cout << "\n2. Telefono: ";
			cin >> telefonoCliente;
			cout << "\n3. Direccion: ";
			cin >> direccionCliente;
			Client cliente={recordId, nombreCliente, direccionCliente, telefonoCliente}; 
			clientConnection.updateRecord(clientFile, recordId, cliente);
		}
		else{
		}

	}

	void insert(){
		int table = selectTable();

		DBConnection<Client> clientConnection=DBConnection<Client>();
		string clientFile="./db/client.dat";
		char nombreCliente[45];
		char direccionCliente[70];
		char telefonoCliente[18];
		int idCliente=clientConnection.getLastItemId(clientFile)+1;

		
		string invoiceFile="db/invoice.dat";
		DBConnection<Factura> invoiceConnection=DBConnection<Factura>();
		int idFactura=invoiceConnection.getLastItemId(invoiceFile)+1;
		char fecha[12];

		string providerFile="db/provider.dat";
		DBConnection<Provider> providerConnection=DBConnection<Provider>();
		int idProveedor=providerConnection.getLastItemId(providerFile)+1;
		char nombreProveedor[45]="Empresas Polar";
		char telefonoProveedor[30]="0212-1234567";
		
		string productFile="db/product.dat";
		DBConnection<Producto> productConnection=DBConnection<Producto>();
		int idProducto=productConnection.getLastItemId(productFile)+1;
		int stockProducto;
		float precioProducto;
		int stockMinimoProducto;
		char descripcionProducto[45];

		string purchaseFile="db/purchase.dat";
		DBConnection<Compra> purchaseConnection=DBConnection<Compra>();
		int cantidadComprada=10;
		int idCompra = purchaseConnection.getLastItemId(purchaseFile)+1;

		if(table>5){
			cout << "Opcion Invalida" << endl;
			return;

		}
		if(table==1){
			cout << "Insertar datos de producto: " << endl;
			cout << "1. Id Proveedor: ";
			cin >> idProveedor;
			cout << "\n2. Stock: ";
			cin >> stockProducto;
			cout << "\n3. Precio: ";
			cin >> precioProducto;
			cout << "\n4. Descripcion: ";
			cin >> descripcionProducto;
			cout << "\n5. stockMinimoProducto: ";
			cin >> descripcionProducto;
			Producto producto = {idProducto, idProveedor, stockProducto, precioProducto, descripcionProducto, stockMinimoProducto};
			productConnection.storeInDB(productFile, producto);
				
		}
		else if(table==2){
			cout << "Insertar datos de la factura: " << endl;
			cout << "1. Id Cliente: ";
			cin >> idCliente;
			cout << "\n2. Fecha: ";
			cin >> fecha;
			Factura factura = {idFactura, idCliente, fecha};
			invoiceConnection.storeInDB(invoiceFile, factura);
		}
		else if(table==3){
			cout << "Insertar datos de la compra: " << endl;
			cout << "1. Id producto: ";
			cin >> idProducto;
			cout << "\n2. Id factura: ";
			cin >> idFactura;
			cout << "\n3. Cantidad: ";
			cin >> cantidadComprada;
			Compra compra = {idCompra, idProducto, idFactura, cantidadComprada};	
			Producto producto = productConnection.getById(productFile, idProducto);
			if(producto.getId()==idProducto){
				if(cantidadComprada <= producto.getStock()){
					producto.setStock(producto.getStock()-cantidadComprada);
					productConnection.updateRecord(productFile, idProducto, producto);
					purchaseConnection.storeInDB(purchaseFile, compra);
				}
				else{
					cout << "No hay suficiente stock" << endl;
				}
			}
			else{
				cout << "El producto seleccionado no existe" << endl;
			}
		}
		else if(table==4){
			cout << "Insertar datos de Proveedor: " << endl;
			cout << "1. Nombre: ";
			cin >> nombreProveedor;
			cout << "\n2. Telefono: ";
			cin >> telefonoProveedor;
			Provider proveedor={idProveedor, nombreProveedor, telefonoProveedor};
			providerConnection.storeInDB(providerFile, proveedor);
		}
		else if(table==5){
			cout << "Insertar datos de Proveedor: " << endl;
			cout << "1. Nombre: ";
			cin >> nombreCliente;
			cout << "\n2. Telefono: ";
			cin >> telefonoCliente;
			cout << "\n3. Direccion: ";
			cin >> direccionCliente;
			Client cliente={idCliente, nombreCliente, direccionCliente, telefonoCliente}; 
			clientConnection.storeInDB(clientFile, cliente);
		}
		else{
		}

	}
	void remove(){
		int table = selectTable();
		int id;
		if(table>5){
			cout << "Opcion Invalida" << endl;
			return;

		}
		cout << "Inserte el ID del Registro que desea eliminar: ";
		cin >> id;
		if(table==1){
				DBConnection<Producto> conn;
				conn.deleteRecord("./db/product.dat", id);
		}
		else if(table==2){
				DBConnection<Factura> conn;
				conn.deleteRecord("./db/invoice.dat", id);
		}
		else if(table==3){
				DBConnection<Compra> conn;
				conn.deleteRecord("./db/purchase.dat", id);
		}
		else if(table==4){
				DBConnection<Provider> conn;
				conn.deleteRecord("./db/provider.dat", id);
		}
		else if(table==5){
				DBConnection<Client> conn;
				conn.deleteRecord("./db/client.dat", id);
		}
		else{
		}
		
	}
	void selectAll(){
		int table = selectTable();
		cout << "***************************************" << endl;
		if(table==1){
				DBConnection<Producto> conn;
				cout << "Productos: " << endl;
				cout << "***************************************" << endl;
				printf("%s", conn.selectAll("./db/product.dat").c_str());
		}
		else if(table==2){
				DBConnection<Factura> conn;
				cout << "Facturas: " << endl;
				cout << "***************************************" << endl;
				printf("%s", conn.selectAll("./db/invoice.dat").c_str());
		}
		else if(table==3){
				DBConnection<Compra> conn;
				cout << "Compras: " << endl;
				cout << "***************************************" << endl;
				printf("%s", conn.selectAll("./db/purchase.dat").c_str());
		}
		else if(table==4){
				DBConnection<Provider> conn;
				cout << "Proveedores: " << endl;
				cout << "***************************************" << endl;
				printf("%s", conn.selectAll("./db/provider.dat").c_str());
		}
		else if(table==5){
				DBConnection<Client> conn;
				cout << "Clientes: " << endl;
				cout << "***************************************" << endl;
				printf("%s", conn.selectAll("./db/client.dat").c_str());
		}
		else{
			cout << "Opcion Invalida" << endl;
		}

	}
	int selectTable(){
		int tabla;
		cout << "**************************************************" << endl;
		cout << "Inserte sobre cual tabla desea realizar la accion: " << endl;
		cout << "**************************************************" << endl;
		printf("1. Productos \n2. Facturas \n3. Compras \n4. Proveedores \n5. Clientes \nIngrese el Numero de correspondiente a la tabla: ");

		cin >> tabla; 
		return tabla;
	}
};
