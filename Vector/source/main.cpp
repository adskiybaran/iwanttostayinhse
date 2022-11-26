#include "tests.h"
#include <iostream>
int main() {
	/*
	test_swap();
	test_push_back();
	test_move();
	test_empty_clear();
	test_capacity();
	test_reserve();
	*/
	try {
		test_shrek_2_fat();
	}
	catch(std::exception& ex){
		std::cout << ex.what();
	}
	return 0;
}