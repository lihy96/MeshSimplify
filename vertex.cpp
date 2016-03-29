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
	/*vector
	if(isExistConnectVertex(num))
		return;
	connectVertexes.push_back(num);
	*/
}

void Vertex::delConnectVertex(int num){
	connectVertexes.erase(num);
	/*vector
	for (std::vector<int>::iterator it = connectVertexes.begin(); it != connectVertexes.end(); it++) {
		if ((*it) == id) {
			connectVertexes.erase(it);
			return;
		}
	}
	*/
}

bool Vertex::isExistConnectVertex(int num){
	return (connectVertexes.count(num) >  0);
	/*vector
	for (std::vector<int>::iterator it = connectVertexes.begin(); it != connectVertexes.end(); it++) {
		if ((*it) == id)
			return true;
	}
	return false;
	*/
}


