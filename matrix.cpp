#include "matrix.h"


Matrix::Matrix(void)
{
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++){
			mat[i][j] = 0;
		}
	}

}

Matrix::~Matrix(void)
{
}

Matrix operator + ( const Matrix& A , const Matrix& B ) {
	Matrix m;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m.mat[i][j] = A.mat[i][j] + B.mat[i][j];
	return m;
}
