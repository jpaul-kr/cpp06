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
	float	ret = static_cast<float>(atof(str.c_str()));
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

	for (size_t i = 0;i < str.length();i++)
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
	int	type = ScalarConverter::get_type(str);
	double	x = 0;

	switch (type)
	{
		case CHAR:
			x = static_cast<double>(str[0]);
			break ;
		case INT:
			x = static_cast<double>(convert_int(str));
			break ;
		case DOUBLE:
			x = static_cast<double>(convert_double(str));
			break ;
		case FLOAT:
			x = static_cast<double>(convert_float(str));
			break ;
		default:
			return ;

	}
	char	c = static_cast<char>(x);
	int	n = static_cast<int>(x);
	float	f = static_cast<float>(x);
	double	d = static_cast<double>(x);

	std::cout << "float: " << f <<  std::endl;
	std::cout << "double: " << d <<  std::endl;
}

void	ScalarConverter::Printc(char x, int type) 
{
	std::cout << "char: ";
	if (isprint(x))
		std::cout << "Not displayable" << std::endl;
	if (x == -1)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << x << "'" << std::endl;
}

void	ScalarConverter::Printi(int x, int type) 
{
	std::cout << "int: " << n <<  std::endl; //haciendo los printd de cada uno
}

void	ScalarConverter::Printf(double x, int type) {}

void	ScalarConverter::Printd(float x, int type) {}
