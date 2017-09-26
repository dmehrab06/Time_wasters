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
#define eps 0.00000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
template <typename T> class Vector2D
{
private:
    T x;
    T y;

public:
    explicit Vector2D(const T& x=0, const T& y=0) : x(x), y(y) {}
    Vector2D(const Vector2D<T>& src) : x(src.x), y(src.y) {}
    virtual ~Vector2D() {}

    // Accessors
    inline T X() const { return x; }
    inline T Y() const { return y; }
    inline T X(const T& x) { this->x = x; }
    inline T Y(const T& y) { this->y = y; }

    // Vector arithmetic
    inline Vector2D<T> operator-() const
        { return Vector2D<T>(-x, -y); }

    inline Vector2D<T> operator+() const
        { return Vector2D<T>(+x, +y); }

    inline Vector2D<T> operator+(const Vector2D<T>& v) const
        { return Vector2D<T>(x+v.x, y+v.y); }

    inline Vector2D<T> operator-(const Vector2D<T>& v) const
        { return Vector2D<T>(x-v.x, y-v.y); }

    inline Vector2D<T> operator*(const T& s) const
        { return Vector2D<T>(x*s, y*s); }

    // Dot product
    inline T operator*(const Vector2D<T>& v) const
        { return x*v.x + y*v.y; }

    // l-2 norm
    inline T norm() const { return sqrt(x*x + y*y); }

    // inner angle (radians)
    static T angle(const Vector2D<T>& v1, const Vector2D<T>& v2)
    {
        return acos( (v1 * v2) / (v1.norm() * v2.norm()) );
    }
};

int main()
{
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int p,x,y;
        scanf("%d %d %d",&p,&x,&y);
        int val=x*x+y*y-100*x-100*y+2500;
        printf("Case #%d: ",cs++);
        if(val>0 || p==0){
            printf("white\n");
            continue;
        }
        Vector2D<double> p1(50, 50);
        Vector2D<double> p2(50, 100);
        Vector2D<double> p3(x, y);
        double rad = Vector2D<double>::angle(p3-p1, p2-p1);
        double deg = rad * 180.0 / M_PI;
        if(x<50)deg=360.0-deg;
        double needdeg=((double)p*360.0)/100.0;
       // cout<<deg<<" "<<needdeg<<"\n";
        if(fabs(deg-needdeg)<eps || deg<needdeg){
            printf("black\n");
        }
        else{
            printf("white\n");
        }
    }
    return 0;
}
