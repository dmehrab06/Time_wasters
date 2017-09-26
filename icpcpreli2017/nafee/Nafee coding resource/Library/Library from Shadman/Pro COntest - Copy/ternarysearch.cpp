#include <bits/stdc++.h>
using namespace std;
double a1,a2,b1,b2,c1,c2,d1,d2,x,y,x1,y2;
double ep=1e-9;
double dis(double x2)
{
    double ax,ay,bx,by;
    ax=a1+x*x2;
    ay=a2+y*x2;
    bx=c1+x1*x2;
    by=c2+y2*x2;

    return sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
}
int cmp(double p,double q)
{
    if(p<=q+ep)return -1;
    else if(p+ep<q)return 0;
    else
        return 1;
}
int main()
{
    int a,b,c,d,e,i,j,p,q;
    double z,z1,lo=0.0,hi=1.0;
    cin>>a;
    for(i=1;i<=a;i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&a1,&a2,&b1,&b2,&c1,&c2,&d1,&d2);
        lo=0.0;
        hi=1.0;
        x=b1-a1;
        y=b2-a2;
        x1=d1-c1;
        y2=d2-c2;

        while(cmp(hi,lo)==1)
        {
            z=(lo*2.0+hi)/3;
            z1=(lo+2.0*hi)/3;
            if(cmp(dis(z),dis(z1))==-1){

                    hi=z1;


            }
            else
                {
                    lo=z;

                }

        }

        printf("Case %d: %.10lf\n",i,dis(lo));


    }
    return 0;

}
