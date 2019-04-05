/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
#define PLLI pair<LLI,LLI>
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

long long int ys[1000006];
long long int xs[1000006];

int main(){
    int n;
    scanf("%d",&n);
    int xsz = 0, ysz = 0;
    FREP(i,1,n){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==0)ys[ysz++]=y;
        else if(y==0)xs[xsz++]=x;
    }
    sort(xs,xs+xsz);sort(ys,ys+ysz);
    double mxdis = 0;
    FREP(xx,0,xsz-1){
        double dis1 = fabs(xs[xx]-xs[0]); double dis2 = fabs(xs[xx]-xs[xsz-1]);
        mxdis = max(mxdis,max(dis1,dis2));
        double dis3 = sqrt(xs[xx]*xs[xx]+ys[0]*ys[0]);
        double dis4 = sqrt(xs[xx]*xs[xx]+ys[ysz-1]*ys[ysz-1]);
        mxdis = max(mxdis,max(dis3,dis4));
    }
    FREP(yy,0,ysz-1){
        double dis1 = fabs(ys[yy]-ys[0]); double dis2 = fabs(ys[yy]-ys[ysz-1]);
        mxdis = max(mxdis,max(dis1,dis2));
        double dis3 = sqrt(ys[yy]*ys[yy]+xs[0]*xs[0]);
        double dis4 = sqrt(ys[yy]*ys[yy]+xs[xsz-1]*xs[xsz-1]);
        mxdis = max(mxdis,max(dis3,dis4));
    }
    printf("%.10lf\n",mxdis);
}
