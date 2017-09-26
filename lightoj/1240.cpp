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

struct pt3d{
    double x,y,z;
    pt3d(double _x = 0.0, double _y=0.0, double _z=0.0){
        x = _x; y = _y;z = _z;
    }
    double dis(pt3d p){
        double dx = p.x-x; double dy = p.y-y; double dz = p.z-z;
        return sqrt(dx*dx+dy*dy+dz*dz);
    }
};

pt3d sub(pt3d a, pt3d b){
    return pt3d(a.x-b.x,a.y-b.y,a.z-b.z);
}

pt3d add(pt3d a, pt3d b, double t){
    return pt3d(a.x+t*b.x,a.y+t*b.y,a.z+t*b.z);
}

struct line{
    pt3d startpoint;
    pt3d dir;
    line(pt3d p1, pt3d p2){
        startpoint = p1;
        dir = sub(p2,p1);
    }
    pt3d getpoint(double t){
        return add(startpoint,dir,t);
    }
    /*void print(){
        cout<<"line start : "<<startpoint.first<<" "<<startpoint.second<<"\n";
        cout<<"line end : "<<startpoint.first+dir.first<<" "<<startpoint.second+dir.second<<"\n";
    }*/
};

double disattime(double t, line l, pt3d p){
    pt3d p1 = l.getpoint(t);
    return p.dis(p1);
}

double tersearch(line l, pt3d p){
    double lo = 0.0;
    double hi = 1.0;
    FREP(i,0,100){
        double mid = (lo+hi)/2.0;
        double midmid = (mid+hi)/2.0;
        double valmid = disattime(mid,l,p);
        double valmidmid = disattime(midmid,l,p);
        if(valmid<valmidmid){
            hi = midmid;
        }
        else{
            lo = mid;
        }
    }
    return disattime(lo,l,p);
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        double Ax,Ay,Az,Bx,By,Bz,Px,Py,Pz;
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",&Ax,&Ay,&Az,&Bx,&By,&Bz,&Px,&Py,&Pz);
        pt3d pA(Ax,Ay,Az); pt3d pB(Bx,By,Bz);; line l(pA,pB);
        pt3d P(Px,Py,Pz);
        printf("Case %d: %.10lf\n",cs,tersearch(l,P));
    }
    return 0;
}
