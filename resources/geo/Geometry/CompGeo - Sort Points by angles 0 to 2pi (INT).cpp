#include<stdio.h>
#include<algorithm>
#include<utility>
using namespace std;

#define _abs(x)		(((x)>0)?(x):-(x))
#define _max(x,y)	(((x)>(y))?(x):(y))
#define _min(x,y)	(((x)<(y))?(x):(y))

#define S(x)	((x)*(x))
#define D2(a,b)	(S(a.first-b.first) + S(a.second-b.second))

typedef __int64	LL;
typedef pair<int,int> Point;

int quad(const Point &a){
	if(!a.first && !a.second)	return 0;
	if(a.first >  0 && a.second >= 0)	return 1;
	if(a.first <= 0 && a.second >  0)	return 2;
	if(a.first <  0 && a.second <= 0)	return 3;
	return 4;
}
int sortPointByAngles(const Point &a,const Point &b){
	
	//sort by quadrant [inc]
	int aa = quad(a);
	int bb = quad(b);
	if(aa!=bb)	return aa < bb;
	
	//sort by angles [inc]
	LL area = ((LL)(a.first))*((LL)(b.second)) - ((LL)(a.second))*((LL)(b.first));
	if(area)	return area > 0;

	//sort by distance from origin [inc]
	aa = _abs(a.first);
	bb = _abs(b.first);
	if(aa != bb)return aa < bb;
	
	aa = _abs(a.second);
	bb = _abs(b.second);
	return aa < bb;
}

int n;
Point p[100];

int main(){

	int x,y,i;

	i=0;
	for(x=-2;x<=2;x++)for(y=-2;y<=2;y++)
		p[i++] = Point(x,y);

	n=i;

	printf("Unsorted\n");
	for(i=0;i<n;i++)printf("%d %d\n",p[i].first,p[i].second);

	sort(p,p+n,sortPointByAngles);

	printf("\nSorted\n");
	for(i=0;i<n;i++)printf("%d %d\n",p[i].first,p[i].second);

	return 0;
}



