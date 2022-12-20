#include "matrix.h"
#include <stdexcept>


iwanttostayinhse::Matrix::Matrix(size_t rows, size_t columns){
	m_rows = rows;
	m_cols = columns;
	m_ptr = new double[m_rows * m_cols];
}

size_t iwanttostayinhse::Matrix::rows() const{
	return m_rows;
}

size_t iwanttostayinhse::Matrix::columns() const{
	return m_cols;
}

bool iwanttostayinhse::Matrix::empty(){
	return (m_cols == 0 || m_rows == 0);
}

iwanttostayinhse::Matrix::Matrix(const Matrix& m){
	m_rows = m.rows();
	m_cols = m.columns();
	m_ptr = new double[m_rows * m_cols];
	for (size_t i = 0; i < m_rows * m_cols; i++)
	{
		m_ptr[i] = m.m_ptr[i];
	}
}

iwanttostayinhse::Matrix& iwanttostayinhse::Matrix::operator=(const Matrix& m) {
	Matrix temp(m);
	std::swap(m_cols, temp.m_cols);
	std::swap(m_rows, temp.m_rows);
	std::swap(m_ptr, temp.m_ptr);

	return *this;
}

iwanttostayinhse::Matrix iwanttostayinhse::Matrix::reshape(size_t new_rows, size_t new_cols) {
	if (m_cols * m_rows != new_cols * new_rows) throw std::runtime_error("Cannot save the number of elements");
	m_rows = new_rows;
	m_cols = new_cols;
	return *this;
}

