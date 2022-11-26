#include "vector_utilities.h"


std::ostream& operator<<(std::ostream& out, const shrek::MyVector& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		out << vec[i] << ' ';
	}
	return out;
}