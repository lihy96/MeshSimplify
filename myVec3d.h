#ifndef MYVEC3D_H
#define MYVEC3D_H
#include "config.h"
#include <cmath>
//此类基本已经实现 2016/03/27
class MyVec3d
{
	
public:
	MyVec3d(double X = 0 , double Y = 0 , double Z = 0 ) : x( X ) , y( Y ) , z( Z ) {};
	~MyVec3d(void);
	double x,y,z;
	friend MyVec3d operator - ( const MyVec3d& );//取反
	friend MyVec3d operator + ( const MyVec3d& , const MyVec3d& );
	friend MyVec3d operator - ( const MyVec3d& , const MyVec3d& );
	friend MyVec3d operator * ( const MyVec3d& , const MyVec3d& );
	friend MyVec3d operator / ( const MyVec3d& , const MyVec3d& );
	friend MyVec3d operator + ( const MyVec3d& , const double& );
	friend MyVec3d operator - ( const MyVec3d& , const double& );
	friend MyVec3d operator * ( const MyVec3d& , const double& );
	friend MyVec3d operator / ( const MyVec3d& , const double& );

	MyVec3d getUnitVectorOfThis();//获得自己的单位向量
	MyVec3d getVerticalVectorCrossed001();//获得与自己垂直的单位向量
	MyVec3d getCross(const MyVec3d&);
	double getDot(const MyVec3d&);
};

#endif

