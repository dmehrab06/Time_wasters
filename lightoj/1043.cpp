#include <stdio.h>
#include <math.h>
int main(){
    double AB,AC,BC,ratio;
    int t;
    int tt=1;
    scanf("%d",&t);
    while(t--){
        scanf("%lf %lf %lf %lf",&AB,&AC,&BC,&ratio);
        double newratio;
        newratio=(ratio)/(ratio+1.0);
        double a;
        a=newratio*AB*AB;
        double result;
        result=sqrt(a);
        printf("Case %d: %.10lf\n",tt,result);
        tt++;
    }
    return 0;
}
