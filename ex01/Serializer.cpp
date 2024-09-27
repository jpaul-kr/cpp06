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
}

Data*		Serializer::deserialize(uintptr_t raw)
{
}
