/********   convex hull + vector by Shadman **********/
#include <bits/stdc++.h>
#define Vector Point
using namespace std;
//fstream in,out;
const int maxn=2405;
const double PI=acos(-1);
double torad(double deg)
{
    return deg/180*PI;
}
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};

bool operator < (const Point &a,const Point &b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
Vector operator +(Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator -(Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);}
double Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}
int ConvexHull(Point *p,int n,Point *ch)
{
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++)
    {
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)
            m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)
            m--;
        ch[m++]=p[i];
    }
    if(n>1)
        m--;
    return m;
}
Vector Rotate(Vector A,double rad)//旋转
{
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
double PolyonArea(Point* p,int n)//多边形面积
{
    double area=0;
    for(int i=1;i<n-1;i++)
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    double p,q;
    Point P[maxn],ch[maxn];
    cin>>t;
    while(t--)
    {
        int pc=0;
        double x,y,w,h,j,ang,board,hull;
        board=hull=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y>>w>>h>>j;
            Point o(x,y);
            ang=-torad(j);
            P[pc++]=o+Rotate(Vector(-w/2,-h/2),ang);
            P[pc++]=o+Rotate(Vector(w/2,-h/2),ang);
            P[pc++]=o+Rotate(Vector(-w/2,h/2),ang);
            P[pc++]=o+Rotate(Vector(w/2,h/2),ang);
            board+=w*h;
        }
        int m=ConvexHull(P,pc,ch);
        hull=PolyonArea(ch,m);
        cout<<hull<<" "<<board<<endl;
        cout<<fixed<<setprecision(1)<<board*100/hull<<" %"<<endl;
    }
    return 0;
}
