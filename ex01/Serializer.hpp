#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <string>

typedef struct s_Data
{
	string	content;
}Data;

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer& cpy);
		~Serializer();
		Serializer&	operator=(const Serializer& cpy);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
