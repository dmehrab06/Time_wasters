#include <stdio.h>
#include <math.h>
 
int main(){
    int t;
    double pi=acos(-1.0);
    scanf("%d",&t);
    int tt=1;
    double R;
    int n;
    while(t--){
        scanf("%lf %d",&R,&n);
        double tempn;
        tempn=n;
        double ang;
        ang=sin(pi/tempn);
        double new;
        new=R*(ang);
        double new2;
        new2=1+ang;
        double r;
        r=new/new2;
        printf("Case %d: %.10lf\n",tt,r);
        tt++;
 
    }
    return 0;
}
