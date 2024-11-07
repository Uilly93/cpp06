#include "../includes/Serializer.hpp"
#include "../includes/colors.hpp"
#include <iostream>
#include <stdint.h>


int main(void) {
	Data ptr;
	ptr.data = "Hello";
	
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << NGREEN << "first PTR adress" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << PURPLE << &ptr << RESET << std::endl;

	uintptr_t adress = Serializer::serialize(&ptr);
	Data *newptr = Serializer::deserialize(adress);

	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << NGREEN << "Serialized and deserialized PTR adress" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

	std::cout << PURPLE << newptr << RESET << std::endl;

	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << NGREEN << "Printing new PTR deserialised adress" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

	std::cout << newptr->data << std::endl;

	return 0;
}
