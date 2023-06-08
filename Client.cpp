#include "Client.h"
#include <cstring>
#include <fstream>
#include <iostream>


Client::Client(int id, char* nombre, char* direccion, char* telefono): Table(id) {
	strcpy(this->nombre,nombre);
	strcpy(this->direccion,direccion);
	strcpy(this->telefono,telefono);

}


char* Client::getNombre() {
    return nombre;
}
char* Client::getDireccion() {
	return direccion;
}
char* Client::getTelefono() {
	return telefono;
}

void Client::setNombre(char* nombre) {
	strcpy(this->nombre,nombre);
}
void Client::write(const std::string& filename, const Client& person) {
	fstream outFile(filename, std::ios::binary | std::ios::app);

    if (!outFile) {
        std::cerr << "File could not be opened." << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&person), sizeof(Client));
    outFile.close();
}

void Client::storeInDB() {
	Client* newClient = this;
    std::string filename = "db/people.dat";
    write(filename, *newClient);

    std::cout << "New record added to the file." << std::endl;
}

void Client::read(){

	std::fstream arc;
	Client* buf = this;
	arc.open("db/people.dat",ios::binary | ios::in);
    while (true)
    {
        arc.read((char *)buf,sizeof(*buf));
        if (arc.eof()) break;
        printf("%s %d", buf->getNombre(), buf->getId());
        printf("\n");
    }
    arc.close();
}

char* Client::getById(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    Client* client=this;
    while (in.read((char*)client, sizeof(Client))) {
        if (client->getId() == 2) {
            std::cout << "ID: " << client->getId() << ", Name: " << client->getNombre() << std::endl;
        }
    }
    in.close();
	return this->nombre;
}
