#include <cstdio>
#include <cstring>
#include <iostream>
#include "Client.h"
#include "User.h"
#include "DBConnection.h"
class Inventory{
	public: 
		void run(){
			// login();
			// signup();
			DBConnection<User> connection= DBConnection<User>();
			User table= connection.getById(4);
			printf("%s", table.getName());

		}
		void signup(){

		    char name[45];
			char password[128];
			int age;
			int id=1;
			std::cout << "Enter your name: ";
		    std::cin.getline(name, sizeof(name));

			std::cout << "Enter your password: ";
		    std::cin.getline(password, sizeof(password));

			DBConnection<User> connection;	
			User users[]={{id, name, password, 1}};
			while(connection.getUserById(id)!=NULL){
				id++;
			}
			users->storeInDB(id, name, password, 1);
			// 
			// printf("%d", id);
			// User* user = new User(id, name, password, 1);
			// user->getById(id);
			// user->storeInDB();
			users->read();
		}
		void login(){
		    char name[45];
			char password[128];
			int age;
			std::cout << "Enter your name: ";
		    std::cin.getline(name, sizeof(name));

			strcpy(password, "password");

		
			User* user = new User(1, name, password, 1);
			// user->read();
			user->login(name, password);
		}
};
