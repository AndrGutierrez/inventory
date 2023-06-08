#include "Client.h"

Client::Client() : id(0), name("") {}

Client::Client(int id, const std::string& name) : id(id), name(name) {}

int Client::getId() const {
    return id;
}

void Client::setId(int id) {
    this->id = id;
}

std::string Client::getName() const {
    return name;
}

void Client::setName(const std::string& name) {
    this->name = name;
}

