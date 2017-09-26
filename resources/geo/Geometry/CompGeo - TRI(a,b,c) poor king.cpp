#include<stdio.h>
#include<math.h>

#define LMT 1e-10

struct Point{
	double x,y;
}A,B,C,D,E,F,X;

struct Line{
	double p,q,r;
}BF,CE;

int Z(double x){
	return (fabs(x) < LMT);
}

int main(){
	int N = 1;
	double a,b,c;
	
	double l,m,n;
	
	double X,Y;
	
	while(scanf("%lf%lf%lf",&a,&b,&c)==3){
		if( Z(a+1) )
			break;
		
		printf("Set %d:\n",N++);
		if( a*c > b*b || Z(a*c - b*b)){	//ac >= b^2
			printf("Poor King!\n");
			continue;
		}
		
		if( Z(a) || Z(c) ){
			printf("0.0000\n");
			continue;
		}
		
		l = sqrt(2.*b);
		m = 2*a / l;
		n = 2*c / l;
		
		X = n*l*(l+m) / (l*l - m*n);
		Y = m*l*(l+n) / (l*l - m*n);
		
		printf("%.4lf\n", X*Y  -  X*(Y - m) / 2.  -  Y*(X-n) / 2.);
		
		
	}
	
	return 0;
}
