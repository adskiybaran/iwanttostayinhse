#pragma once
#include <initializer_list>

namespace shrek {
	class MyVector {
	public:
		MyVector() = default;
		MyVector(size_t size, double value = 0);
		MyVector(std::initializer_list<double> lst);
		MyVector(const MyVector& obj);
		MyVector(MyVector&& obj) { swap(obj); }
		~MyVector() { delete[] m_ptr; }

		MyVector& operator=(const MyVector& obj);
		MyVector& operator=(MyVector&& obj) { swap(obj); return *this; }
		double& operator[](size_t i) { return m_ptr[i]; }
		double operator[](size_t i) const { return m_ptr[i]; }
		size_t size() const { return m_size; }
		size_t capacity() const { return m_capacity; }
		void reserve(size_t capacity) { reserve_utilities(capacity, true); }
		void shrek_2_fat();
		void swap(MyVector& obj);
		void push_back(double el);
		void pop_back();
		bool empty() const { return m_size == 0; }
		void clear() { m_size = 0; }
		void resize(size_t size);

	private:
		void reserve_utilities(size_t capacity, bool flag);
	private:
		double* m_ptr = nullptr;
		size_t m_capacity = 0;
		size_t m_size = 0;
	};

	inline void swap(MyVector& obj1, MyVector& obj2) { obj1.swap(obj2); }
	bool operator==(const MyVector& obj1, const MyVector& obj2);
	inline bool operator!=(const MyVector& obj1, const MyVector& obj2) {
		return !(obj1 == obj2);
	}

}