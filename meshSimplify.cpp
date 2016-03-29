#include "meshSimplify.h"
MeshSimplify::MeshSimplify(void)
{
	eHeap = new EdgeHeap();
	vGroup = new VertexGroup();
	cntFace = 0;
}


MeshSimplify::~MeshSimplify(void)
{
}

void MeshSimplify::start(){
	for(int i = 0;i < cntDelFace;i += 2){//开始删边	
		Edge e = eHeap->getMinDelta();
		Vertex* v1 = &(vGroup->group[e.v1]);
		Vertex* v2 = &(vGroup->group[e.v2]);
		Vertex v0 = e.v;
		int v0_id = vGroup->addVertex(v0);
		Vertex* pV0 = &(vGroup->group[v0_id]);//定位到缩后的点

		set<int> connectV;//pV0的邻接点
		connectV.clear();
		eHeap->delEdge(e);//打上边已经删除的标记

		for(set<int>::iterator it = v1->connectVertexes.begin(); it != v1->connectVertexes.end();it++){
			if((*it)!=v2->id){
				eHeap->delEdge( Edge((*it),v1->id));
				vGroup->group[(*it)].delConnectVertex(v1->id);
				connectV.insert((*it));
			}

		}

		for(set<int>::iterator it = v2->connectVertexes.begin(); it != v2->connectVertexes.end();it++){
			if((*it)!=v1->id){
				eHeap->delEdge( Edge((*it),v2->id));
				vGroup->group[(*it)].delConnectVertex(v2->id);
				connectV.insert((*it));
			}

		}

		//将原来u，v的结点的邻接点集合中加入新点o
		for (set<int>::iterator it = connectV.begin();it != connectV.end(); it++) {
			vGroup->group[(*it)].addConnectVertex(v0_id);
			vGroup->group[v0_id].addConnectVertex(*it);
		}
		vGroup->isDeleted[v1->id] = true;//标记结点已经被删除
		vGroup->isDeleted[v2->id] = true;

		//给新点加边
		for (set<int>::iterator it = connectV.begin(); it != connectV.end(); it++) {
			Edge e((*it),v0_id);
			calVAndDeltaV(e);
			eHeap->addEdge(e);
		}



	}

}

void MeshSimplify::setRatio(double _ratio){
	ratio = _ratio;
}

void MeshSimplify::input(){
	int cntv=0,cntf=0;
	char s[256];
	int tmp = 0;
	while (scanf("%s", s) == 1){
		tmp++;
		switch (s[0]) {
			case '#': fgets(s, sizeof s, stdin); break;
			case 'v': {
				cntv++;
				double x, y, z;
				scanf("%lf %lf %lf", &x, &y, &z);
				vGroup -> addVertex(Vertex(x,y,z));
				break;
			}
			case 'f': {
				cntf++;
				cntFace++;
				int a, b, c;
				scanf("%d%d%d", &a, &b, &c);
				//建立邻接关系,已检查
				vGroup->group[a].addConnectVertex(b);
				vGroup->group[a].addConnectVertex(c);
				vGroup->group[b].addConnectVertex(a);
				vGroup->group[b].addConnectVertex(c);
				vGroup->group[c].addConnectVertex(a);
				vGroup->group[c].addConnectVertex(b);
				break;
			}
			default: break;
		}
	}

	//下面将边加入到边堆中
	for(int i = 1;i <= vGroup->cntVertex;i++){//遍历所有顶点
		for(set<int>::iterator it = vGroup->group[i].connectVertexes.begin();//遍历某个顶点的所有邻接点
			it != vGroup->group[i].connectVertexes.end();it++){
			if(i < (*it))//这里优化的不太确定！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
				break;
			
			Edge e((*it),i);
			calVAndDeltaV(e);//每创建一条边就要计算缩后点和误差
			eHeap->addEdge(e);//将一条边加入其中
		}
	}
	cntDelFace = (int)((1-ratio) * cntFace);//计算应该剩下多少个面
}


void MeshSimplify::output(){
	int cnt = 0;
	int cntv=0,cntf=0;
	for(int i = 1;i <= vGroup->cntVertex;i++){//输出所有点
		if(vGroup->isDeleted[i])//如果第i个点已经删掉了，就略去
			continue;
		Vertex* v = &vGroup->group[i];
		cnt++;
		v->id = cnt;
		printf("v %lf %lf %lf\n",v->pos.x,v->pos.y,v->pos.z);
	}	
	for(int i = 1;i <= vGroup->cntVertex;i++){//输出所有面
		if(vGroup->isDeleted[i])//如果第i个点已经删掉了，就略去
			continue;
		Vertex* v = &(vGroup->group[i]);//对于第i个点
		for(set<int>::iterator it1 = v->connectVertexes.begin();it1 != v->connectVertexes.end();it1++){
			if(i >= (*it1))
				continue;
			for(set<int>::iterator it2 = v->connectVertexes.begin();it2 != v->connectVertexes.end();it2++){
				if((*it1) < (*it2) && (vGroup->group[(*it1)].isExistConnectVertex(*it2))){
					printf("f %d %d %d\n",v->id,vGroup->group[(*it1)].id,vGroup->group[(*it2)].id);
					cntf++;
				}	
			}
		}

	}
}

void MeshSimplify::calVAndDeltaV(Edge& e){
	Matrix mat = calVertexDelta(e.v1) + calVertexDelta(e.v2);//计算完顶点的误差然后求和
	e.v = calVertexPos(e,mat);//确定一个点收缩后的点	
	Vector4 X(e.v.x, e.v.y, e.v.z, 1.0);
	if (vGroup->getCommonVertexNum(e.v1, e.v2) != 2) {//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		e.deltaV = 0;
		return;
	}
	double pri = 0;
	for (int i = 0; i < 4; i++) {
		double p = 0;
		for (int j = 0; j < 4; j++)
			p += X.v[j] * mat.mat[i][j];
		pri += p * X.v[i];
	}
	e.deltaV = pri;
}

Matrix MeshSimplify::calVertexDelta(int _id){
	Matrix ans;
	Vertex* p = &(vGroup->group[_id]);
	for(set<int>::iterator it1 = p->connectVertexes.begin();it1 != p->connectVertexes.end();it1++){
		for(set<int>::iterator it2 = p->connectVertexes.begin();it2 != p->connectVertexes.end();it2++){
			if((*it1) < (*it2) && (vGroup->group[(*it1)].isExistConnectVertex(*it2))){
				Vertex* v1 = &(vGroup->group[(*it1)]);
				Vertex* v2 = &(vGroup->group[(*it2)]);
				MyVec3d n = ( (v1->pos) - (p->pos) ).getCross( (v2->pos) - (p->pos)).getUnitVectorOfThis();
				Vector4 tmp(n.x, n.y, n.z, -(p->pos.getDot(n)));
				for(int i = 0;i < 4;i++){
					for(int j = 0;j < 4;j++){
						ans.mat[i][j] += tmp.v[i] * tmp.v[j];
					}

				}

			}

		}

	}
	return ans;

}

MyVec3d MeshSimplify::calVertexPos(Edge& e,Matrix m){
	MyVec3d mid = (vGroup->group[e.v1].pos + vGroup->group[e.v2].pos) / 2;  //中点，应对退化情况
	m.mat[3][0] = 0;
	m.mat[3][1] = 0;
	m.mat[3][2] = 0;
	m.mat[3][3] = 1;
	
	Vector4 Y(0,0,0,1);
	Solve* solve = new Solve(m,Y);
	Vector4 ans = solve->getAns();
	if(ans.v[3] > 0)
		return MyVec3d(ans.v[0],ans.v[1],ans.v[2]);
	else
		return mid;
}

/*
void MeshSimplify::addEdgeToHeap(){
	for(int i = 1;i <= vGroup->cntVertex;i++){//遍历所有结点
		for(set<int>::iterator it = vGroup->group[i].connectVertexes.begin();
			it != vGroup->group[i].connectVertexes.end();it++){//遍历所有邻接点

		}

	}

}*/






