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
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define PI acos(-1.0)
using namespace std;

struct P3D
{
    double x, y, z;
    double len;
    P3D(double _x=0.0, double _y=0.0, double _z=0.0){
        x=_x;
        y=_y;
        z=_z;
        len=sqrt(x*x+y*y+z*z);
    }
};

P3D add(P3D a, P3D b){
    P3D res(a.x+b.x,a.y+b.y,a.z+b.z);
    return res;
}
P3D sub(P3D a, P3D b){
    P3D res(a.x-b.x,a.y-b.y,a.z-b.z);
    return res;
}

double dprod(P3D a, P3D b){
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

P3D Xprod(P3D a, P3D b){
    P3D res(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
    return res;
}

double sq(double x){
    return x*x;
}

double area(P3D A, P3D B, P3D C){
    P3D AB=sub(B,A);
    P3D AC=sub(C,A);
    double x1=AB.x;
    double x2=AB.y;
    double x3=AB.z;
    double y1=AC.x;
    double y2=AC.y;
    double y3=AC.z;
    double oka=sq(x2*y3-x3*y2)+sq(x3*y1-x1*y3)+sq(x1*y2-x2*y1);
    oka=sqrt(oka);
    return oka/2.0;
}


bool isinside(P3D A,P3D B,P3D C,P3D P){
    double a1=area(P,A,B);
    double a2=area(P,B,C);
    double a3=area(P,C,A);
    double asol=area(A,B,C);
    double tmp=a1+a2+a3;
    if(fabs(tmp-asol)<eps){
        return true;
    }
    return false;
}

//credit for raytri function idea
//geomalgorithms.com
//this is another
//previous didnt work, why? :/ must be some corner case

bool raytri(P3D R0, P3D R1,P3D V0, P3D V1, P3D V2)
{
    P3D n = Xprod(sub(V1,V0), sub(V2,V0));
    double dd=dprod(n, sub(R1,R0));
    if(fabs(dd)<eps) return false;

    double m = dprod(n,sub(V0,R0));
    double t = m / dd;
    if(t < 0.0 || (t-1.00) > 0.0) return false;
    P3D ray=sub(R1,R0);
    P3D nray(t*ray.x,t*ray.y,t*ray.z);
    P3D I=add(nray,R0);
    return isinside(V0, V1, V2,I);
}

P3D T1[5];
P3D T2[5];

bool tritri()
{
    for(int i = 0; i < 3; i++)
    {
        if(raytri(T2[i], T2[(i+1)%3],T1[0], T1[1], T1[2])) return true;
    }
    for(int i = 0; i < 3; i++)
    {
        if(raytri(T2[(i+1)%3], T2[i],T1[0], T1[1], T1[2])) return true;
    }
    for(int i = 0; i < 3; i++)
    {
        if(raytri(T1[i], T1[(i+1)%3],T2[0], T2[1], T2[2])) return true;
    }
    for(int i = 0; i < 3; i++)
    {
        if(raytri(T1[(i+1)%3], T1[i],T2[0], T2[1], T2[2])) return true;
    }
    return false;
}


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        double x,y,z;
        for(int i=1;i<=3;++i){
            scanf("%lf %lf %lf",&x,&y,&z);
            P3D pp(x,y,z);
            T1[i-1]=pp;
        }
        for(int i=1;i<=3;++i){
            scanf("%lf %lf %lf",&x,&y,&z);
            P3D pp(x,y,z);
            T2[i-1]=pp;
        }
        if(tritri()){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
