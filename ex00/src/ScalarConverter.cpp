#include "../includes/ScalarConverter.hpp"
#include "../includes/colors.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <limits>

// Constructors
ScalarConverter::ScalarConverter() {
	std::cout << GREEN << "ScalarConverter Default Constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	std::cout << BLUE << "ScalarConverter Copy Constructor called" << RESET << std::endl;
	*this = src;
}
// Destructor
ScalarConverter::~ScalarConverter() {
	std::cout << RED << "ScalarConverter Destructor called " << RESET << std::endl;
}

// Operator Overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	std::cout << PURPLE << "ScalarConverter Copy Assignment Operator called" << RESET << std::endl;
	if (this != &src) {
	}
	return *this;
}
// Methods

// static bool only_digit_string(std::string arg) {
// 	for (int i = 0; arg[i]; i++) {
// 		if (!std::isdigit(arg[i]))
// 			return false;
// 	}
// 	return true;
// }

static bool only_one_char(std::string arg) {
	if (arg[0] >= 32 && arg[0] <= 126 && !arg[1])
		return true;
	return false;
}

static bool all_digit_string(std::string arg) {
	for (int i = 0; arg[i]; i++) {
		if (!std::isdigit(arg[i]))
			return false;
	}
	return true;
}

// static void printChar(std::string n)
// {
//     int k = 0;
//     long double nb = strtold(n.c_str(), NULL);
//     while (n[k] == '0')
//         k++;
//     char c = n[k];
//     if (nb < std::numeric_limits<char>::min() || nb > std::numeric_limits<char>::max() || std::isnan(nb))
//         std ::cout << "char : impossible\n";
//     else if ((all_digit_string(n) && (nb < 32 || nb > 126)) || n[0] == '-')
//         std ::cout << "char : character non displayable\n";
//     else if (only_one_char(n))
//         std::cout << "char : " << static_cast<char>(c) << std::endl;
//     else
//         std::cout << "char : " << static_cast<char>(nb) << std::endl;
// }

static void printchar(std::string arg) {
	long double d = strtold(arg.c_str(), NULL);

	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() ||
		std::isnan(d))
		std::cout << ORANGE << "char = Impossible" << RESET << std::endl;
	else if ((all_digit_string(arg) && (!std::isprint(d))) || arg[0] == '-')
		std::cout << ORANGE << "char = non displayable" << RESET << std::endl;
	else if (only_one_char(arg))
		std::cout << ORANGE << "char = " << static_cast<char>(arg[0]) << RESET << std::endl;
	else
		std::cout << ORANGE << "char = " << static_cast<char>(d) << RESET << std::endl;
}

// static void printdouble(std::string arg) {
// }

// static void printfloat(std::string arg) {
// }

// static void printint(std::string arg) {
// }

void ScalarConverter::convert(std::string arg) {
	double d = std::atof(arg.c_str());
	int i;
	float f;

	i = static_cast<int>(d);
	f = static_cast<float>(d);
	printchar(arg);
	if (std::isnan(d)) {
		std::cout << BLUE << "int = impossible" << RESET << std::endl;
		std::cout << PURPLE << "float = nanf" << RESET << std::endl;
		std::cout << BLUE << "double = nan" << RESET << std::endl;
	} else if (!std::isprint(d)) {
		std::cout << BLUE << "int = " << i << RESET << std::endl;
		std::cout << PURPLE << "float = " << std::fixed << f << "f" << RESET << std::endl;
		std::cout << BLUE << "double = " << d << RESET << std::endl;
	} else {
		std::cout << BLUE << "int = " << i << RESET << std::endl;
		std::cout << PURPLE << "float = " << std::fixed << f << "f" << RESET << std::endl;
		std::cout << BLUE << "double = " << d << RESET << std::endl;
	}
}
