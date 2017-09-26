#include<stdio.h>
#include<math.h>

#define S(x)		((x)*(x))
#define ABS(x)		(((x)>0)?(x):-(x))
#define MAX(x,y)	(((x)>(y))?(x):(y))
#define MIN(x,y)	(((x)<(y))?(x):(y))

#define EPS		1e-8
#define Z(x)	(ABS(x)  < EPS)

double pi = 2.*acos(0.);
double mysqrt(double x){if(x < 0)	return 0;return sqrt(x);}
double myasin(double x){if(x < -1)	return -pi/2;if(x > 1)	return pi/2;return asin(x);}
double myacos(double x){if(x < -1)	return -pi;if(x > 1)	return 0;return acos(x);}

struct Vector{
	double x,y,z;
	Vector(){}
	Vector(double _x,double _y,double _z){x=_x;y=_y;z=_z;}

	bool scan(){
		return scanf("%lf%lf%lf",&x,&y,&z)==3;}

	double mag2(){
		return S(x)+S(y)+S(z);	}

	double mag(){
		return mysqrt(mag2());	}

	void norm(){
		double d = mag();x/=d;y/=d;	z/=d;}

	Vector unit(){
		Vector ret = *this;	ret.norm();	return ret;	}

	void show(){
		printf("[%.2lf, %.2lf, %.2lf]",x,y,z);}

	void showln(){
		printf("[%.2lf, %.2lf, %.2lf]\n",x,y,z);}
};

Vector operator+(Vector a,Vector b){	return Vector(a.x+b.x, a.y+b.y, a.z+b.z);}
Vector operator-(Vector a){				return Vector (-a.x, -a.y, -a.z);}
Vector operator-(Vector a,Vector b){	return Vector(a.x-b.x, a.y-b.y, a.z-b.z);}
Vector operator*(double a,Vector b){	return Vector(a*b.x, a*b.y, a*b.z);}
Vector operator*(Vector b,double a){	return Vector(a*b.x, a*b.y, a*b.z);}
Vector operator/(Vector b,double a){	return Vector(b.x/a, b.y/a, b.z/a);}

double DOT(Vector a, Vector b){	return a.x*b.x + a.y*b.y + a.z*b.z;}
Vector CROSS(Vector a, Vector b){	return Vector( a.y*b.z - a.z*b.y , a.z*b.x - a.x*b.z , a.x*b.y - a.y*b.x );}
double BOX(Vector a, Vector b, Vector c){	return DOT(a, CROSS(b,c));}

int main(){

	return 0;
}