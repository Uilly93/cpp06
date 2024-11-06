#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "colors.hpp"
#include <iostream>

class ScalarConverter {
	public:
	// Methods
	static void convert(std::string arg);

	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
	~ScalarConverter();
};

#endif