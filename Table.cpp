#include "Table.h"
#include <iostream>
Table::Table(int id){
	this->id = id;
}
int Table::getId(){
	return this->id;
}
void Table::setId(int id){
	this->id = id;
}
void Table::print(){
	std::cout << "Id: " << this->id << std::endl;
}
