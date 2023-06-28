#include "Inventory.h"
#include "QuickSort.h"
int main(){
	// Inventory inventory;
	// inventory.cargarDatosDePrueba();
		// inventory.run();
	string productFile="db/product.dat";
	DBConnection<Producto> productConnection= DBConnection<Producto>();
	vector<Producto> productos=productConnection.selectAllItems(productFile);
	int size=productos.size();
	int iniciales[size];
	for (int i=0; i<size; i++) {
		iniciales[i]=(int) toupper(productos[i].getDescripcion()[0]);
		cout << productos[i].getId() << endl;
		printf("%d, %s \n", iniciales[i], productos[i].getDescripcion());
	}
	QuickSort qs;
	qs.sort(iniciales, 0, size-1);
	for (int i=0; i<size; i++) {
		printf("%d \n", iniciales[i]);
	}


	return 0;
}
