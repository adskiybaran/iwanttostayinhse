#include "vector.h"

/*
Создаем массив на size элементов,
каждый из которых со значением value.
*/
MyVector::MyVector(size_t size, double value) {
	m_ptr = new double[size];
	m_size = size;

	for (size_t i = 0; i < size; ++i) {
		m_ptr[i] = value;
	}
}

