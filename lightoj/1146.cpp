/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
//#include <dirent.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
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
//using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

double dis(PDD p1, PDD p2){
    double dx = p1.first-p2.first;
    double dy = p2.second-p1.second;
    return sqrt(dx*dx+dy*dy);
}

struct line{
    PDD startpoint;
    PDD dir;
    line(PDD p1, PDD p2){
        startpoint = p1;
        dir.first = p2.first-p1.first;
        dir.second = p2.second-p1.second;
    }
    PDD getpoint(double t){
        PDD gopoint;
        gopoint.first = startpoint.first+t*dir.first;
        gopoint.second = startpoint.second+t*dir.second;
        return gopoint;
    }
    void print(){
        cout<<"line start : "<<startpoint.first<<" "<<startpoint.second<<"\n";
        cout<<"line end : "<<startpoint.first+dir.first<<" "<<startpoint.second+dir.second<<"\n";
    }
};

double disattime(double t, line l1, line l2){
    PDD p1 = l1.getpoint(t);
    PDD p2 = l2.getpoint(t);
    return dis(p1,p2);
}

double tersearch(line l1, line l2){
    double lo = 0.0;
    double hi = 1.0;
    FREP(i,0,100){
        double mid = (lo+hi)/2.0;
        double midmid = (mid+hi)/2.0;
        double valmid = disattime(mid,l1,l2);
        double valmidmid = disattime(midmid,l1,l2);
        if(valmid<valmidmid){
            hi = midmid;
        }
        else{
            lo = mid;
        }
    }
    return disattime(lo,l1,l2);
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        double Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&Ax,&Ay,&Bx,&By,&Cx,&Cy,&Dx,&Dy);
        PDD pA = make_pair(Ax,Ay); PDD pB = make_pair(Bx,By); line l1(pA,pB);
        PDD pC = make_pair(Cx,Cy); PDD pD = make_pair(Dx,Dy); line l2(pC,pD);
        printf("Case %d: %.10lf\n",cs,tersearch(l1,l2));
    }
    return 0;
}
