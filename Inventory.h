#include <cstdio>
#include <iostream>
#include "Client.h"
class Inventory{
	public: 
		void run(){
		    std::string name;
			int age;
			std::cout << "Enter your name: ";
		    std::getline(std::cin, name);  // Read a line of text including spaces
			Client* client = new Client(1, name);
			printf("%s", client->getName().c_str());

		}
};
