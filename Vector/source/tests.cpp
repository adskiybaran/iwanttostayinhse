#include "tests.h"
#include "vector.h"

#include <iostream>


void print(const MyVector& myvec) {
	if (myvec.size() == 0) {
		std::cout << "Empty!\n";
		return;
	}
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

void test_move(){
	MyVector vec1(5, 2.3);
	print(vec1);
	vec1 = { 3, 4 };
	print(vec1);

	MyVector vec2 = static_cast<MyVector&&>(vec1);
	print(vec1);
	print(vec2);
}

void test_empty_clear() {
	MyVector vec1(5, 2.3);
	std::cout << std::boolalpha;
	std::cout << vec1.empty() << '\n';
	print(vec1);
	vec1.clear();
	std::cout << vec1.empty() << '\n';
	print(vec1);	
}

void test_capacity() {
	MyVector vec1(5, 2.3);
	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';
	
	vec1.push_back(228.337);
	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';
	
	vec1.push_back(215.47);
	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';

	vec1.clear();
	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';

	vec1 = MyVector(5, 2.28);
	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';

	MyVector vec2{3, 1.}, vec3{6, 2.};
	//
	vec1 = vec2;
	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';
	//
	vec1 = vec3;
	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';

}

void test_reserve(){
	MyVector vec1;
	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';

	vec1.reserve(2);
	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';

	vec1.push_back(1);
	vec1.push_back(2);

	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';

}

void test_shrek_2_fat(){
	MyVector vec1(5, 1);
	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';

	vec1.push_back(2);
	vec1.shrek_2_fat();
	std::cout << vec1.size() << ' ' << vec1.capacity() << '\n';
	print(vec1);
	std::cout << '\n';
}
