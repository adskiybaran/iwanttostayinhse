#include <iostream>
#include "vector.h"

void print(const MyVector& myvec) {
	for (size_t i = 0; i < myvec.size(); ++i) {
		std::cout << myvec[i] << ' ';
	}
	std::cout << '\n';
}

int main() {
	const MyVector vec1(10, 3.14);
	MyVector vec2;
	vec2 = vec1;
	vec2[3] = 10;
	print(vec1);
	print(vec2);	
	return 0;
}