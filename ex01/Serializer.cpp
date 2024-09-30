#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& cpy) 
{
	(void)cpy;
}

Serializer::~Serializer() {}

Serializer&	Serializer::operator=(const Serializer& cpy)
{
	(void)cpy;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	num = reinterpret_cast<uintptr_t>(ptr);
	return num;
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data*	data = reinterpret_cast<Data*>(raw);
	return data;
}
