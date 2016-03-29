#ifndef VERTEX_H
#define VERTEX_H
#include "config.h"
#include "myVec3d.h"
#include <vector>
#include <set>
//顶点类
class Vertex
{
public:
	Vertex(void);
	Vertex(MyVec3d);
	Vertex(double,double,double);
	~Vertex(void);

	int id;//顶点编号
	MyVec3d pos;//顶点坐标位置
	std::set<int> connectVertexes;//邻接点
	void addConnectVertex(int);//增加编号为id邻接点
	void delConnectVertex(int);//删除编号为id邻接点
	bool isExistConnectVertex(int);//是否已经存在了某个邻接点
};
#endif 
