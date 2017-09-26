#define ERR 0.00000001
#include <stdio.h>
#include <math.h>
double bin_search(double low,double high,double area,double AB){
    double mid=(low+high)/2.0;
    double comp=((mid)/(AB));
    comp=comp*comp;
    if(fabs(comp-area)<=ERR){
        return mid;
    }
    if(comp<area){
        return bin_search(mid,high,area,AB);
    }
    else{
        return bin_search(low,mid,area,AB);
    }
 
}
int main(){
    double AB,AC,BC,ratio;
    int t;
    int tt=1;
    scanf("%d",&t);
    while(t--){
        scanf("%lf %lf %lf %lf",&AB,&AC,&BC,&ratio);
        double newratio;
        newratio=(ratio)/(ratio+1.0);
        double result;
        result=bin_search(0,AB,newratio,AB);
        printf("Case %d: %.10lf\n",tt,result);
        tt++;
    }
    return 0
}
