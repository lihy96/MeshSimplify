#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;
class Matrix
{
public:
	Matrix(void);
	~Matrix(void);
	double mat[5][5];//4阶矩阵，保险起见多开
	friend Matrix operator + (const Matrix&, const Matrix&);//用于误差矩阵Q的相加
};

#endif 

