#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# define CHAR	0
# define INT	1
# define DOUBLE	2
# define FLOAT	3
# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <climits>

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
		static int	get_type(string str);
		static int	convert_int(string str);
		static float	convert_float(string str);
		static double	convert_double(string str);
		static void	Printc(double x, string str);
		static void	Printi(double x, string str);
		static void	Printd(double x, string str);
		static void	Printf(double x, string str);
};

#endif
