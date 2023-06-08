#include <cstdio>
#include <cstring>
#include <iostream>
#include "Client.h"
#include "User.h"
class Inventory{
	public: 
		void run(){
			
		}
		void signup(){

		    char name[45];
			char password[128];
			int age;
			std::cout << "Enter your name: ";
		    std::cin.getline(name, sizeof(name));

			strcpy(password, "password");

		
			User* user = new User(1, name, password, 1);
			user->storeInDB();
			user->read();
		}
};
