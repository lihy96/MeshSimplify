#ifndef MESHSIMPLIFY_H
#define MESHSIMPLIFY_H
#include "edgeHeap.h"
#include "vertexGroup.h"
#include "matrix.h"
#include "vector4.h"
#include "solve.h"
#include "config.h"
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
class MeshSimplify
{
	double ratio;
	int cntFace,cntDelFace;//面片数和应该删除的面片数
	EdgeHeap* eHeap;//边的堆
	VertexGroup* vGroup;//点的集合
public:
	MeshSimplify(void);
	~MeshSimplify(void);

	void setRatio(double);//设置简化率
	void setLeftFaceNum(int);//设置最终剩余的面片数

	void input();//读入初始结果
	void start();//开始简化
	void output();//输出结果

	//点的相关操作
	Matrix calVertexDelta(int);
	MyVec3d calVertexPos(Edge&,Matrix);//根据一个边两个点的误差矩阵计算收缩后的点位置
	//边的相关操作
	void calVAndDeltaV(Edge&);//计算并确定一个边v和deltaV;	
};

#endif