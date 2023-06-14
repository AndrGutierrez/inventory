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
			// User table= connection.getById(3);
			string DBFile="db/users.dat";
			// connection.storeInDB(DBFile, table);
			// table.read();
			signup();
			connection.selectAll(DBFile);
			// connection.getLastItemId(DBFile);

		}
		void signup(){

		    char name[45];
			char password[128];
			int age;
			string DBFile="db/users.dat";
			std::cout << "Enter your name: ";
		    std::cin.getline(name, sizeof(name));

			std::cout << "Enter your password: ";
		    std::cin.getline(password, sizeof(password));

			DBConnection<User> connection=DBConnection<User>();
			int id=connection.getLastItemId(DBFile)+1;
			User* user=new User(id, name, password, 1);
			connection.storeInDB(DBFile, *user);
		}
		void login(){
		    char name[45];
			char password[128];
			int age;
			std::cout << "Enter your name: ";
		    std::cin.getline(name, sizeof(name));

			strcpy(password, "password");

			User* user = new User(1, name, password, 1);
			user->login(name, password);
		}
};
