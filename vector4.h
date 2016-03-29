#ifndef VECTOR4_H
#define VECTOR4_H
#include <iostream>
using namespace std;
class Vector4
{
public:
	double v[5];
	Vector4(double X = 0, double Y = 0, double Z = 0, double W = -99){
		v[0] = X; v[1] = Y; v[2] = Z; v[3] = W;
	}
	~Vector4(void);
	friend Vector4 operator + (const Vector4&, const Vector4&);
};
#endif

