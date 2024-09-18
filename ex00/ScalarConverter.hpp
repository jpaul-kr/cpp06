#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <ostream>

using std::string;

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpy);
		~ScalarConverter();

		ScalarConverter&	operator=(const ScalarConverter& cpy);
		static void		convert(string str);
};

#endif
