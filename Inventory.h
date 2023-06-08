#include <cstdio>
#include <iostream>
#include "Client.h"
class Inventory{
	public: 
		void run(){
		    char name[45];
			int age;
			std::cout << "Enter your name: ";
		    std::cin.getline(name, sizeof(name));


		    // std::getline(std::cin, name);  // Read a line of text including spaces
			Client* client = new Client(1, name);
			printf("%s", client->getNombre());
			printf("%d", client->getId());

		}
};
