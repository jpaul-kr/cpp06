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
		static int	get_type(string str);
		static int	convert_int(string str);
		static float	convert_float(string str);
		static double	convert_double(string str);
		static void	Printc(char x, int type);
		static void	Printi(int x, int type);
		static void	Printd(double x, int type);
		static void	Printf(float x, int type);
};

#endif
