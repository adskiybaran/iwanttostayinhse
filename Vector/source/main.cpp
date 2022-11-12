#include <iostream>
#include "vector.h"

int main() {
	
	MyVector vec1(5, 3.14);
	MyVector vec2 = vec1;
	std::cout << "Hello World!\n";
	vec2[3] = 10;
	for (size_t i = 0; i < 10; ++i) {
		std::cout << vec1[i] << ' ';
	}

	return 0;
}