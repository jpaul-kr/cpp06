#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# define CHAR	0
# define INT	1
# define DOUBLE	2
# define FLOAT	3
# include <iostream>
# include <cstdlib>

using std::string;

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpy);
		~ScalarConverter();

		ScalarConverter&	operator=(const ScalarConverter& cpy);
		static void		convert(string str);

	private:
		int	get_type(string str);
		int	convert_int(string str);
		float	convert_float(string str);
		double	convert_double(string str);
};

#endif
