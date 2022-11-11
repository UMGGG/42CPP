#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		std::string getType();
		~Weapon();
};
