#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 100005

#define A(a,b,c)	((a.x*b.y+b.x*c.y+c.x*a.y) - (a.y*b.x+b.y*c.x+c.y*a.x))

int n;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0){
		x=_x;
		y=_y;
	}
	void scan(){
		scanf("%d%d",&x,&y);
	}
}p[MAX];

bool sortx(const Point &p,const Point &q){
	if(p.x == q.x)
		return p.y < q.y;
	return p.x < q.x;
}

bool operator==(const Point &p,const Point &q){
	return p.x==q.x && p.y==q.y;
}

vector<int>		cindex;

int ns,s[MAX];
void convexhull(int n,Point *p,vector<int> &vindex){
	int i;

	vindex.clear();

	if(n<=2){
		for(i=0;i<n;i++)
			vindex.push_back(i);
		return;
	}

	//lower hull : 1) lesser X, then 2) lesser Y
	ns = 1;
	s[0] = 0;
	for(i=1;i<n;i++){
		if(p[i]==p[i-1])
			continue;
		while( ns >= 2 && A( p[s[ns-2]],p[s[ns-1]],p[i]) <= 0 )
			ns--;
		s[ns++] = i;
	}

	for(i=0;i<ns;i++)
		vindex.push_back(s[i]);

	//upper hull : 1) greater X, then 2) greater Y
	ns = 1;
	s[0] = n-1;
	for(i=n-2;i>=0;i--){
		if(p[i]==p[i+1])
			continue;
		while( ns >= 2 && A( p[s[ns-2]],p[s[ns-1]],p[i]) <= 0 )
			ns--;
		s[ns++] = i;
	}
	
	if( !(p[vindex[vindex.size()-1]] == p[s[0]]) )
		vindex.push_back(s[0]);

	for(i=1;i<ns-1;i++)
		vindex.push_back(s[i]);

	if( !(p[vindex[0]] == p[s[ns-1]]) )
		vindex.push_back(s[ns-1]);
}

int main(){

	int i;
	while(scanf("%d",&n)==1 && n){

		for(i=0;i<n;i++)
			p[i].scan();

		sort(p,p+n,sortx);

		convexhull(n,p,cindex);

/*		printf("%d\n",cindex.size());
		for(i=0;i<cindex.size();i++)
			printf("%d %d\n",p[cindex[i]].x, p[cindex[i]].y);
		printf("\n");
*/
		if(n == cindex.size())
			printf("No\n");
		else
			printf("Yes\n");
	}
	
	return 0;
}