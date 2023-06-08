#include "Table.h"
Table::Table(int id){
	this->id = id;
}
int Table::getId(){
	return this->id;
}
void Table::setId(int id){
	this->id = id;
}
