#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy) 
{
	(void)cpy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& cpy)
{
	(void)cpy;
	return *this;
}

int	ScalarConverter::convert_int(string str)
{
	int	ret = atoi(str.c_str());
	return ret;
}

float	ScalarConverter::convert_float(string str)
{
	float	ret = atoi(str.c_str());
	return ret;
}

double	ScalarConverter::convert_double(string str)
{
	double	ret = atof(str.c_str());
	return ret;
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
	double	x = 0;

	switch (type)
	{
		case CHAR:
			x = static_cast<double>(str[0]);
		case INT:
			x = static_cast<double>(convert_int(str));
		case DOUBLE:
			x = static_cast<double>(convert_double(str));
		case FLOAT:
			x = static_cast<double>(convert_float(str));
		default:
			return ;

	}
	char	c = static_cast<char>(x);
	int	n = static_cast<int>(x);
	float	f = static_cast<float>(x);
	double	d = static_cast<double>(x);

	std::cout << "char: " << c <<  std::endl;
	std::cout << "int: " << n <<  std::endl;
	std::cout << "float: " << f <<  std::endl;
	std::cout << "double: " << d <<  std::endl;
}
