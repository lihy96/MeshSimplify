#include "meshSimplify.h"
#include "config.h"
#include "matrix.h"
#include "vector4.h"
#include "solve.h"
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc,char* argv[]){	
	if(argc != 4){
		cout << "error input " << endl;
		return -1;
	}else{
		clock_t start = clock();//计时开始

		MeshSimplify* meshSimplify = new MeshSimplify();
		freopen(argv[1],"r",stdin);
		freopen(argv[2],"w",stdout);
		meshSimplify->setRatio(atof(argv[3]));//设置简化率
		meshSimplify->input();//读入
		meshSimplify->start();//开始简化
		meshSimplify->output();//输出

		clock_t finish = clock();//计时结束，计算简化时间
		cout << "# time use: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	}
	return 0;
}


/*注意：
0.建堆过程的break很容易出错！！！！
1.vertexgroup中的结点是从【1，cnt】
2.edgeheap中的边是【1，cnt】
3.为什么缩点的时候有时选中点，为什么有时解方程返回0,0,0，-1
*/


/*

目前进度，该写meshsimplify类中start函数了

*/