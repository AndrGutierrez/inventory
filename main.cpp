#include "Client.h"
#include "Inventory.h"
#include "Sorters.h"
#include "Search.h"
#include "MergeSort.h"
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

int main(){
	// DBConnection<Client> clientConnection= DBConnection<Client>();
	// string data=clientConnection.selectAll("db/client.dat");
	// cout<<data<<endl;
	// Inventory inventory;
	// inventory.run();
	// calc_time(quicksort);
	MergeSort<Client> mergeSort;
	mergeSort.run();
	return 0;
}
