#ifndef TABLE_H
#define TABLE_H
#include <string>
class Table{
	private:
		int id;
	public:
		Table(){};
		Table(int id);
		int getId();
		void setId(int id);
		void print();
		void write(const std::string& filename, const Table& table);
};
#endif
