#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <string>
# include <stdint.h>

using std::string;

typedef struct s_Data
{
	string	content;
	float	f;
}Data;

class Serializer
{
	public:
		~Serializer();
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	
	private:
		Serializer();
		Serializer(const Serializer& cpy);
		Serializer&	operator=(const Serializer& cpy);
};

#endif
