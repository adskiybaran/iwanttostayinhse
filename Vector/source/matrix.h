#pragma once

namespace iwanttostayinhse {
	class Matrix {
	public:
		Matrix() = default;
		Matrix(size_t rows, size_t columns);
		Matrix(const Matrix& m);
		~Matrix() { delete[] m_ptr; }

		size_t rows() const;
		size_t columns() const;
		bool empty();
		Matrix reshape(size_t new_rows, size_t new_cols);
		Matrix& operator=(const Matrix& m);

	private:
		double* m_ptr = nullptr;
		size_t m_rows;
		size_t m_cols;
	};

}