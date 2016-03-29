#include "vector4.h"

Vector4::~Vector4(void)
{
}

Vector4 operator + (const Vector4& A ,const Vector4& B) {
	return Vector4(A.v[0] + B.v[0], A.v[1] + B.v[1], A.v[2] + B.v[2], A.v[3] + B.v[3]);
}
