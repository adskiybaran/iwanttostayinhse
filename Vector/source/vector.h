#pragma once

class MyVector {
public:
	MyVector() = default;
	MyVector(size_t size, double value);
	MyVector(const MyVector& obj);
	double& operator[](size_t i) { return m_ptr[i]; }
	double operator[](size_t i) const { return m_ptr[i]; }
	~MyVector() { delete[] m_ptr; }
private:
	double* m_ptr = nullptr;
	size_t m_size = 0;
};