#include<stdio.h>
#include<math.h>

#include<vector>
#include<algorithm>
using namespace std;

#define EPS 1e-8
#define MAX 105

#define _abs(x)		(((x)>0)?(x):-(x))
#define _max(x,y)	(((x)>(y))?(x):(y))
#define _min(x,y)	(((x)<(y))?(x):(y))

#define all(x)	x.begin(),x.end()

#define S(x)	((x)*(x))
#define Z(x)	(_abs(x) < EPS)
#define E(x,y)	Z((x)-(y))

#define D2(a,b)	(S(a.x-b.x) + S(a.y-b.y))
#define D1(a,b)	(mysqrt(D2(a,b)))


struct Circle{
	double x,y,r,xlo,xhi;
	void scan(){
		scanf("%lf%lf%lf",&x,&y,&r);
		xlo=x-r;
		xhi=x+r;
	}
};

struct Slice{
	double y1,y2,y3,y4,area;
	double YY1,YY2;
	friend bool operator<(const Slice &a,const Slice &b){
		return a.YY1 > b.YY1; 
	}
};

double mysqrt(double x){
	if(x < 0)	return 0;
	return sqrt(x);
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
double myasin(double x){
	if(x < -1)	return -pi/2.;
	if(x > 1)	return pi/2.;
	return asin(x);
}

int ns;
Slice s[2*MAX];
vector<double> vx,X;
double circleUnionArea(int n,Circle *c){
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
		if(d+EPS > c[i].r + c[j].r || d < _abs(c[i].r - c[j].r)+EPS )
			continue;
		getCircleIsects(c[i],c[j],x1,x2);
		vx.push_back(x1);
		vx.push_back(x2);
	}
	sort(all(vx));

	X.clear();
	X.push_back(vx[0]);
	for(i=1;i<vx.size();i++)if( !E(vx[i],vx[i-1]))
		X.push_back(vx[i]);

//	for(i=0;i<X.size();i++)
//		printf(">>> %lf\n",X[i]);

	int last;
	double area = 0,run;
	double xgap, dx1,dy1, dx2,dy2, lasty , mindy,maxdy;
	double t1,t2;

	for(k=0;k+1<X.size();k++){
		x1 = X[k];
		x2 = X[k+1];
		xgap = x2-x1;
		
		ns = 0;
		for(i=0;i<n;i++){
			if(x2 < c[i].xlo+EPS)	continue;
			if(c[i].xhi < x1+EPS)	continue;
			
			dx1 = x1-c[i].x;
			dy1 = mysqrt( S(c[i].r) - S(dx1) );
			
			dx2 = x2-c[i].x;
			dy2 = mysqrt( S(c[i].r) - S(dx2) );

			if(dy1 < dy2){
				mindy = dy1;
				maxdy = dy2;
			}
			else{
				mindy = dy2;
				maxdy = dy1;
			}

			t1 = myasin((x1-c[i].x)/c[i].r);
			t2 = myasin((x2-c[i].x)/c[i].r);

//			printf(">>>>>>>>>> %lf %lf %.15lf %.15lf\n",dy1,dy2 , S(c[i].r) - S(dx1) , S(c[i].r) - S(dx2));

			s[ns].y1	= c[i].y+maxdy;
			s[ns].y2	= c[i].y+mindy;
			s[ns].y3	= c[i].y-mindy;
			s[ns].y4	= c[i].y-maxdy;
			s[ns].YY1	= s[ns].y1 + s[ns].y2;
			s[ns].YY2	= s[ns].y3 + s[ns].y4;
			s[ns].area  = 0.5*S(c[i].r)*((t2-t1) + 0.5*(sin(2*t2)-sin(2*t1))) - xgap*mindy;
			++ns;
		}

		if(ns==0)
			continue;

		sort(s,s+ns);

//		for(i=0;i<ns;i++)
//			printf(">>%6.2lf %6.2lf %6.2lf %6.2lf aaa %6.2lf\n",s[i].y1,s[i].y2,s[i].y3,s[i].y4, s[i].area);

		run = 0;
		j = 0;
		last = 0;
		lasty = s[j].YY2;
		for(i=1;i<ns;i++){
			if(s[i].YY1 > s[last].YY2 || E(s[i].YY1,s[last].YY2)){
				if(s[i].YY2 < s[last].YY2)
					last = i;
			}
			else{
				run += s[j].area + s[last].area + xgap*(s[j].y2-s[last].y3);
//				printf("%d %d\n",j,i-1);
				j = i;
				last = i;
				lasty = s[i].YY2;
			}
		}
		run += s[j].area + s[last].area + xgap*(s[j].y2-s[last].y3);
//		printf("%d %d\n",j,i-1);

//		printf("boss %lf\n\n\n",run);
		
		area += run;
	}
	return area;
}

int n;
Circle c[MAX];

int main(){
	int i;
	while(scanf("%d",&n)==1 && n){
		for(i=0;i<n;i++)
			c[i].scan();
		printf("%.3lf\n",circleUnionArea(n,c) );
	}
	return 0;
}
