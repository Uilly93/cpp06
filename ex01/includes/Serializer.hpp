#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data{
	std::string data;
};

class Serializer {
	public:
	// Methods
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	private:
	Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);
	~Serializer();
};

#endif