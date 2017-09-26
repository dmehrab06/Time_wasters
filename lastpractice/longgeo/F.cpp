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
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

struct pt3d{
    double x,y,z;
    pt3d(double _x=0.0, double _y=0.0, double _z=0.0){
        x=_x; y=_y; z=_z;
    }
    void print(){
        cout<<x<<","<<y<<","<<z<<"\n";
    }
};

struct line{
    pt3d startpoint;
    pt3d dir;
    line(pt3d p1, pt3d p2){
        startpoint = p1;
        dir.x = p2.x-p1.x;
        dir.y = p2.y-p1.y;
        dir.z = p2.z-p1.z;
    }
    void normalizedir(){
        double sm = dir.x*dir.x+dir.y*dir.y;
        sm = sqrt(sm);
        dir.x/=sm; dir.y/=sm; dir.z/=sm;
    }
    pt3d getpoint(double t){
        pt3d gopoint;
        gopoint.x = startpoint.x+t*dir.x;
        gopoint.y = startpoint.y+t*dir.y;
        gopoint.z = 0.0;
        return gopoint;
    }
    pt3d getendp(){
        return getpoint(1.0);
    }
    pt3d planexyintersect(){
        double t = -(startpoint.z)/(dir.z);
        return getpoint(t);
    }
    void print(){
        cout<<"line start : "<<startpoint.x<<" "<<startpoint.y<<" "<<startpoint.z<<"\n";
    }
};

pt3d allpt[10004];

double volume(double rad, double h){
    return (1.0/3.0)*rad*rad*h;
}

double getdis(pt3d a, pt3d b){
    double dx = a.x-b.x;
    double dy = a.y-b.y;
    double dz = a.z-b.z;
    return sqrt(dx*dx+dy*dy+dz*dz);
}

double getradii(double h, int n){
    pt3d st(0.0,0.0,h);
    double mxrad = 0.0;
    FREP(i,1,n){
        line l(st,allpt[i]);
        pt3d xy = l.planexyintersect();
        double r = getdis(pt3d(0.0,0.0,0.0),xy);
        mxrad = max(r,mxrad);
    }
    return mxrad;
}

double getvol(double h, int n){
    double r = getradii(h,n);
    return volume(r,h);
}

double tersearch(double mxh, int n){
    double lo = mxh+eps; double hi = 1e40;
    while(fabs(hi-lo)>eps){
        double m1 = (lo+hi)/2.0; double v1 = getvol(m1,n);
        double m2 = (lo+m1)/2.0; double v2 = getvol(m2,n);
        if(v1>v2){
            hi = m1;
        }
        else{
            lo = m2;
        }
    }
    return lo;
}

PDD getans(double mxh, int n){
    double h = tersearch(mxh,n);
    double r = getradii(h,n);
    return make_pair(h,r);
}

int main() {
    int n;
    while(scanf("%d",&n)==1){
        double mxz = -1.0;
        FREP(i,1,n){
            double x,y,z;
            scanf("%lf %lf %lf",&x,&y,&z);
            pt3d p(x,y,z); allpt[i]=p;
            mxz = max(mxz,z);
        }
        PDD ans = getans(mxz,n);
        printf("%.3lf %.3lf\n",ans.first,ans.second);
    }

	return 0;
}
