//O(xnlogn)
//abs(int^2) < 2^31-1
//uva 11016
//tju 2659
#pragma warning (disable:4786)
#include<stdio.h>
#include<assert.h>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,int> Point;

#define INF	1000000000
#define MAX 1005

#define _max(x,y)	(((x)>(y))?(x):(y))
#define _min(x,y)	(((x)<(y))?(x):(y))

bool sortsum(const PII &a,const PII &b){
	return a.first+a.second < b.first+b.second;
}

PII getGridArea(int n,Point *p){		//returns pair(mingrid,maxgrid)
	static int i,ml;
	static int area1,last1,area2,last2;
	static int x1,x2,x,y1,y2,y3,y4,dx;
	static Point a,b;

	static int m;
	static PII y[MAX];

	x1 = INF;
	x2 = -INF;
	for(i=0;i<n;++i){
		x1 = _min(x1,p[i].first);
		x2 = _max(x2,p[i].first);
	}
	p[n] = p[0];

	area1 = area2 = 0;
	for(x=x1;x<x2;++x){	//for each x,x+1 slice

		m = 0;
		for(i=0;i<n;++i){
			a = p[i];
			b = p[i+1];
			if(a < b)swap(a,b);
			if(b.first <= x && x+1 <= a.first);
			else	continue;

			// (y1-a.s)/(a.s-b.s) = (x-a.f)/(a.f-b.f)
			dx = a.first - b.first;

			ml = a.second*dx + (x - a.first)*(a.second - b.second);
			if(ml >= 0){
				y1 = ml/dx;
				y2 = (ml+dx-1)/dx;
			}
			else{
				y1 = -(-ml+dx-1)/dx;
				y2 = -(-ml)/dx;
			}
			//assert(y1<=y2);

			ml = a.second*dx + (x+1 - a.first)*(a.second - b.second);
			if(ml >= 0){
				y3 = ml/dx;
				y4 = (ml+dx-1)/dx;
			}
			else{
				y3 = -(-ml+dx-1)/dx;
				y4 = -(-ml)/dx;
			}
			//assert(y3<=y4);
			y[m].first = _min(y1,y3);
			y[m].second= _max(y2,y4);

			++m;
		}
		//assert(m%2==0);
		sort(y,y+m,sortsum);

		last1 = last2 = -INF;
		for(i=0;i<m;i+=2){
			if(y[i+1].second > _max(y[i].first,last2))
				area2+=y[i+1].second - _max(y[i].first,last2);
			last2 = _max(last2,y[i+1].second);

			if(y[i+1].first > _max(y[i].second,last1))
				area1+=y[i+1].first - _max(y[i].second,last1);
			last1 = _max(last1,y[i+1].first);
		}
	}
	return PII(area1,area2);
}

int n;
Point p[MAX+3];

int main(){
	int i;
	PII ans;
	while(scanf("%d",&n)==1 && n){
		for(i=0;i<n;++i)
			scanf("%d%d",&p[i].first,&p[i].second);
		p[n] = p[0];
		ans = getGridArea(n,p);
		printf("min = %d max = %d\n",ans.first,ans.second);
	}
	return 0;
}