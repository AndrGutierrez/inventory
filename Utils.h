#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
template <class T>
class Utils{
public:
	T recorrer(int line, string filename){
		ifstream in(filename, ios::binary);
		T buf;
		for(int i=1; i<=line; i++){
			in.read((char*)&buf, sizeof(T));
			if(i==line){
				in.close();
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
			// return 1;
		}

		// Seek to the end of the file to determine its size
		file.seekg(0, std::ios::end);
		std::streampos fileSize = file.tellg();

		// Calculate the number of records
		int recordSize = sizeof(T);  // Replace 'Record' with your actual record structure
		int numRecords = fileSize / recordSize;

		// std::cout << "Number of records: " << numRecords << std::endl;

		file.close();
		return numRecords;
	}
	bool isAlphabeticallySmaller(string str1, string str2){
		transform(str1.begin(), str1.end(), str1.begin(),
				  ::toupper);
		transform(str2.begin(), str2.end(), str2.begin(),
				  ::toupper);
		if (str1 < str2) {
			return true;
		}
		return false;
	}
};
#endif
