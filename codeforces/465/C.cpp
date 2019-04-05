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
#define eps 0.00000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
#define MDD 1000000007
#define PI acos(-1.0)
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;


double getdis(PDD p1, PDD p2){
    double xx = p1.first-p2.first;
    double yy = p1.second-p2.second;
    return sqrt(xx*xx+yy*yy);
}

double getarea(double x, double y, double dx, double dy, double terx, double tery, double t, double x2, double y2){
    double xnw = x+t*dx;
    double ynw = y+t*dy;
    double rrhere = min(getdis(make_pair(terx,tery),make_pair(xnw,ynw)),getdis(make_pair(x2,y2),make_pair(xnw,ynw)));
    return PI*rrhere*rrhere;
}

pair< double , PDD > getradii(double x, double y, double dx, double dy, double terx, double tery, double t, double x2, double y2){
    double xnw = x+t*dx;
    double ynw = y+t*dy;
    double rrhere = min(getdis(make_pair(terx,tery),make_pair(xnw,ynw)),getdis(make_pair(x2,y2),make_pair(xnw,ynw)));
    return make_pair(rrhere,make_pair(xnw,ynw));
}

pair< double , PDD > tersearch(double x, double y, double dx, double dy, double thi, double x2, double y2){
    double lo = 0.0;
    double hi = thi;
    double terminalx = x+hi*dx;
    double terminaly = y+hi*dy;
    FREP(i,1,1000){
        double midt = (lo+hi)/2.0;
        double ar1 = getarea(x,y,dx,dy,terminalx,terminaly,midt,x2,y2);
        double ar2 = getarea(x,y,dx,dy,terminalx,terminaly,midt+eps,x2,y2);
        double ar3 = getarea(x,y,dx,dy,terminalx,terminaly,midt-eps,x2,y2);
        if(ar2>ar1){
            lo = midt;
        }
        else if(ar3>ar1){
            hi = midt;
        }
    }
    return getradii(x,y,dx,dy,terminalx,terminaly,lo,x2,y2);
}

int main(){
    double R,x1,y1,x2,y2;
    scanf("%lf %lf %lf %lf %lf",&R,&x1,&y1,&x2,&y2);
    if(fabs(x1-x2)<eps && fabs(y1-y2)<eps){
        printf("%.10lf %.10lf %.10lf\n",x1+R/2.0,y1,R/2.0);
        return 0;
    }
    double x = x1; double dx = x1-x2;
    double y = y1; double dy = y1-y2;
    double dd = getdis(make_pair(x1,y1),make_pair(x2,y2));
    double thi = R/dd; //dd == 0 hoile ki korbo dekhte hobe
    pair<double,PDD>ans = tersearch(x,y,dx,dy,thi,x2,y2);
    printf("%.10lf %.10lf %.10lf\n",ans.second.first,ans.second.second,ans.first);
}
