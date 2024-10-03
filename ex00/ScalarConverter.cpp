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

bool	ScalarConverter::isinf(string str)
{
	if (str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return true;
	return false;
}

bool	ScalarConverter::isnan(string str)
{
	if (str == "nan" || str == "nanf")
		return true;
	return false;
}

bool	ScalarConverter::isoor(double x, int flag)
{
	switch (flag)
	{
		case CHAR:
			if (x > SCHAR_MAX || x < SCHAR_MIN)
				return true;
			break ;
		case INT:
			if (x > INT_MAX || x < INT_MIN)
				return true;
			break ;
		case FLOAT:
			if (x > FLT_MAX || x < -(FLT_MAX + 1))
				return true;
			break;
		default:
			return false;
	}
	return false;
}

int	ScalarConverter::convert_int(string str)
{
	int	ret = atoi(str.c_str());
	return ret;
}

float	ScalarConverter::convert_float(string str)
{
	str[str.length() - 1] = '\0';
	float	ret = strtof(str.c_str(), NULL);
	return ret;
}

double	ScalarConverter::convert_double(string str)
{
	double	ret = atof(str.c_str());
	return ret;
}

int	ScalarConverter::get_type(string str)
{
	int	type;
	int	flag = str.find("f");
	int	pointf = str.find(".");

	if (!isdigit(str[0]) && !str[1])
		return CHAR;
	else
		type = INT;
	if (flag > 0)
		str[flag] = '\0';
	for (size_t i = 0; str[i]; i++)
	{
		if (!i && str[i] == '-')
			i++;
		if (type < INT && str[i] >= '0' && str[i] <= '9')
			type = INT;
		if (type < DOUBLE && (str[i] == '.' || isoor(atof(str.c_str()), INT)))
			type = DOUBLE;
		if (flag > 0 && type == DOUBLE && str.find(".") + 1 < 8 && !isoor(atof(str.c_str()), FLOAT))
			type = FLOAT;
		if (((size_t)flag != str.length() - 1 && flag > 0) || (!isdigit(str[i]) && (str[i] != '.' || !isdigit(str[i + 1]) || !isdigit(str[i - 1]) || i == 0 || (int)i != pointf)))
			return ERR;
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
		case ERR:
			x = 0;
			break ;
		default:
			return ;

	}
	Printc(x, str, type);
	Printi(x, str, type);
	Printf(x, str, type);
	Printd(x, str, type);
}

void	ScalarConverter::Printc(double x, string str, int type) 
{
	char	c;
	std::cout << "char: ";
	c = static_cast<char>(x);
	if (isinf(str) || isnan(str) || isoor(x, CHAR) || type == ERR)
		std::cout << "impossible" << std::endl;
	else if (!isprint(x))
		std::cout << "Not displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void	ScalarConverter::Printi(double x, string str, int type)
{
	std::cout << "int: ";
	if (isnan(str) || isoor(x, INT) || isinf(str) || type == ERR)
		std::cout << "impossible" << std::endl;
	else
	{
		int	n = static_cast<int>(x);
		std::cout << n << std::endl;
	}
}

void	ScalarConverter::Printd(double x, string str, int type) 
{
	double	d;
	std::cout << "double: ";
	d = static_cast<double>(x);
	if (isnan(str))
		std::cout << "nan" << std::endl;
	else if (isinf(str))
		std::cout << str[0] << "inf" << std::endl;
	else if (type == ERR)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << std::showpoint << d << std::endl;
}

void	ScalarConverter::Printf(double x, string str, int type) 
{
	float	f;
	std::cout << "float: ";
	f = static_cast<float>(x);
	if (isinf(str))
		std::cout << str[0] << "inff" << std::endl;
	else if (isnan(str))
		std::cout << "nanf" << std::endl;
	else if (isoor(x, FLOAT) || type == ERR)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << std::showpoint << f << "f" << std::endl;
}
