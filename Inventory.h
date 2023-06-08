#include <cstdio>
#include <cstring>
#include <iostream>
#include "Client.h"
class Inventory{
	public: 
		void run(){
		    char name[45];
		    char direccion[75];
		    char telefono[18];
			int age;
			std::cout << "Enter your name: ";
		    std::cin.getline(name, sizeof(name));

			strcpy(direccion, "casa");
			strcpy(telefono, "127");

			Client* client = new Client(1, name, direccion, telefono);
			// printf("%s", client->getNombre());
			// printf("%d", client->getId());

			client->storeInDB();
		}
};
