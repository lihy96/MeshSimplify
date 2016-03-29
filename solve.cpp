#include "solve.h"


Solve::Solve(Matrix& _m,Vector4& _v)
{
	for(int i = 0;i < 4;i++)
		for(int j = 0;j < 4;j++)
			m.mat[i][j] = _m.mat[i][j];
	for(int i  =0;i < 4;i++)
		v.v[i] = _v.v[i];
}


Solve::~Solve(void)
{
}

Vector4 Solve::getAns(){
	for (int i = 0; i < 4; i++) {
		int j = 0;
		while (j < 4 && fabs(m.mat[i][j]) < Config::EPS)
			j++;
		if (j == 4)
			continue;
		for (int k = 0; k < 4; k++) {
			if (k != i) {
				double rate = m.mat[k][j] / m.mat[i][j];
				for (int l = 0; l < 4; l++)
					m.mat[k][l] -= m.mat[i][l] * rate;
				v.v[k] -= v.v[i] * rate;
			}
		}
	}	
	Vector4 X;
	for (int i = 0; i < 4; i++) {
		int j = 0;
		while (j < 4 && fabs(m.mat[i][j]) < Config::EPS)
			j++;
		if (j == 4)
			return Vector4(0, 0, 0, -1);
		X.v[i] = v.v[i] / m.mat[i][j];
	}
	X.v[4] = 1;
	return X;
}

