#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
using namespace std;

double cf[15];

double solve(double IRR, int T){
    double hor=1.00;
    double sum=0.00;
    FREP(i,0,T){
        sum+=(cf[i]/hor);
        hor*=(1.0+IRR);
    }
    return sum;
}

double bs(double lo, double hi, int T){
    FREP(i,1,1000){
        double mid=(lo+hi)/(2.0);
        double val=solve(mid,T);
        double lval=solve(lo,T);
      //  double rval=solve(hi,T);
        if(fabs(val)<eps)return mid;
        else{
            if((val*lval)<0){
                hi=mid;
            }
            else{
                lo=mid;
            }
        }
    }
   // printf("ekhan theke\n");
    return hi;
}

int main(){
    int t;
    while(scanf("%d",&t)==1 && t){
        FREP(i,0,t){
            scanf("%lf",&cf[i]);
        }
        double ans=bs(-0.99999,1000000.00,t);
        printf("%.3lf\n",ans);
    }
    return 0;
}
