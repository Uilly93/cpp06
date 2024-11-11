#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/Base.hpp"
#include "../includes/C.hpp"
#include "../includes/colors.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

Base *generate(void) {
	int nb = std::rand();

	if (nb % 3 == 0) {
		return new A();
	} else if (nb % 2 == 0) {
		return new B();
	} else {
		return new C();
	}
}

void identify(Base *p) {
	if (A *aptr = dynamic_cast<A *>(p)) {
		std::cout << NGREEN << "A" << RESET << std::endl;
	} else if (B *bptr = dynamic_cast<B *>(p)) {
		std::cout << NGREEN << "B" << RESET << std::endl;
	} else if (C *cptr = dynamic_cast<C *>(p)) {
		std::cout << NGREEN << "C" << RESET << std::endl;
	}
	return;
}

void identify(Base &p) {
	try {
		A &aptr = dynamic_cast<A &>(p);
		(void)aptr;
		std::cout << NGREEN << "A" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << NRED << e.what() << RESET << std::endl;
	}
	try {
		B &aptr = dynamic_cast<B &>(p);
		(void)aptr;
		std::cout << NGREEN << "B" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << NRED << e.what() << RESET << std::endl;
	}
	try {
		C &aptr = dynamic_cast<C &>(p);
		(void)aptr;
		std::cout << NGREEN << "C" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << NRED << e.what() << RESET << std::endl;
	}
}

int main(void) {
	std::srand(time(0));
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	std::cout << NGREEN << "trying identify pointer function" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	for (int i = 0; i < 10; i++) {
		Base *ptr = generate();
		identify(ptr);
		delete ptr;
	}
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	std::cout << NGREEN << "trying identify reference function" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	for (int i = 0; i < 10; i++) {
		Base *ptr = generate();
		identify(*ptr);
		delete ptr;
	}
	return 0;
}
