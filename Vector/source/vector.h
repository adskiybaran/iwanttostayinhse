#pragma once

class MyVector {
public:
	MyVector() = default;
	MyVector(size_t size, double value);
	MyVector(const MyVector& obj);
	~MyVector() { delete[] m_ptr; }

	MyVector& operator=(const MyVector& obj);
	double& operator[](size_t i) { return m_ptr[i]; }
	double operator[](size_t i) const { return m_ptr[i]; }
	size_t size() const { return m_size; }
	void swap(MyVector& obj);

private:
	double* m_ptr = nullptr;
	size_t m_size = 0;
};

inline void swap(MyVector& obj1, MyVector& obj2){ obj1.swap(obj2);}