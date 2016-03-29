#include "edgeHeap.h"


EdgeHeap::EdgeHeap(void)
{
	cntEdge = 0;
	for(int i = 0;i < Config::MAX_EDGE_NUM;i++)
		isDeleted[i] = false;
}


EdgeHeap::~EdgeHeap(void)
{
}

void EdgeHeap::addEdge(Edge& e){
	cntEdge++;
	e.id = cntEdge;
	int u = min(e.v1,e.v2);
	int v = max(e.v1,e.v2);	
	mapEdgeToID[make_pair(u,v)] = cntEdge;
	pq.push(e);
}

Edge EdgeHeap::getMinDelta(){
	if(pq.size() <= 0){
		return Edge(0,0);
	}
	while(isDeleted[pq.top().id]){
		pq.pop();
	}
	Edge e = pq.top();
	pq.pop();
	return e;
}

void EdgeHeap::delEdge(Edge e){
	int u = min(e.v1,e.v2);
	int v = max(e.v1,e.v2);
	int ID = mapEdgeToID[make_pair(u,v)];
	isDeleted[ID] = true;//打上标记，记录它已经被删除了！！
}
