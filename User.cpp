#include "User.h"
#include "DBConnection.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>


using namespace std;
string DBFile="db/users.dat";
User::User(int id, char* name, char* password, int role): Table(id) {
    strcpy(this->name,name);
    strcpy(this->password,password);
	this->role = role;

}


char* User::getName() {
    return this->name;
}
char* User::getPassword() {
        return this->password;
}

int User::getRole() {
		return role;
}
void User::setName(char* name) {
        strcpy(this->name,name);
}
void User::write(int id, char* name, char* password, int role) {
    fstream outFile(DBFile, ios::binary | ios::app);

    if (!outFile) {
        std::cerr << "File could not be opened." << std::endl;
        return;
    }

	User users[]={{id, name, password, role}};
    outFile.write((char*)users, sizeof(User));
    outFile.close();
}

void User::storeInDB(int id, char* name, char* password, int role) { write(id, name, password, role);

    std::cout << "New record added to the file." << std::endl;
}

void User::read(){

	fstream arc;
	User buf;
	arc.open(DBFile,ios::binary | ios::in);
    while (true)
    {
        arc.read((char *)&buf,sizeof(buf));
        if (arc.eof()) break;
        printf("%s %d \n", buf.getName(), buf.getId());
    }
    arc.close();
}

char* User::getById(int id) {
	std::ifstream in(DBFile, std::ios::binary);
	User* user=this;
    while (in.read((char*)user, sizeof(User))) {
        if (user->getId() == id) {
            std::cout << "ID: " << user->getId() << ", Name: " << user->getName() << std::endl;
        }
    }
    in.close();
    return this->name;
}


bool User::login(char* inputName, char* inputPassword){
		DBConnection<User> connection;
		User user = connection.getUserByName(inputName);
		int usersMatch = strcmp(user.getName(), inputName);
		if(usersMatch==0){
			int passwordsMatch = strcmp(user.getPassword(), inputPassword);
			if(passwordsMatch==0){
				return true;
			}
		}

		printf("******************************************************************* \n");
		printf("* Usuario no encontrado o contrasena incorrecta, intente de nuevo *\n");
		printf("******************************************************************* \n");
		return false;

}
string User::print(){
	// printf("%s %d \n", this->getName(), this->getId());
	string data = to_string(this->getId()) + " " + this->getName() + " " + this->getPassword()+" " + to_string(this->getRole());
	// printf("\n nombre: %s \n", this->getName());
	printf("%s \n", data.c_str());
	return data;
}
