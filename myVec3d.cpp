#include "myVec3d.h"

MyVec3d::~MyVec3d(void)
{

}

MyVec3d operator - ( const MyVec3d& A){
	return MyVec3d( -A.x, -A.y , -A.z );
}

MyVec3d operator + ( const MyVec3d& A , const MyVec3d& B ){
	return MyVec3d( A.x + B.x , A.y + B.y , A.z + B.z );
}

MyVec3d operator - ( const MyVec3d& A , const MyVec3d& B ){
	return MyVec3d( A.x - B.x , A.y - B.y , A.z - B.z );
}

MyVec3d operator * ( const MyVec3d& A , const MyVec3d& B ){
	return MyVec3d( A.x * B.x , A.y * B.y , A.z * B.z );
}

MyVec3d operator / ( const MyVec3d& A , const MyVec3d& B ){
	return MyVec3d( A.x / B.x , A.y / B.y , A.z / B.z );
}

MyVec3d operator + ( const MyVec3d& A , const double& t ){
	return MyVec3d( A.x + t , A.y + t , A.z + t );
}

MyVec3d operator - ( const MyVec3d& A , const double& t ){
	return MyVec3d( A.x - t , A.y - t , A.z - t );
}

MyVec3d operator * ( const MyVec3d& A , const double& t ){
	return MyVec3d( A.x * t , A.y * t , A.z * t );
}

MyVec3d operator / ( const MyVec3d& A , const double& t ){
	return MyVec3d( A.x / t , A.y / t , A.z / t );
}

MyVec3d MyVec3d::getUnitVectorOfThis(){
	double module = sqrt(x * x + y * y + z * z);
	if(module < Config::EPS)
		return MyVec3d(0,0,1);
	return *this / module;
}

MyVec3d MyVec3d::getVerticalVectorCrossed001(){
	//tmp is vertical to this and (0,0,1)
	MyVec3d tmp  = MyVec3d(y,- x,0 );
	double eps = Config::EPS;
	if(fabs(x) < eps && fabs(y) < eps && fabs(z) < eps)
		return MyVec3d(1,0,0);
	return tmp.getUnitVectorOfThis();
	
}

MyVec3d MyVec3d::getCross(const MyVec3d& A){
	return MyVec3d(y * A.z - z * A.y , z * A.x - x * A.z , x * A.y - y * A.x );
}

double MyVec3d::getDot(const MyVec3d& A){
	return x * A.x + y * A.y + z * A.z;
}





