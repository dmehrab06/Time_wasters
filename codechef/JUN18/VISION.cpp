/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 1e-12
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

typedef pair<int,int> pii;
const double pi = 4 * atan(1);
//const double eps = 1e-12;

inline int dcmp (double x) { if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }
inline double getDistance (double x, double y) { return sqrt(x * x + y * y); }
inline double torad(double deg) { return deg / 180 * pi; }

struct Point {
    double x, y,z;
    Point (double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}
    void read () { scanf("%lf%lf%lf", &x, &y,&z); }
    void write () { printf("%lf %lf %lf", x, y,z); }

    bool operator == (const Point& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0 && dcmp(z - u.z) == 0; }
    bool operator != (const Point& u) const { return !(*this == u); }
    bool operator < (const Point& u) const { return dcmp(x - u.x) < 0 || ((dcmp(x-u.x)==0 && dcmp(y-u.y) < 0)) || ((dcmp(x-u.x)==0 && dcmp(y-u.y)==0 && dcmp(z-u.z)<0)); }
    bool operator > (const Point& u) const { return u < *this; }
    bool operator <= (const Point& u) const { return *this < u || *this == u; }
    bool operator >= (const Point& u) const { return *this > u || *this == u; }
    Point operator + (const Point& u) { return Point(x + u.x, y + u.y, z+u.z); }
    Point operator - (const Point& u) { return Point(x - u.x, y - u.y, z-u.z); }
    Point operator * (const double u) { return Point(x * u, y * u, z*u); }
    Point operator / (const double u) { return Point(x / u, y / u, z/u); }
    //double operator * (const Point& u) { return x*u.y - y*u.x; }
};

typedef Point Vector;
typedef vector<Point> Polygon;

struct DirLine {
    Point p;
    Vector v;
    //double ang;
    DirLine () {}
    DirLine (Point p, Vector v): p(p), v(v) {}
    Point getpoint(double d){return p+v*d;}
    //bool operator < (const DirLine& u) const { return ang < u.ang; }
};

double getDot (Vector a, Vector b) { return a.x * b.x + a.y * b.y + a.z*b.z; }
//double getCross (Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
double getLength (Vector a) { return sqrt(getDot(a, a)); }
double getPLength (Vector a) { return getDot(a, a); }
//double getAngle (Vector u) { return atan2(u.y, u.x); }
double getAngle (Vector a, Vector b) { return acos(getDot(a, b) / getLength(a) / getLength(b)); }
//Vector rotate (Vector a, double rad) { return Vector(a.x*cos(rad)-a.y*sin(rad), a.x*sin(rad)+a.y*cos(rad)); }
//Vector getNormal (Vector a) { double l = getLength(a); return Vector(-a.y/l, a.x/l); }
Vector normalize (Vector a) { double l = getLength(a); return Vector(a.x/l,a.y/l,a.z/l);}

bool isIntersect(Point C, Point O, Point l, double r){
    Point OC = O-C;
    double aa = getDot(l,OC); double a = aa*aa; double b = getDot(OC,OC);
    double v = a-b+(r*r);
    return (v>0);
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        Point P, Q, d, C; double R;
        P.read(); Q.read(); d.read(); C.read(); scanf("%lf",&R);
        //Vector PQV = Q-P; PQV = getNormal(PQV); DirLine PQ(P,PQV);
        DirLine Qline(Q,d);
        double lo = 0.0, hi = 1e10;
        FREP(it,1,100){
            double mid = (lo+hi)/2.0;
            Point curQ = Qline.getpoint(mid);
            Vector PQV = curQ-P; PQV = normalize(PQV);
            if(isIntersect(C,P,PQV,R)){
                lo = mid;
            }
            else{
                hi = mid;
            }
        }
        Point curQ = Qline.getpoint(lo);
        if(!isIntersect(C,P,(normalize(curQ-P)),R)){printf("%.10lf\n",lo);}
        else printf("%.10lf\n",hi);
    }
    return 0;

}
