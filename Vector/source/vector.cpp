#include "vector.h"
#include <utility>

/*
Создаем массив на size элементов,
каждый из которых со значением value.
*/
MyVector::MyVector(size_t size, double value) {
	m_ptr = new double[size];
	m_size = size;
	m_capacity = size;
	for (size_t i = 0; i < size; ++i) {
		m_ptr[i] = value;
	}
}

MyVector::MyVector(const MyVector& obj) {
	m_ptr = new double[obj.m_size];
	m_size = obj.m_size;
	m_capacity = obj.m_size;
	for (size_t i = 0; i < m_size; ++i)
		m_ptr[i] = obj[i]; 
}

MyVector& MyVector::operator=(const MyVector& obj) {
	if (&obj == this) {
		return *this;
	}
	reserve_utilities(obj.m_size, false);
	for (size_t i = 0; i < obj.m_size; ++i)
		m_ptr[i] = obj[i];

	m_size = obj.m_size;
	return *this;
}



void MyVector::swap(MyVector& obj) {
	std::swap(m_ptr, obj.m_ptr);
	std::swap(m_size, obj.m_size);
	std::swap(m_capacity, obj.m_capacity);
}

void MyVector::push_back(double el){
	if (m_size + 1 > m_capacity)
		reserve(2 * m_capacity);
	
	m_ptr[m_size] = el;
	++m_size;
}

void MyVector::resize(size_t size){
	reserve_utilities(size, true);
	for (size_t i = m_size; i < size; ++i) {
		m_ptr[i] = double();
	}
	m_size = size;
}

void MyVector::reserve_utilities(size_t capacity, bool flag){
	if (capacity <= m_capacity) {
		return;
	}
	double* tmp_ptr = new double[capacity];
	if (flag)
		for (size_t i = 0; i < m_size; ++i)
			tmp_ptr[i] = m_ptr[i];
	delete[] m_ptr;
	m_ptr = tmp_ptr;
	m_capacity = capacity;
}

void MyVector::shrek_2_fat() {
	if (m_capacity == m_size)
		return;
	double* tmp_ptr = new double[m_size];

	for (size_t i = 0; i < m_size; ++i) {
		tmp_ptr[i] = m_ptr[i];
	}
	delete[] m_ptr;
	m_ptr = tmp_ptr;
	m_capacity = m_size;
}

bool operator==(const MyVector& obj1, const MyVector& obj2){
	if (obj1.size() != obj2.size())
		return false;
	for (size_t i = 0; i < obj1.size(); ++i) {
		if (obj1[i] != obj2[i])
			return false;
	}
	return true;
}
