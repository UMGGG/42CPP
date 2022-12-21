#include "Serializer.hpp"

int main()
{
	Data dat1;
	Data dat2;
	dat1.name = "jeon";
	dat1.num = 0;
	std::cout << "----------------------Origin----------------------" << std::endl;
	std::cout << "dat1 (" << &dat1 << ")\n" << dat1.name << ", " << dat1.num << std::endl;
	std::cout << "----------------------Serialized----------------------" << std::endl;
	Data *reserialized_data = deserialize(serialize(&dat1));
	std::cout << "dat1 (" << &dat1 << ")\n" << dat1.name << ", " << dat1.num << std::endl;
	std::cout << "reserialized_data (" << reserialized_data << ")\n" << reserialized_data->name << ", " << reserialized_data->num << std::endl;
	return (0);
}
