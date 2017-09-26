//ac - graham scan - all possible points
#include<assert.h>
#include<stdio.h>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 100005
#define EPS 1e-10

#define T(a,b,c)	((a.x*b.y+b.x*c.y+c.x*a.y) - (a.y*b.x+b.y*c.x+c.y*a.x))

#define A(x)	(((x)>0)?(x):-(x))
#define Z(x)	(A(x) < EPS)
#define E(x,y)	(Z(x-y))
#define S(x)	((x)*(x))
#define D(a,b)	(sqrt(S(a.x-b.x) + S(a.y-b.y)))

int n,nq;
struct Point{
	double x,y,a,d;
	string s;
	Point(double _x=0,double _y=0){
		x=_x;
		y=_y;
	}
	void scan(char *t){
		static char buf[1000];
		sscanf(t,"(%lf,%lf)",&x,&y);
		sscanf(t,"%s",buf);
		s = string(buf);
	}
}p[MAX],q[MAX];

bool operator==(const Point &a,const Point &b){
	return E(a.x,b.x) && E(a.y,b.y);
}

double pi = 2*acos(0.);
double mytan(double dx,double dy){
	
	if(Z(dx) && Z(dy))
		assert(0);

	double at = atan2(dy,dx);
	if(at < 0)	at+=2*pi;
	return at;
}

bool spsort(const Point &a,const Point &b){
	if(E(a.a,b.a))	return a.d < b.d;
	return a.a < b.a;
}

int ns,s[MAX];

void convexhull(int n,Point *p,vector<Point> &c){
	
	int i,k,j;

	c.clear();

	if(n==1){
		c.push_back(p[0]);
		return;
	}
	if(n==2){
		c.push_back(p[0]);
		if(!(p[0]==p[1]))	c.push_back(p[1]);
		return;
	}

	//all same points
	for(i=1;i<n;i++)
		if(!(p[i]==p[0]))
			break;
	if(i==n){
		c.push_back(p[0]);
		return;
	}
	/////////////////

	k = 0;
	for(i=1;i<n;i++)
		if(p[i].y < p[k].y || (E(p[i].y,p[k].y) && p[i].x < p[k].x))
			k=i;

	swap(p[0],p[k]);
	
	for(i=1;i<n;i++){
		p[i].a = mytan(p[i].x-p[0].x , p[i].y-p[0].y); 
		p[i].d = D(p[0],p[i]);
	}

	sort(p+1,p+n,spsort);

	
	//colinear points
	for(i=2;i<n;i++)
		if(!E(p[i].a , p[1].a))
			break;
	if(i==n){
		for(i=0;i<n;i++)
			c.push_back(p[i]);
		return;
	}
	/////////////////

	
	for(i=n-2;i>=0;i--)
		if(!E(p[i].a , p[n-1].a))
			break;
	i++;

	for(j=n-1;i<j;i++,j--)
		swap(p[i],p[j]);

	ns = 0;
	s[ns++] = 0;
	s[ns++] = 1;

	for(i=2;i<n;i++){
		while(ns >= 2 && (T(p[s[ns-2]] , p[s[ns-1]] , p[i]) < 0 && !Z(T(p[s[ns-2]] , p[s[ns-1]] , p[i]))) )
			ns--;
		s[ns++] = i;
	}

	for(i=0;i<ns;i++)
		c.push_back(p[s[i]]);
}

vector<Point> c;

int main(){

	int i;
	char buf[10000],*t;

	while(gets(buf)){

		n = 0;
		t = strtok(buf," \n\r");
		while(t!=NULL){
			p[n].scan(t);
			t = strtok(NULL," \n\r");
			n++;
		}

		convexhull(n,p,c);

		for(i=0;i<c.size();i++){
			if(i)	printf(" ");
			printf("%s",c[i].s.c_str());
		}
		printf("\n");
	}
	
	return 0;
}