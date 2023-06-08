#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
	private:
		int id;
		std::string name;

	public:
		Client();
		Client(int id, const std::string& name);

		int getId() const;
		void setId(int id);

		std::string getName() const;
		void setName(const std::string& name);
};

#endif

