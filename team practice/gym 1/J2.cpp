#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<time.h>
#include<bitset>
using namespace std;
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T> inline void gmax(T &a,T b){if(b>a)a=b;}
template <class T> inline void gmin(T &a,T b){if(b<a)a=b;}
const int N=5e4+100,M=0,Z=1e9+7,maxint=2147483647,ms31=522133279,ms63=1061109567,ms127=2139062143;const double eps=1e-8,PI=acos(-1.0);//.0
void fre()
{
    freopen("journey.in","r",stdin);
    freopen("journey.out","w",stdout);
}
int casenum,casei;
int n,m;
int p[N],d[N];
LL f[N];
multiset<LL>sot;
bool check(int len)
{
	sot.clear();
	f[1]=0;sot.insert(0);
	for(int i=2;i<=len+1;i++)
	{
		f[i]=d[i];
		sot.insert(f[i]);
	}
	for(int i=len+2;i<=n;i++)
	{
		sot.erase(sot.find(f[i-len-1]));
		f[i]=*sot.begin()+d[i];
		sot.insert(f[i]);
	}
	return f[n]<=m;
}
int main()
{
	//fre();
	while(~scanf("%d%d",&n,&m))
	{
		m-=(n-1);
		for(int i=1;i<n;i++)scanf("%d",&p[i]);
		for(int i=n-2;i>=1;i--)gmin(p[i],p[i+1]);
		for(int i=2;i<n;i++)scanf("%d",&d[i]);
		int l=1;
		int r=n-1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		printf("%d\n",p[l]);
	}
}
/*
【trick&&吐槽】
1，QwQ逻辑要清楚，一开始忘了算必须要走的时间n-1，导致wawawa。
2，总的时间耗费是可能超过int的，鉴于m只有1e9，我们可以动态返回no，否则就要用LL。

【题意】
有n（[2,5e4]）个点，排列在数轴上，坐标分别为1~n。我们要从起点1走到终点n，每走1单位的路耗费1单位时间。
我们可以选择购买单次电量最大支撑行程为1~n-1的电动车，每种电动车有一个价格p[]。
然后在2~n-1的每个点都可以充电，每个点有一个充电时间d[]，每次充电一定可以充满。

我们想要在m（[n-1，1e9]）时间内从1点到达n点，
让你输出，在满足这个条件，我们至少要要花费多少钱，才能成功从1走到n

【类型】
二分+（单调队列 or set）

【分析】
首先，一定有解，买里程为n-1的车肯定可以。
然后，我们发现，我们至少要花费的时间为n-1，这个可以先提前减掉。
继续——我们一定不会往回走，因为每次能走的距离是从1开始的。
也就是说，对于同里程的车，相同成本下，肯定走得越远就越优秀。所以不会往回走。
这里考虑到了"同里程的车"，于是，我们可以先枚举车的里程。

车里程越大，车性能越优。
如果车的价格更便宜，里程还更大，那我们对于一个里程小的需求，还不如买这个里程大的车。
于是我们可以按照里程由大到小，价格向小的方向更新。

这样子我们就有了一个（里程，价格）双单调递增的一个车的性能价格表。
于是我们就可以二分答案啦。
二分我们买的车的里程。用一个multiset存放距离每个点[1~里程上限]的其他点，
维护f[i]=min(f[前驱点])+d[i]这样的DP方程，最后f[n]是否在m范围内决定着这个价格是否可行。

【时间复杂度&&优化】
O（nlognlogn）

*/
