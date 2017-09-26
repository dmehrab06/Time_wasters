#include<assert.h>
#include<stdio.h>
#include<math.h>


#define EPS		1e-12
#define _abs(x)		(((x)>0)?(x):-(x))
#define _max(x,y)	(((x)>(y))?(x):(y))
#define _min(x,y)	(((x)<(y))?(x):(y))

#define E(x,y)	(_abs((x)-(y)) < EPS)
#define Z(x)	(_abs(x) < EPS)
#define ZN(x)	(x < 0 || Z(x))
#define ZP(x)	(x > 0 || Z(x))
#define S(x)	((x)*(x))

#define UNDEF	-1
#define OUTSIDE	0
#define INSIDE	1
#define CUT		2
//0 <= x1 <= x2 <= R
double ySlice(double R,double x1,double x2){		// area bounded by y=0, x=x1, x=x2, y = sqrt(R*R - x*x)
	double a,t1,t2;
	
	assert( ZP(x1) );
	assert( ZP(x2-x1) );
	assert( ZP(R-x2) );

	t2 = acos(x2/R);
	t1 = acos(x1/R);
	a  = 0.5*( S(R)*(t1-t2) + R*(x2*sin(t2) - x1*sin(t1)) );

	assert( ZP(a) );

	return a;
}

//rect(x1,x2,y1,y2) must be in the FIRST quadrant, 0<=x1<=x2, 0<=y1<=y2
double posXYRectCommon(double R,double x1,double x2,double y1,double y2,int &flag){
	double x3,x4,a,d11,d12,d21,d22;

	assert( ZP(x1));
	assert( ZP(y1));
	assert( ZP(x2-x1) );
	assert( ZP(y2-y1) );

	d11 = S(x1)+S(y1) - S(R); 
	d12 = S(x1)+S(y2) - S(R); 
	d21 = S(x2)+S(y1) - S(R); 
	d22 = S(x2)+S(y2) - S(R);

	if( ZN(d22) ){					//case 1
		a  = (x2-x1)*(y2-y1);
		flag = _max(flag,INSIDE);
	}
	else if( ZN(d12) && ZN(d21) ){	//case 2
		x3 = sqrt(S(R) - S(y2));	//x3 <= x2
		a  = (x3-x1)*(y2-y1) + ySlice(R,x3,x2) - (x2-x3)*y1;
		flag = _max(flag,CUT);
		assert(ZP(x2-x3));
	}
	else if( ZN(d12) ){				//case 3
		x3 = sqrt(S(R) - S(y2));	//x3 <= x4
		x4 = sqrt(S(R) - S(y1));	
		a  = (x3-x1)*(y2-y1) + ySlice(R,x3,x4) - (x4-x3)*y1;
		flag = _max(flag,CUT);
		assert(ZP(x4-x3));
	}
	else if( ZN(d21) ){				//case 4
		a  = ySlice(R,x1,x2) - (x2-x1)*y1;
		flag = _max(flag,CUT);
	}
	else if( ZN(d11) ){				//case 5
		x3 = sqrt(S(R) - S(y1));	//x1 <= x3
		a  = ySlice(R,x1,x3) - (x3-x1)*y1;
		flag = _max(flag,CUT);
		assert(ZP(x3-x1));
	}
	else{							//case 6
		a = 0;
		flag = _max(flag,OUTSIDE);
	}

	assert( ZP(a) );
	assert( ZP( (x2-x1)*(y2-y1) - a) );

	return a;
}

double XYRectCommon(double x,double y,double R,double x1,double x2,double y1,double y2,int &flag){
	double a;
	x1-=x;
	x2-=x;
	y1-=y;
	y2-=y;

	flag = UNDEF;

	if(ZP(x1) && ZP(y1)){
		a = posXYRectCommon(R,x1,x2,y1,y2,flag);
	}
	else if(ZP(x1)){		//y1 < 0
		a = posXYRectCommon(R,x1,x2,0, y2,flag);
		a+= posXYRectCommon(R,x1,x2,0,-y1,flag);
	}
	else if(ZP(y1)){		//x1 < 0
		a = posXYRectCommon(R,0, x2,y1,y2,flag);
		a+= posXYRectCommon(R,0,-x1,y1,y2,flag);
	}
	else{			//x1 < 0 && y1 < 0
		a = posXYRectCommon(R,0, x2,0, y2,flag);
		a+= posXYRectCommon(R,0, x2,0,-y1,flag);
		a+= posXYRectCommon(R,0,-x1,0, y2,flag);
		a+= posXYRectCommon(R,0,-x1,0,-y1,flag);
	}
	return a;
}

int main(){

	int flag;
	double x,y,R,x1,x2,y1,y2;

	while(scanf("%lf%lf%lf%lf%lf%lf%lf",&x,&y,&R,&x1,&y1,&x2,&y2)==7){
		printf("area = %.15lf\n",XYRectCommon(x,y,R,x1,x2,y1,y2,flag));
		printf("type = %d\n",flag);
	}

	return 0;
}