#include "User.h"
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
    return name;
}
char* User::getPassword() {
        return password;
}

int User::getRole() {
		return role;
}
void User::setName(char* name) {
        strcpy(this->name,name);
}
void User::write(const User& user) {
        fstream outFile(DBFile, std::ios::binary | std::ios::app);

    if (!outFile) {
        std::cerr << "File could not be opened." << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&user), sizeof(User));
    outFile.close();
}

void User::storeInDB() {
    User* newClient = this;
    write(*newClient);

    std::cout << "New record added to the file." << std::endl;
}

void User::read(){

	std::fstream arc;
	User* buf = this;
	arc.open(DBFile,ios::binary | ios::in);
    while (true)
    {
        arc.read((char *)buf,sizeof(*buf));
        if (arc.eof()) break;
        printf("%s %d", buf->getName(), buf->getId());
        printf("\n");
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

char* User::getByName(char* name) {
    std::ifstream in(DBFile, std::ios::binary);
    User* user=this;
	int userNameMatches = strcmp(user->getName(), name);
	while (in.read((char*)user, sizeof(User))) {
		if (userNameMatches == 0) {
			std::cout << "ID: " << user->getId() << ", Name: " << user->getName() << std::endl;
		}
	}
    in.close();
    return this->name;
}
