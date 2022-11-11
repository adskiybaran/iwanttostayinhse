#pragma once

class MyVector {
public:
	MyVector() = default;
	MyVector(size_t size, double value);
private:
	double* m_ptr = nullptr;
	size_t m_size = 0;
};