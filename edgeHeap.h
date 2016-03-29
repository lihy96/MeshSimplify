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
	std::priority_queue<Edge,std::vector<Edge>,cmp> pq;//用于保存边，按照误差从小到大排序
	map<pair<int, int>, int> mapEdgeToID;//建立顶点到边的映射关系
	bool isDeleted[Config::MAX_EDGE_NUM+1];//标记哪些边被删除
	int cntEdge;//边数量
	void addEdge(Edge&);//加边
	void delEdge(Edge);//删边
	Edge getMinDelta();//删除误差最小的边
};
#endif
