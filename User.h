#ifndef USER_H
#define USER_H
#include "Table.h"
using namespace std;
#include <vector>
class User:public Table{
	
	private:
		int id;
		char name[32];
		char password[128];
		int role;
	public:
		User(){};
		User(int id, char* name, char* password, int role);
		char* getName();
		char* getPassword();
		int getRole();
		void write(int id, char* name, char* password, int role);
		void read();
		void storeInDB(int id, char* name, char* password, int role);
		void setName(char* name);
		void setPassword(char* password);
		void setRole(int role);
		char* getById(int id);
		User* getByName(char* name);
		bool login(char* inputName, char* inputPassword);
		string print();
};
#endif
