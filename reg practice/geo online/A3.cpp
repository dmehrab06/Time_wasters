#include <cstdio>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <cstdlib>
#include <ctime>
using namespace std;

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
typedef long long ll;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
struct Point    {
    double x, y;
    Point (double x=0, double y=0) : x (x), y (y) {}
};
typedef Point Vector;
double dot(Vector A, Vector B)  {
    return A.x * B.x + A.y * B.y;
}
double cross(Vector A, Vector B)    {
    return A.x * B.y - A.y * B.x;
}
int dcmp(double x)  {
    if (fabs (x) < EPS) return 0;
    else    return x < 0 ? -1 : 1;
}
Vector operator + (Vector A, Vector B)  {
    return Vector (A.x + B.x, A.y + B.y);
}
Vector operator - (Vector A, Vector B)  {
    return Vector (A.x - B.x, A.y - B.y);
}
Vector operator * (Vector A, double p)  {
    return Vector (A.x * p, A.y * p);
}
double length(Vector A) {
    return sqrt (dot (A, A));
}
double angle(Vector A, Vector B)    {
    return acos (dot (A, B) / length (A) / length (B));
}
Vector rotate(Vector A, double rad) {
    return Vector (A.x * cos (rad) - A.y * sin (rad), A.x * sin (rad) + A.y * cos (rad));
}
Point point_inter(Point p, Vector V, Point q, Vector W)    {
    Vector U = p - q;
    double t = cross (W, U) / cross (V, W);
    return p + V * t;
}

Point solve(Point a, Point b, Point c)  {
    Vector V1 = c - b;
    double r1 = angle (a - b, V1);
    //cout<<r1<<" ";
    V1 = rotate (V1, r1 / 3);
    Vector V2 = b - c;
    double r2 = angle (a - c,  V2);
    //cout<<r2<<"\n";
    V2 = rotate (V2, -r2 / 3);
    return point_inter (b, V1, c, V2);
}

int main(void)    {
    int T;  scanf ("%d", &T);
    Point a, b, c, d, e, f;
    while (T--) {
        scanf ("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
       // cout<<"in d\n";
        d = solve (a, b, c);
       // cout<<"in e\n";
        e = solve (b, c, a);
       // cout<<"in f\n";
        f = solve (c, a, b);
        printf ("%.6f %.6f %.6f %.6f %.6f %.6f\n", d.x, d.y, e.x, e.y, f.x, f.y);
    }

    return 0;
}
