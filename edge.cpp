#include "edge.h"


Edge::Edge(int _u,int _v)
{
	id = -999;
	v1 = _u;
	v2 = _v;
	deltaV = Config::INF * 1.0;
}


Edge::~Edge(void)
{
}



