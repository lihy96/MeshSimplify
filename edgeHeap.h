#ifndef EDGEHEAP_H
#define EDGEHEAP_H
#include "config.h"
#include "edge.h"
#include <queue>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
class EdgeHeap
{

public:
	EdgeHeap(void);
	~EdgeHeap(void);
	struct cmp{
		bool operator() (Edge X, Edge Y){
			return X.deltaV > Y.deltaV;
		}
	};
	std::priority_queue<Edge,std::vector<Edge>,cmp> pq;
	map<pair<int, int>, int> mapEdgeToID;
	bool isDeleted[Config::MAX_EDGE_NUM+1];
	int cntEdge;
	void addEdge(Edge&);//加边
	void delEdge(Edge);

	Edge getMinDelta();//删除误差最小的边
};
#endif
