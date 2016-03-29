#ifndef CONFIG_H
#define CONFIG_H
//配置类，用于存放一些常亮
class Config
{
public:
	Config(void);
	~Config(void);
	static const int MAX_POINT_NUM = 1000000;//最多顶点数
	static const int MAX_EDGE_NUM = 20000000;//最多边数
	static const double EPS;//无穷小，当做0
	static const double INF;//无穷大
};
#endif