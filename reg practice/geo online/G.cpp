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

//typedef Point3 Vector3;

P3D add(P3D &a, P3D &b){
    P3D res(a.x+b.x,a.y+b.y,a.z+b.z);
    return res;
}
P3D sub(P3D &a, P3D &b){
    P3D res(a.x-b.x,a.y-b.y,a.z-b.z);
    return res;
}

double dprod(P3D &a, P3D &b){
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

P3D Xprod(P3D &a, P3D &b){
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

//double Area2(Point3 A, Point3 B, Point3 C) { return Length(Cross(B-A, C-A)); }


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

//credit for raytri function
//geomalgorithms.com barycentric coordinate computation

// intersect3D_RayTriangle(): find the 3D intersection of a ray with a triangle
//    Input:  a ray R, and a triangle T
//    Output: *I = intersection point (when it exists)
//    Return: -1 = triangle is degenerate (a segment or point)
//             0 =  disjoint (no intersect)
//             1 =  intersect in unique point I1
//             2 =  are in the same plane

bool raytri(P3D R0, P3D R1, P3D T0, P3D T1, P3D T2)
{
    P3D    u, v, n;              // triangle vectors
    P3D    dir, w0, w;           // ray vectors
    double     r, a, b;              // params to calc ray-plane intersect

    // get triangle edge vectors and plane normal
    u = sub(T1,T0);
    v = sub(T2,T0);
    n = Xprod(u,v);              // cross product
    if (dprod(n,n)< eps)             // triangle is degenerate
        return false;                  // do not deal with this case

    dir = sub(R1,R0);              // ray direction vector
    w0 = sub(R0,T0);
    a = -dprod(n,w0);
    b = dprod(n,dir);
    if (fabs(b) < eps) {     // ray is  parallel to triangle plane
        if (fabs(a)< eps)                 // ray lies in triangle plane
            return true;
        else return false;              // ray disjoint from plane
    }

    // get intersect point of ray with triangle plane
    r = a / b;
    if (r < 0.0 || (r-1)>0.0)                    // ray goes away from triangle
        return false;                   // => no intersect
    // for a segment, also test if (r > 1.0) => no intersect
    P3D newdir(r*dir.x,r*dir.y,r*dir.z);
    P3D I = add(R0,newdir);            // intersect point of ray and plane
    return isinside(T0,T1,T2,I);
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
        if(raytri(T1[i], T1[(i+1)%3],T2[0], T2[1], T2[2])) return true;
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
