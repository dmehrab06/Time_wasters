#include<assert.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

#include<vector>
#include<algorithm>
using namespace std;

#define EPS 1e-10
#define MAX 105

#define _abs(x)		(((x)>0)?(x):-(x))
#define _max(x,y)	(((x)>(y))?(x):(y))
#define _min(x,y)	(((x)<(y))?(x):(y))

#define all(x)	x.begin(),x.end()

#define S(x)	((x)*(x))
#define Z(x)	(_abs(x) < EPS)

#define D2(a,b)	(S(a.x-b.x) + S(a.y-b.y))
#define D1(a,b)	(mysqrt(D2(a,b)))

double myasin(double x);
double mysqrt(double x);

struct Circle{
	int x,y,r,xlo,xhi;
	void scan(){
		scanf("%d%d%d",&x,&y,&r);
		xlo=x-r;
		xhi=x+r;
	}
};

#define OPEN 0
#define CLOSE 1

struct Event{
	int type;
	double y1,y2,aa;	//arcarea = aa
	Event(){}
	Event(int t,double yy1,double yy2,double aaa){
		type = t;
		y1 = yy1;
		y2 = yy2;
		aa = aaa;
	}
};

bool operator<(const Event &p,const Event &q){
	double py = p.y1 + p.y2;
	double qy = q.y1 + q.y2;
	if(_abs(py-qy) < EPS)	return p.type < q.type;
	return py > qy;
}

void getCircleIsects(Circle c1,Circle c2,double &x1,double &x2){
	if(c1.r < c2.r)swap(c1,c2);

	double d = D1(c1,c2);
	double a = ( S(c1.r) + S(d) - S(c2.r) )/(2.*d);
	double h = mysqrt( S(c1.r) - S(a) );

	x1 = c1.x + (a*(c2.x-c1.x) - h*(c2.y-c1.y))/d;
	x2 = c1.x + (a*(c2.x-c1.x) + h*(c2.y-c1.y))/d;
}

double pi = acos(-1.);
vector<double> vx,X;

int ne;
Event e[2*MAX];

int tos;
Event stack[2*MAX];
double inarea[2*MAX];

double ans[2];

void circleUnionArea(int n,Circle *c){
	int i,j,k;
	double d,x1,x2;

	vx.clear();
	for(i=0;i<n;i++){
//		vx.push_back(c[i].x);
		vx.push_back(c[i].x - c[i].r);
		vx.push_back(c[i].x + c[i].r);
	}

	for(i=0;i<n;i++)for(j=i+1;j<n;j++){
		d = D1(c[i],c[j]);
		if(D2(c[i],c[j]) >= S(c[i].r + c[j].r) || D2(c[i],c[j]) <= S(c[i].r - c[j].r) )
			continue;
		getCircleIsects(c[i],c[j],x1,x2);
		vx.push_back(x1);
		vx.push_back(x2);
	}
	sort(all(vx));

	X.clear();
	X.push_back(vx[0]);
	for(i=1;i<vx.size();i++)if( vx[i-1] < vx[i]+EPS )
		X.push_back(vx[i]);

//	for(i=0;i<X.size();i++)printf(">>> %lf\n",X[i]);
	double area;
	double xgap, dx1,dy1, dx2,dy2;
	double t1,t2;

	ans[0] = ans[1] = 0;

	for(k=0;k+1<X.size();k++){
		x1 = X[k];
		x2 = X[k+1];
		xgap = x2-x1;

		ne = 0;
		for(i=0;i<n;i++){
			if(x2 < c[i].xlo+EPS)	continue;
			if(c[i].xhi < x1+EPS)	continue;
			
			dx1 = x1-c[i].x;
			dy1 = mysqrt( S(c[i].r) - S(dx1) );
			
			dx2 = x2-c[i].x;
			dy2 = mysqrt( S(c[i].r) - S(dx2) );

			t1 = myasin(dx1/c[i].r);
			t2 = myasin(dx2/c[i].r);

			area = 0.5*S(c[i].r) * ((t2-t1) + 0.5*(sin(2*t2)-sin(2*t1)) )    -   0.5*xgap*(dy1 + dy2);
			e[ne++] = Event(OPEN, c[i].y+dy1, c[i].y+dy2, area);
			e[ne++] = Event(CLOSE,c[i].y-dy1, c[i].y-dy2, area);
		}
		if(ne==0)
			continue;

		sort(e,e+ne);

		for(i=0;i<ne;i++)
			inarea[i] = 0;

		tos = 1;	//special reason, tos-1 will occur
		stack[tos++] = e[0];
//		assert(e[0].type == OPEN && e[ne-1].type == CLOSE);

		for(i=1;i<ne;i++){
			assert(tos >= 1);
			if(e[i].type == CLOSE){
				area = stack[tos-1].aa + e[i].aa + 0.5*xgap*((stack[tos-1].y1 - e[i].y1) + (stack[tos-1].y2 - e[i].y2));
				ans[tos%2] += area - inarea[tos-1];
				inarea[tos-2] += area;
				inarea[tos-1] = 0;
				tos--;
			}
			else{
				stack[tos++] = e[i];
				inarea[tos-1] = 0;
			}
		}
	}
}

int n;
Circle c[MAX];

int main(){
	int i;
	while(scanf("%d",&n)==1 && n){
		for(i=0;i<n;i++)
			c[i].scan();
		circleUnionArea(n,c);
		printf("%.8lf %.8lf\n",ans[0],ans[1]);
	}
	return 0;
}



double mysqrt(double x){
	if(x < 0)	return 0;
	return sqrt(x);
}
double myasin(double x){
	if(x < -1)	return -pi/2.;
	if(x > 1)	return pi/2.;
	return asin(x);
}
