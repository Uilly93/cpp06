#include "../includes/Base.hpp"
#include "../includes/colors.hpp"
#include <iostream>

// Destructor
Base::~Base() {
	std::cout << RED << "Base Destructor called " << RESET << std::endl;
}
