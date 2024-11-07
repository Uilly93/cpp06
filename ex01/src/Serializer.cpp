#include "../includes/Serializer.hpp"
#include "../includes/colors.hpp"
#include <cmath>
#include <stdint.h>

// Constructors
Serializer::Serializer() {
	std::cout << GREEN << "Serializer Default Constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &src) {
	std::cout << BLUE << "Serializer Copy Constructor called" << RESET << std::endl;
	*this = src;
}
// Destructor
Serializer::~Serializer() {
	std::cout << RED << "Serializer Destructor called " << RESET << std::endl;
}

// Operator Overload
Serializer &Serializer::operator=(const Serializer &src) {
	std::cout << PURPLE << "Serializer Copy Assignment Operator called" << RESET << std::endl;
	if (this != &src) {
	}
	return *this;
}
// Methods

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
