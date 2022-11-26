#include "vector.h"
#include <utility>

/*
������� ������ �� size ���������,
������ �� ������� �� ��������� value.
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
	
	if (m_capacity < obj.m_size) {
		double* tmp_ptr = new double[obj.m_size];
		delete[] m_ptr;
		m_ptr = tmp_ptr;
		m_capacity = obj.m_size;
	}

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
	if (m_size + 1 > m_capacity) {
		double* tmp_ptr = new double[2 * m_size];
		
		for (size_t i = 0; i < m_size; ++i) {
			tmp_ptr[i] = m_ptr[i];
		}
		
		delete[] m_ptr;
		m_ptr = tmp_ptr;
		m_capacity = 2 * m_size;
	}
	
	m_ptr[m_size] = el;
	++m_size;
}