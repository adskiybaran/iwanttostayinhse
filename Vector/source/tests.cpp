#include "tests.h"
#include "vector.h"

#include <iostream>


void print(const MyVector& myvec) {
	for (size_t i = 0; i < myvec.size(); ++i) {
		std::cout << myvec[i] << ' ';
	}
	std::cout << '\n';
}

void test1() {
	const MyVector vec1(10, 3.14);
	MyVector vec2;
	vec2 = vec1;
	vec2[3] = 10;
	print(vec1);
	print(vec2);
}