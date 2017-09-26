/**********************************************
	All Triangle Fuctions
**********************************************/

#include<stdio.h>
#include<math.h>

#define PI (2.*acos(0.))

#define dis(X1,Y1,X2,Y2) (sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2)))
#define min(x,y) ((x<y)?(x):(y))
#define myabs(x) ((x>0)?(x):-(x))

struct Point{
	double x,y;
}A,B,C,Ic,Cc,Gc;

double Get_Angle(Point A,Point P){
	double dx,dy;
	dx = P.x - A.x;
	dy = P.y - A.y;
	if(dx==0){
		if(dy>0) return PI/2.;
		else return 3.*PI/2.;
	}
	else if (dy==0){
		if (dx>0)
			return 0;
		else return PI;
	}
	if(atan2(dy,dx)<0) return atan2(dy,dx) + 2.*PI;
	return atan2(dy,dx);
}

void Triangle_Area(Point A,Point B,Point C,double *area){
	*area = 0.5 * myabs((A.x*B.y + B.x*C.y + C.x*A.y) - (A.y*B.x + B.y*C.x + C.y*A.x));
}

void Triangle_Sides(Point A,Point B,Point C,double *a,double *b,double *c){
	*a = dis(B.x, B.y, C.x, C.y);
	*b = dis(C.x, C.y, A.x, A.y);
	*c = dis(A.x, A.y, B.x, B.y);
}

void Triangle_Angles(Point A,Point B,Point C,double *alpha,double *beta,double *gamma){
	double a,b,c;
	Triangle_Sides(A,B,C,&a,&b,&c);
	*alpha = acos((b*b + c*c - a*a)/(2.*b*c));
	*beta  = acos((c*c + a*a - b*b)/(2.*c*a));
	*gamma = acos((a*a + b*b - c*c)/(2.*a*b));
}

void In_Circle(Point A,Point B,Point C,Point *P,double *r){
	double a,b,c,s;

	//measuring in-radius:
	Triangle_Sides(A,B,C,&a,&b,&c);
	s = (a+b+c)/2.;
	if(a+b<=c||b+c<=a||c+a<=b)
		*r = 0.;
	else
		*r = sqrt(s*(s-a)*(s-b)*(s-c)) / s;
	
	//measuring the In_center P(x,y):
	P->x = (A.x*a + B.x*b + C.x*c) / (a+b+c);
	P->y = (A.y*a + B.y*b + C.y*c) / (a+b+c);
}

void Circum_Circle(Point A,Point B,Point C,Point *P,double *r){
	double a,b,c,s,k1,k2,k3;

	//measuring circum-radius:
	Triangle_Sides(A,B,C,&a,&b,&c);
	s = (a+b+c)/2.;
	if(a+b<=c||b+c<=a||c+a<=b)
		*r = s/2.;
	else
		*r = (a*b*c)/(4.*sqrt(s*(s-a)*(s-b)*(s-c)));

	//measuring the Circum_center P(x,y):
	k1 = A.x*A.x - B.x*B.x + A.y*A.y - B.y*B.y;
	k2 = A.x*A.x - C.x*C.x + A.y*A.y - C.y*C.y;
	k3 = (A.x*C.y + B.x*A.y + C.x*B.y) - (C.x*A.y + A.x*B.y + B.x*C.y);

	P->x = (k2*(A.y-B.y) - k1*(A.y-C.y))/(2.*k3);
	P->y = (k1*(A.x-C.x) - k2*(A.x-B.x))/(2.*k3);
}

void Center_of_Gravity(Point A,Point B,Point C,Point *P){
	P->x = (A.x + B.x + C.x) / 3.;
	P->y = (A.y + B.y + C.y) / 3.;
}

void main(){
	double area,a,b,c,alpha,beta,gamma,Cr,Ir;
	while(scanf("%lf%lf%lf%lf%lf%lf",&A.x, &A.y, &B.x, &B.y, &C.x, &C.y)==6){
		Triangle_Area(A,B,C,&area);
		Triangle_Sides(A,B,C,&a,&b,&c);
		Triangle_Angles(A,B,C,&alpha,&beta,&gamma);
		In_Circle(A,B,C,&Ic,&Ir);
		Circum_Circle(A,B,C,&Cc,&Cr);		//A,B,C must not be linear
		Center_of_Gravity(A,B,C,&Gc);
		
		printf("******Triangle Status******\n");
		printf("Area = %lf\n",area); 
		printf("Sides a = %lf, b = %lf, c = %lf\n",a,b,c); 
		printf("Angles BAC = %lf, ABC = %lf, ACB = %lf\n",alpha,beta,gamma); 
		printf("In Circle x = %lf,y = %lf,radius = %lf\n",Ic.x,Ic.y,Ir); 
		printf("Circum Circle x = %lf,y = %lf,radius = %lf\n",Cc.x,Cc.y,Cr); 
		printf("Center of Gravity x = %lf,y = %lf\n",Gc.x,Gc.y);
		printf("\n");

	}
}