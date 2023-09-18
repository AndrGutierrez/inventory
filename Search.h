#include <cstring>
#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <fstream>
#include "Producto.h"
#include "Client.h"
using namespace std;
 
// An iterative binary search function.
class Search{
public:
	Client recorrer(int line, string filename){
		ifstream in(filename, ios::binary);
		Client buf;
		for(int i=1; i<=line; i++){
			in.read((char*)&buf, sizeof(Client));
			if(i==line){
				return buf;
			}
		}
		in.close();
		return buf;
	}

	int getRecordAmount(string filename) {

		std::ifstream file(filename, std::ios::binary);
		if (!file) {
			std::ofstream newfile(filename, std::ios::binary);
			newfile.close();
			// std::cerr << "Error opening file." << std::endl;
			std::fstream file(filename, std::ios::binary);
			file.close();
			return 1;
		}

		// Seek to the end of the file to determine its size
		file.seekg(0, std::ios::end);
		std::streampos fileSize = file.tellg();

		// Calculate the number of records
		int recordSize = sizeof(Client);  // Replace 'Record' with your actual record structure
		int numRecords = fileSize / recordSize;

		// std::cout << "Number of records: " << numRecords << std::endl;
		file.close();
		return numRecords;
	}

	int binary(vector<Producto>arr, string x, int n) {
		int lower = 0;
		int upper = n-1;
		while (lower <= upper) {
			int mid = lower + (upper - lower) / 2;
			int res;
			string descripcion=arr[mid].getDescripcion();
			// printf("%s, %s\n", x.c_str(), descripcion.c_str());
			if (x == descripcion) 
				res = 0;
			if (res == 0) 
				return mid;
			if (x > descripcion) 
				lower = mid + 1;
			else 
				upper = mid - 1;
	   }
	   return -1;
	} 
	void indexedSequentialSearch(string filename, int n, string search){
		int GN = 3; // GN is group number that is number of
					// elements in a group
		int indices[GN], i, set = 1;
		int j = 1, ind = 1, start, end;
		if (search < recorrer(1, filename).getNombre()) {
			cout << recorrer(1, filename).getNombre() << endl;
			printf("Not found");
			exit(0);
		}
		else {
			for (i = 1; i <= ind; i++)
				if (search <= recorrer(i, filename).getNombre()) {
					start = indices[i - 1];
					end = indices[i];
					set = 1;
					break;
				}
		}
		if (set == 1) { 
			start = indices[GN - 1];
			end = GN;
		}
		for (i = start; i <= end; i++) {
			if (search == recorrer(i, filename).getNombre()) {
				j = 1;
				break;
			}
		}
		if (j == 1)
			printf("Found at index %d", i);
		else
			printf("Not found");
	}
 
// Driver code
void runIndexed(string search, string filename)
{
    // Element to search
	int n = getRecordAmount(filename);
    indexedSequentialSearch(filename, n, search);
}
	// Driver code
	// int main(void)
	// {
	// 	int arr[] = { 2, 3, 4, 10, 40 };
	// 	int x = 10;
	// 	int n = sizeof(arr) / sizeof(arr[0]);
	// 	int result = binary(arr, 0, n - 1, x);
	// 	(result == -1)
	// 		? cout << "Element is not present in array"
	// 		: cout << "Element is present at index " << result;
	// 	return 0;
	// }
};
