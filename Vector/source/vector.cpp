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

MyVector::MyVector(const MyVector& obj) {
	m_ptr = new double[obj.m_size];
	m_size = obj.m_size;
	for (size_t i = 0; i < m_size; ++i)
		m_ptr[i] = obj[i]; 
}

void MyVector::operator=(const MyVector& obj) {
	double* tmp_ptr = new double[obj.m_size];
	for (size_t i = 0; i < obj.m_size; ++i)
		tmp_ptr[i] = obj[i];

	delete[] m_ptr;
	m_ptr = tmp_ptr;
 	m_size = obj.m_size;
}