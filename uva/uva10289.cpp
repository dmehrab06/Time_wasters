#include<iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

double pi=acos(-1.0);

double degtorad(double deg){
    return (deg*pi)/180.0;
}

double t5val(double left, double right, double b){
    double t=(left+right)/2.0;
    double gx=t;
    double gy=t*(sqrt(3.0))/2.0;
    double ax=b;
    double ay=gy;
    double AG=ax-gx;
    if(AG<0.0){AG*=1.0;}
    double AB=AG/sqrt(3.0);
    double bx=b;
    double by=ay-AB;
    double dx=b;
    double dy=by+t;
    double cx=b-t*(sqrt(3.0)/2.0);
    double cy=(by+dy)/2.0;
    double cdslope=(dy-cy)/(dx-cx);
    double cdcut=(dx*cy-dy*cx)/(dx-cx);
    double fx=0;
    double fy=ay;
    double A=1.0+(cdslope*cdslope);
    double tempval=cdcut-fy;
    double B=2.0*cdslope*tempval-2.0*fx;
    double C=fx*fx+tempval*tempval-t*t;
    double Ex=sqrt(B*B-4.0*A*C)-B;
    Ex=Ex/(2.0*A);
    double Ey=cdslope*Ex+cdcut;
    double triheight=t*(sqrt(3.0)/2.0);
    double calside=Ey+triheight;
    if(fabs(calside-b)<0.0000000001){
        return t;
    }
    else{
        if(calside>b){
            return t5val(left,t-0.0000000001,b);
        }
        else{
            return t5val(t+0.0000000001,right,b);
        }
    }

}

int main()

{
    double t5factor=t5val(0.0,1.0,1.0);
    double sqrt3=sqrt(3.0);
    double sqrt2=sqrt(2.0);
        double b;
        while(scanf("%lf",&b)==1){
        double t2=(b*(sin(degtorad(45.0))))/(sin(degtorad(120.0)));
        double t1=b/(sin(degtorad(75.0)));
        double t3=b/(sqrt3*(1+sqrt2));
        t3=t3*2.0*sqrt2;
        double t4=(b*(sqrt3))/(1.0+sqrt3);
        double t6=b*(sqrt3+3.0)/9.0;
        double t8=b*(sqrt3+1.0)/(4.0+sqrt3);
        //double t5=0.554579157314857*b;
        double t5=b*t5factor;
        printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n",t1,t2,t3,t4,t5,t6,t8);
    }
    return 0;
}


