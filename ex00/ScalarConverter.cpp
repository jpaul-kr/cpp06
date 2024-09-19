#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy) 
{
	(void)cpy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& cpy)
{
	(void)cpy;
	return *this;
}

int	ScalarConverter::get_type(string str)
{
	int	type = CHAR;

	for (int i = 0;i < str.length();i++)
	{
		if (type <= INT && str[i] >= '0' && str[i] <= '9')
			type = INT;
		if (type <= DOUBLE && str[i] == '.')
			type = DOUBLE;
		if (str[i] == 'f')
			type = FLOAT;
	}
	return type;
}

void	ScalarConverter::convert(string str)
{
	int	type = get_type(str);

	switch (type)
	{
		case CHAR:

	}
	char	c = static_cast<char>(str);
	int	n = static_cast<int>(str);
	float	f = static_cast<float>(str);
	double	d = static_cast<double>(str);

	std::cout << "char: " << c <<  std::endl;
	std::cout << "int: " << n <<  std::endl;
	std::cout << "float: " << f <<  std::endl;
	std::cout << "double: " << d <<  std::endl;
}
