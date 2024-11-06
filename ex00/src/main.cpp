#include "../includes/colors.hpp"
#include "../includes/ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
	if(ac != 2)
		return 1;
	std::string nb = av[1];
	ScalarConverter::convert(nb);
	return 0;
}
