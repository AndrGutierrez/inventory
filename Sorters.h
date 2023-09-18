#include <iostream>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Producto.h"
using namespace std;
class Sorters{
public:
	vector <Producto> arr;

	int partition(int low, int high) {
		char* pivot = arr[high].getDescripcion();  // Choosing the last element as the pivot
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++) {
			if (strcmp(arr[j].getDescripcion(), pivot) < 0) {
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[high]);
		return (i + 1);
	}

	// Quicksort function
	vector<Producto> quicksort(vector<Producto> products, int low, int high) {
		arr=products;
		if (low < high) {
			int pi = partition(low, high);

			quicksort(arr, low, pi - 1);
			quicksort(arr, pi + 1, high);
		}
		return arr;
	}



};
