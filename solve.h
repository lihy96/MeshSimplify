#ifndef SOLVE_H
#define SOLVE_H
#include "vector4.h"
#include "matrix.h"
#include <cmath>
#include <iostream>
#include "config.h"
using namespace std;
class Solve
{
public:
	Solve(Matrix& _m,Vector4& _v);
	~Solve(void);
	Vector4 getAns();//求解4阶线性方程组
	Matrix m;
	Vector4 v;
};
#endif

