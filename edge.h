#ifndef EDGE_H
#define EDGE_H
#include "myVec3d.h"
#include <cstdlib>
#include <cstdio>
//边类，用于表示一条边
class Edge
{
public:
	Edge(int _u = -99,int _v = -99);
	~Edge(void);
	int id;//边序号
	int v1,v2;//端点的编号
	MyVec3d v;//收缩后形成点
	double deltaV;//边收缩成点v的代价
};

#endif