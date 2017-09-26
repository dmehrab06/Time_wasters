#include <stdio.h>
#include <math.h>
int main(){
    double r;
    int t;
    int i=1;
    double square;
    double pi=2*(acos(0.0));
    double sq;
    double area;
    scanf("%d",&t);
    while(t--){
        scanf("%lf",&r);
        sq=(4*r*r);
        area=(pi*r*r);
        area=sq-area;
        printf("Case %d: %.2lf\n",i,area);
        i++;
    }
    return 0;
}
