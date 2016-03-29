#ifndef VERTEXGROUP_H
#define VERTEXGROUP_H
#include "vertex.h"
#include "config.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
//此类基本已实现 2016/03/27
class VertexGroup
{
public:
	VertexGroup(void);
	~VertexGroup(void);
	Vertex group[Config::MAX_POINT_NUM];//千万注意这里点是[1,cntVectex];
	int cntVertex;
	bool* isDeleted;//判断某个顶点是否已经被删除
	int addVertex(Vertex);//向group中增加一个顶点,同时根据cnt记录此节点id，返回新加入的结点id
	void delVertex(int);//在group中删除id顶点，其实是在isexist中打标记
	int getCommonVertexNum(int,int);
};
#endif
