#include<math.h>

#define S(x) ((x)*(x))

#define D2(a,b)	(S(a.x-b.x) + S(a.y-b.y))
#define D1(a,b)	(sqrt(D2(a,b)))

struct Point{
	double x, y;
	Point(){}
	Point(double x1,double y1){
		x=x1;
		y=y1;
	}
};

struct Circle{
	Point cen;
	double rad;
	Circle(){}
	Circle(Point cen1, double rad1){
		cen=cen1;
		rad=rad1;
	}
};

double area_and(Circle p,Circle q){
	double d,h,s,ta,pt,qt,ret;

	if( p.rad > q.rad )swap(p,q);
	//Now p.rad < q.rad

	d = D1(p.cen,q.cen);
	if( d < q.rad - p.rad || Z(d) || E(d,q.rad - p.rad))
		return pi*S(p.rad);
	if( d > p.rad + q.rad || E(d,p.rad + q.rad))
		return 0;

	s  = (p.rad + q.rad + d) / 2;
	ta = sqrt(s*(s-d))*sqrt((s-p.rad)*(s-q.rad));
	h  = 2*ta / d;
	pt = acos( (S(p.rad) + D2(p.cen,q.cen) - S(q.rad)) / (2.*p.rad*d) );
	qt = acos( (S(q.rad) + D2(p.cen,q.cen) - S(p.rad)) / (2.*q.rad*d) );

	return pt*S(p.rad) + qt*S(q.rad) - h*d;
}
