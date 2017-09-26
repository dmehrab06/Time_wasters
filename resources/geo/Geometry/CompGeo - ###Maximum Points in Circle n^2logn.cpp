#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 305
#define EPS 1e-4

#define _abs(x)	( ((x)>0) ? (x) : -(x) )
#define Z(x)	(_abs(x) < EPS)
#define E(x,y)	(_abs((x)-(y)) < EPS)

#define S(x)	((x)*(x))
#define D2(a,b)	(S(a.x-b.x) + S(a.y-b.y))
#define D1(a,b)	(sqrt(D2(a,b)))

#define OPEN	0
#define CLOSE 	1

double pi = 2.*acos(0.);

int n;
double radius;

struct Point{
	double x,y;
	
	Point(double _x=0,double _y=0){
		x = _x;
		y = _y;
	}
	
	void scan(){
		scanf("%lf%lf",&x,&y);
	}
}p[MAX];

struct Event{
	double angle;
	int type,id;
	
	Event(double _angle=0,int _type=0,int _id=0){
		angle	= _angle;
		type	= _type;
		id		= _id;
		if(angle < 0)						angle += 2*pi;
		if(angle > 2*pi || E(angle,2*pi))	angle -= 2*pi;
	}
};

vector<Point>	vp;
vector<Event>	ve;

bool operator<(const Event &p,const Event &q){
	if( E(p.angle,q.angle) )
		return p.type < q.type;	//priority does not matter, 2 vabei AC
	return p.angle < q.angle;
}

double mytan(Point p,Point p1){
	double dx = p1.x - p.x;
	double dy = p1.y - p.y;
	
	if(Z(dy)){
		if(dx > 0)	return 0;
		else		return pi;
	}
	
	if(Z(dx)){
		if(dy > 0)	return pi/2.;
		else		return 3*pi/2.;
	}
	
	double at = atan2(dy,dx);
	if(at < 0)	at += 2*pi;
	
	return at;
}

int supmax;
int taken[MAX];

void solve(Point c){
	int		i;
	int		run;
	int		smax;
	Point	center;
	double	d, theta, alpha;
	
	ve.clear();
	vp.clear();
	
	for(i=0;i<n;i++){
		d = D1(c,p[i]);
		if( !E(d,2*radius) && d > 2*radius)
			continue;
	
		vp.push_back(p[i]);

		if( Z(d) )
			continue;

		theta = mytan(c,p[i]);
		alpha = acos(d/2.);
		ve.push_back( Event(theta-alpha, OPEN  , vp.size()-1) );
		ve.push_back( Event(theta+alpha, CLOSE , vp.size()-1) );
	}
	
	sort(ve.begin(),ve.end());

	run = 0;
	//init enclosure with circle at (c.x+radius,c.y)
	center = Point(c.x + radius , c.y);

	for(i=0;i<vp.size();i++){
		d = D1(center,vp[i]);
		if( E(d,radius) || d < radius){
			run++;
			taken[i] = 1;
		}
		else
			taken[i] = 0;
	}

	smax = run;
	
	for(i=0;i<ve.size();i++){
		if(ve[i].type==OPEN){
			if(taken[ ve[i].id ] == 0)
				run++;
		}
		else
			run--;
		
		if(run > smax)
			smax = run;
	}

	if(smax > supmax)
		supmax = smax;
}

int main(){
	
	int i;
	
	while(scanf("%d",&n)==1 && n){
		
		for(i=0;i<n;i++)
			p[i].scan();

		radius = 1;	//for this problem

		supmax = 0;
		for(i=0;i<n;i++)
			solve(p[i]);
	
		printf("%d\n",supmax);
	}
	
	return 0;
}