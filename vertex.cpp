#include "vertex.h"


Vertex::Vertex(void)
{
	id = -99;
	connectVertexes.clear();
}

Vertex::Vertex(MyVec3d t)
{
	id = -98;
	connectVertexes.clear();
	pos = t;
}

Vertex::Vertex(double x,double y,double z)
{
	id = -97;
	connectVertexes.clear();
	pos = MyVec3d(x,y,z);
}


Vertex::~Vertex(void)
{
}

void Vertex::addConnectVertex(int num){
	connectVertexes.insert(num);
}

void Vertex::delConnectVertex(int num){
	connectVertexes.erase(num);
}

bool Vertex::isExistConnectVertex(int num){
	return (connectVertexes.count(num) >  0);
}


