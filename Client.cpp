#include "Client.h"
#include <cstring>


Client::Client(int id, char* nombre): Table(id) {
	strcpy(this->nombre,nombre);

}


char* Client::getNombre() {
    return nombre;
}

void Client::setNombre(char* nombre) {
	strcpy(this->nombre,nombre);
}
