#include "vector.h"
#include <utility>
#include <stdexcept>

/*
Создаем массив на size элементов,
каждый из которых со значением value.
*/
shrek::MyVector::MyVector(size_t size, double value) {
	m_ptr = new double[size];
	m_size = size;
	m_capacity = size;
	for (size_t i = 0; i < size; ++i) {
		m_ptr[i] = value;
	}
}

shrek::MyVector::MyVector(std::initializer_list<double> lst) {
	reserve_utilities(lst.size(), false);
	double* el_ptr = m_ptr;
	for (double el: lst){
		*el_ptr = el;
		++el_ptr;
	}
	m_size = lst.size();
}


shrek::MyVector::MyVector(const MyVector& obj) {
	m_ptr = new double[obj.m_size];
	m_size = obj.m_size;
	m_capacity = obj.m_size;
	for (size_t i = 0; i < m_size; ++i)
		m_ptr[i] = obj[i]; 
}

shrek::MyVector& shrek::MyVector::operator=(const MyVector& obj) {
	if (&obj == this) {
		return *this;
	}
	reserve_utilities(obj.m_size, false);
	for (size_t i = 0; i < obj.m_size; ++i)
		m_ptr[i] = obj[i];

	m_size = obj.m_size;
	return *this;
}


void shrek::MyVector::swap(MyVector& obj) {
	std::swap(m_ptr, obj.m_ptr);
	std::swap(m_size, obj.m_size);
	std::swap(m_capacity, obj.m_capacity);
}

void shrek::MyVector::push_back(double el){
	if (m_size + 1 > m_capacity)
		reserve(2 * m_capacity);
	
	m_ptr[m_size] = el;
	++m_size;
}

void shrek::MyVector::pop_back(){
	if (m_size == 0)
		throw std::runtime_error("Cannot pop_back empty vector");
	--m_size;
}

void shrek::MyVector::resize(size_t size){
	reserve_utilities(size, true);
	for (size_t i = m_size; i < size; ++i) {
		m_ptr[i] = double();
	}
	m_size = size;
}

void shrek::MyVector::reserve_utilities(size_t capacity, bool flag){
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

void shrek::MyVector::shrek_2_fat() {
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

bool shrek::operator==(const MyVector& obj1, const MyVector& obj2){
	if (obj1.size() != obj2.size())
		return false;
	for (size_t i = 0; i < obj1.size(); ++i) {
		if (obj1[i] != obj2[i])
			return false;
	}
	return true;
}
