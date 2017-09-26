//tju3044, AC, but with 4.87 sec :( where TL is 5sec
#pragma warning (disable:4786)
#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;

#define OPEN  1
#define CLOSE 0

#ifndef ONLINE_JUDGE
typedef __int64 LL;
#else
typedef long long LL;
#endif

template<class Class1,class Class2,class Class3> struct triple{
	Class1 a;	Class2 b;	Class3 c;
	triple(){}
	triple(Class1 _a,Class2 _b,Class3 _c){
		a = _a;
		b = _b;
		c = _c;
	}
	friend bool operator==(const triple &t1,const triple &t2){
		return t1.a == t2.a && t1.b == t2.b && t1.c == t2.c;
	}
	friend bool operator!=(const triple &t1,const triple &t2){
		return !(t1 == t2);
	}
	friend bool operator<(const triple &t1,const triple &t2){
		if(t1.a == t2.a){
			if(t1.b == t2.b)
				return t1.c < t2.c;
			return t1.b < t2.b;
		}
		return t1.a < t2.a;
	}
};

typedef pair<int,int> Point;
typedef triple<int,int,LL> Line;

int zgcd(int x,int y){
	if(!x)	return y;
	if(!y)	return x;
	int r;
	while(r=x%y){
		x=y;
		y=r;
	}
	return y;
}

int n;
Point p[1005];

int ne;
Line e[1000005];

int nNC2[1000000];

//returns a Unique Line [not Line Segment, the DHAROK REKHA]
//	e.g. if A,B,C are colinear then
//	uniqueLine(A,B) = uniqueLine(B,C) = uniqueLine(A,C)
Line uniqueLine(Point A,Point B){
	int dx,dy,g;
	LL	lineValue;

	if(B < A)swap(A,B);
	dx = B.first  - A.first;
	dy = B.second - A.second;

	if(dy < 0)	g = zgcd(dx,-dy);
	else		g = zgcd(dx,dy);

	dx /= g;
	dy /= g;
	lineValue = ( ((LL)(A.first))*((LL)(B.second)) - ((LL)(A.second))*((LL)(B.first)) ) / g;
	return Line(dx,dy,lineValue);
}

int main(){

	int T = 0;
	int i,j;
	int mx,run;
	char buf[1000];

	for(i=1;i<=1000;i++)
		nNC2[i*(i-1)/2] = i;

	while(gets(buf) && !(buf[0]=='-' && buf[1]=='-')){

		n = 0;
		while( !(buf[0]=='-' && buf[1]=='-') ){
			sscanf(buf,"%d%d",&p[n].first,&p[n].second);
			gets(buf);
			n++;
		}

		ne = 0;
		for(i=0;i<n;i++)for(j=i+1;j<n;j++)
			e[ne++] = uniqueLine(p[i],p[j]);

		sort(e,e+ne);

		mx = 1;
		run = 1;
		for(i=1;i<ne;i++){
			if(e[i]==e[i-1])
				run++;
			else{
				if( nNC2[run] > mx)
					mx = nNC2[run];
				run = 1;
			}
		}
		if( nNC2[run] > mx)
			mx = nNC2[run];

		printf("%d. %d\n",++T,mx);
	}
	return 0;
}