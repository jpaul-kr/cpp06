#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy) 
{
	(void)
	return *this;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& cpy)
{
	(void)cpy;
	return *this;
}

void	ScalarConverter::converter(string str)
{
	char	c = static_cast<char>(str);
}
