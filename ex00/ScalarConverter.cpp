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
	//std::cout << ret << std::endl;
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
		if (type <= DOUBLE && (str[i] == '.' || str > "-2147483648"))
			type = DOUBLE;
		if (str[i] == 'f' && type == DOUBLE)
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
	Printc(x, str);
	Printi(x, str);
	Printf(x, str);
	Printd(x, str);
}

void	ScalarConverter::Printc(double x, string str) 
{
	char	c;
	std::cout << "char: ";
	c = static_cast<char>(x);
	if (str == "nan" || str == "nanf" || x > SCHAR_MAX || x < SCHAR_MIN)
		std::cout << "impossible" << std::endl;
	else if (!isprint(x))
		std::cout << "Not displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void	ScalarConverter::Printi(double x, string str)
{
	//std::cout << x << std::endl;
	std::cout << "int: ";
	if (str == "nan" || str == "nanf" || x > (double)INT_MAX || x < (double)INT_MIN)
		std::cout << "impossible" << std::endl;
	else
	{
		int	n = static_cast<int>(x);
		std::cout << n << std::endl;
	}
}

void	ScalarConverter::Printd(double x, string str) 
{
	float	d;
	std::cout << "double: ";
	d = static_cast<double>(x);
	if (str == "nan" || str == "nanf")
		std::cout << "nan" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << std::showpoint << d << std::endl;
}

void	ScalarConverter::Printf(double x, string str) 
{
	double	f;
	std::cout << "float: ";
	f = static_cast<float>(x);
	if (str == "nan" || str == "nanf")
		std::cout << "nanf" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << std::showpoint << f << "f" << std::endl;
}
