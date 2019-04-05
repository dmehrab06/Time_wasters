#include <bits/stdc++.h>
#define ll             long long
//#define pi             pair <int,int>
#define pl             pair <ll,ll>
#define ps             pair <string,string>
#define vi         vector <int>
#define vl             vector <ll>
#define vpi            vector <pi>
#define vpl            vector <pl>
#define st             string
#define vs             vector <st>
#define f(i,a,b)       for(ll i=(a);i<(b);i++)
#define fd(i,a,b)      for(ll i=(a);i>(b);i--)
#define Max(a,b)       ((a)>(b)?(a):(b))
#define Min(a,b)       ((a)<(b)?(a):(b))
#define x              first
#define y              second
#define si(a)          scanf("%d",&a)
#define sii(a,b)       scanf("%d %d",&a,&b)
#define siii(a,b,c)    scanf("%d %d %d",&a,&b,&c)
#define sl(a)          scanf("%lld",&a)
#define sll(a,b)       scanf("%lld %lld",&a,&b)
#define slll(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c);
#define pf             printf
#define pfi(n)         printf("%d\n",n)
#define pfl(n)         printf("%lld\n",n)
#define pfls(n)        printf("%lld ",n)
#define pfci(n,ans)    printf("Case %lld: %d\n",n,ans)
#define pfcl(n,ans)    printf("Case %lld: %lld\n",n,ans)
#define pfcd(n,ans)    printf("Case %lld: %lf\n",n,ans)
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define mem(a,v)       memset(a,v,sizeof(a))
#define INF 1e18
#define MAX 30007
#define MOD 1000000007
#define LG  16
#define mid ((l+r)/2)
using namespace std; 

typedef pair<int,int> pii;  
const double pi = 4 * atan(1);  
const double eps = 1e-12;  
 
inline int dcmp (double x) { if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }  
inline double getDistance (double x, double y) { return sqrt(x * x + y * y); }  
inline double torad(double deg) { return deg / 180 * pi; }  
 
struct Point {  
    double x, y;  
    Point (double x = 0, double y = 0): x(x), y(y) {}  
    void read () { scanf("%lf%lf", &x, &y); }  
    void write () { printf("%lf %lf", x, y); }  
 
    bool operator == (const Point& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }  
    bool operator != (const Point& u) const { return !(*this == u); }  
    bool operator < (const Point& u) const { return dcmp(x - u.x) < 0 || (dcmp(x-u.x)==0 && dcmp(y-u.y) < 0); }  
    bool operator > (const Point& u) const { return u < *this; }  
    bool operator <= (const Point& u) const { return *this < u || *this == u; }  
    bool operator >= (const Point& u) const { return *this > u || *this == u; }  
    Point operator + (const Point& u) { return Point(x + u.x, y + u.y); }  
    Point operator - (const Point& u) { return Point(x - u.x, y - u.y); }  
    Point operator * (const double u) { return Point(x * u, y * u); }  
    Point operator / (const double u) { return Point(x / u, y / u); }  
    double operator * (const Point& u) { return x*u.y - y*u.x; }  
};  
typedef Point Vector;  
typedef vector<Point> Polygon;  
 
struct DirLine {  
    Point p;  
    Vector v;  
    double ang;  
    DirLine () {}  
    DirLine (Point p, Vector v): p(p), v(v) { ang = atan2(v.y, v.x); }  
    bool operator < (const DirLine& u) const { return ang < u.ang; }  
};  
 
double getDot (Vector a, Vector b) { return a.x * b.x + a.y * b.y; }  
double getCross (Vector a, Vector b) { return a.x * b.y - a.y * b.x; }  
double getLength (Vector a) { return sqrt(getDot(a, a)); }  
double getPLength (Vector a) { return getDot(a, a); }  
double getAngle (Vector u) { return atan2(u.y, u.x); }  
double getAngle (Vector a, Vector b) { return acos(getDot(a, b) / getLength(a) / getLength(b)); }  
Vector rotate (Vector a, double rad) { return Vector(a.x*cos(rad)-a.y*sin(rad), a.x*sin(rad)+a.y*cos(rad)); }   
Vector getNormal (Vector a) { double l = getLength(a); return Vector(-a.y/l, a.x/l); }  

bool getIntersection (Point p, Vector v, Point q, Vector w, Point& o) {  
    if (dcmp(getCross(v, w)) == 0) return false;  
    Vector u = p - q;  
    double k = getCross(w, u) / getCross(v, w);  
    o = p + v * k;  
    return true;  
}  

bool onLeft(DirLine l, Point p) { return dcmp(l.v * (p-l.p)) >= 0; }  

int halfPlaneIntersection(DirLine* li, int n, Point* poly) {  
    sort(li, li + n);  

    int first, last;  
    Point* p = new Point[n];  
    DirLine* q = new DirLine[n];  
    q[first=last=0] = li[0];  

    for (int i = 1; i < n; i++) {  
        while (first < last && !onLeft(li[i], p[last-1])) last--;  
        while (first < last && !onLeft(li[i], p[first])) first++;  
        q[++last] = li[i];  

        if (dcmp(q[last].v * q[last-1].v) == 0) {  
            last--;  
            if (onLeft(q[last], li[i].p)) q[last] = li[i];  
        }  

        if (first < last)  
            getIntersection(q[last-1].p, q[last-1].v, q[last].p, q[last].v, p[last-1]);  
    }  

    while (first < last && !onLeft(q[first], p[last-1])) last--;  
    if (last - first <= 1) { delete [] p; delete [] q; return 0; }  
    getIntersection(q[last].p, q[last].v, q[first].p, q[first].v, p[last]);  

    int m = 0;  
    for (int i = first; i <= last; i++) poly[m++] = p[i];  
    delete [] p; delete [] q;  
    return m;  
}  

Point pts[MAX],  poly[MAX];
DirLine dir[MAX], tmp[MAX];
Vector nrm[MAX];

int get(double sh,int n){
	f(i,0,n){
		tmp[i]=dir[i];
		tmp[i].p=tmp[i].p+nrm[i]*sh;
	}
	return halfPlaneIntersection(tmp, n, poly);
}
int main(){
	while(1){
		int N;
		cin>>N;
		if(!N) break;
		f(i,0,N){
			pts[i].read();
		}
		//reverse(pts,pts+N);
		f(i,0,N){
			dir[i]=DirLine(pts[i],pts[(i+1)%N]-pts[i]);
			nrm[i]=getNormal(pts[(i+1)%N]-pts[i]);
			nrm[i]=nrm[i]/getLength(nrm[i]);
		}
		double l=0, r=100000.0;
		f(i,0,100){
			if(!get(mid,N)) r=mid;
			else l=mid;
		}
		//cout<<mid<<endl;
		pf("%.8lf\n",mid);
	}
}

