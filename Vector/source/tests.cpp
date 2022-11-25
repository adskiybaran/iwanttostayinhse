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

void test_swap() {
	MyVector vec1(10, 3.14);
	MyVector vec2;
	print(vec1);
	print(vec2);
	vec1.swap(vec2);
	print(vec1);
	print(vec2);
	swap(vec1, vec2);
	print(vec1);
	print(vec2);
}

void test_push_back() {
	MyVector vec1(5, 1);
	print(vec1);
	vec1.push_back(2);
	print(vec1);
}