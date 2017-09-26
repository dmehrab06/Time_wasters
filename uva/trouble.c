#include<stdio.h>
#include<math.h>
double pi=acos(-1.0);
double degtorad(double deg){
    return (deg*pi)/180.0;
}
int main(){
    double AB;
    while(scanf("%lf",&AB)==1){
        double AC=AB*(sin(degtorad(108.0)))/(sin(degtorad(63.0)));
        printf("%.10lf\n",AC);
    }
    return 0;
}
