#include "Client.h"
#include "Inventory.h"
#include "Sorters.h"
#include "Search.h"
#include "MergeSort.h"
#include "MezclaNatural.h"
#include <chrono>
#include <thread>
#include <functional>



void quicksort(){
	string productFile="db/product.dat";
	DBConnection<Producto> productConnection= DBConnection<Producto>();
	vector<Producto> productos=productConnection.selectAllItems(productFile);
	int size=productos.size();

	Sorters sorters;
	vector<Producto> productos_ordenados=sorters.quicksort(productos, 0, size-1);
	Search searcher;
	string search=productos_ordenados[46].getDescripcion();
	int index= searcher.binary(productos_ordenados, search, size);
	printf("%d \n", index);
}
void long_operation()
{
    /* Simulating a long, heavy operation. */
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(150ms);
}

int calc_time(function<void()> func){
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    // long_operation();
	func();
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_double.count() << "ms\n";
    return 0;
}

void clientFlow(){

		MergeSort<Client> mergeSort;
		Search searcher;
		int accion;
		string name;
		
		cout << "Seleccione Que Desea Hacer: " << endl;
		printf("1. Listar\n2. Ordenar y listar\n3. Buscar \nIngrese el Numero de correspondiente a la accion: ");
		cin >> accion;
		string filename="db/clientes_ordenados.dat";
		DBConnection<Client> clientConnection= DBConnection<Client>();
		string data = clientConnection.selectAll("db/client.dat");
		switch(accion){
			case 1:
				cout << data << endl;
				break;
			case 2:
				mergeSort.run(filename);
				remove("db/clientes_ordenados.dat");
				break;
			case 3:
				cout << "Ingrese el nombre que quiere buscar: " << endl;
				cin >> name;
				mergeSort.run(filename);

				searcher.runIndexed(name, filename);
				remove(filename.c_str());
				break;
			default:
				cout << "Opcion Invalida" << endl;
				break;
		}

}

void productFlow(){

}

void getUserInput(){

		int accion;
		cout << "Seleccione Que Desea Hacer: " << endl;
		printf("1. Operaciones con Productos\n2. Operaciones con clientes\n Ingrese el Numero de correspondiente a la accion: ");
		cin >> accion;
		switch(accion){
			case 1:
				productFlow();
				break;
			case 2:
				clientFlow();
				break;
			default:
				cout << "Opcion Invalida" << endl;
				break;
		}

}

int main(){
	// DBConnection<Client> clientConnection= DBConnection<Client>();
	// getUserInput();
	MezclaNatural<Client> mezclaNatural = MezclaNatural<Client>();
	mezclaNatural.run("db/client_copy.dat");
	// string data=clientConnection.selectAll("db/client.dat");
	// cout<<data<<endl;
	// Inventory inventory;
	// inventory.run();
	// calc_time(quicksort);
	return 0;
}
