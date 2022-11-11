#include <iostream>
#include "vector.h"

int main() {
	MyVector vec1, vec2(5, 3.14);
	std::cout << "Hello World!\n";
	
	for (size_t i = 0; i < 10; ++i) {
		std::cout << vec2[i] << ' ';
	}

	return 0;
}