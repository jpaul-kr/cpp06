#include "Serializer.hpp"

int	main()
{
	Data		aux;
	Data*		data;
	//Serializer	s;
	uintptr_t	num;

	aux.content = "hello";
	aux.f = 3.14f;
	data = &aux;
	num = Serializer::serialize(data);
	std::cout << "num: " << num << std::endl;
	data = Serializer::deserialize(num);
	std::cout << "data | str: " << data->content << " | float: " << data->f << std::endl;
}
