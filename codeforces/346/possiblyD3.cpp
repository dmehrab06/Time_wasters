#include <bits/stdc++.h>
#define PI (acos(-1.0))
#define TWOPI (2*PI)
#define eps 0.00000001
#define FALSE 0
#define TRUE 1
using namespace std;
struct Point
{
    double h;
    double v;
    Point(){
        h=0.0;
        v=0.0;
    }
    Point(double a,double b){
        h=a;
        v=b;
    }
};

Point polygon1[100005];
double Angle2D(double x1, double y1, double x2, double y2)
{
   double dtheta,theta1,theta2;

   theta1 = atan2(y1,x1);
   theta2 = atan2(y2,x2);
   dtheta = theta2 - theta1;
   while (dtheta > PI)
      dtheta -= TWOPI;
   while (dtheta < -PI)
      dtheta += TWOPI;

   return(dtheta);
}

int InsidePolygon(Point *polygon,int n,Point p)
{
   int i;
   double angle=0;
   Point p1,p2;

   for (i=0;i<n;i++) {
      p1.h = polygon[i].h - p.h;
      p1.v = polygon[i].v - p.v;
      p2.h = polygon[(i+1)%n].h - p.h;
      p2.v = polygon[(i+1)%n].v - p.v;
      angle += Angle2D(p1.h,p1.v,p2.h,p2.v);
   }

   if (fabs(angle) < PI)
      return(FALSE);
   else
      return(TRUE);
}

/*
   Return the angle between two vectors on a plane
   The angle is from vector 1 to vector 2, positive anticlockwise
   The result is between -pi -> pi
*/
/*double Angle2D(double x1, double y1, double x2, double y2)
{
   double dtheta,theta1,theta2;

   theta1 = atan2(y1,x1);
   theta2 = atan2(y2,x2);
   dtheta = theta2 - theta1;
   while (dtheta > PI)
      dtheta -= TWOPI;
   while (dtheta < -PI)
      dtheta += TWOPI;

   return(dtheta);
}
*/
int main()
{
   /* Point polygon1[] = {{0.0, 0.0},{0.0,1.0}, {1.0, 1.0}, {1.0, 2.0} ,{2.0, 2.0},{2.0,0.0}};
    int n = 6;
    Point p = {0.0, 1.5};
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";

    p = {1.5, 1.0};
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";
    p = {1.0, 2.5};
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";
    p = {2.5, 2.0};
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";
    p = {0.0, -0.5};
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";
    p = {-0.5, 0.0};
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";*/
    int n;
    cin>>n;
    for(int i=1;i<=(n+1);++i){
        int x,y;
        cin>>x>>y;
        double xx=x;
        double yy=y;
        Point p(xx,yy);
            polygon1[(i-1)]=p;
    }
    int c=0;
    for(int i=1;i<(n+1);++i){
        double curx,cury;
        Point prev=polygon1[i-1];
        Point cur=polygon1[i];
        if(fabs(cur.h-prev.h)<eps){
            curx=0.0;
            if(cur.v>prev.v){
                cury=0.2;
            }
            else{
                cury=-0.2;
            }
        }
        else if(fabs(cur.v-prev.v)<eps){
            cury=0.0;
            if(cur.h>prev.h){
                curx=0.2;
            }
            else{
                curx=-0.2;
            }
        }
        Point tocheck(cur.h+curx,cur.v+cury);
        //cout<<tocheck.h<<" "<<tocheck.v<<"\n";
        if(InsidePolygon(polygon1,n,tocheck)){
            c++;
          //  cout<<"yes\n";
        }
    }
    cout<<c<<"\n";
    return 0;
    //Point polygon2[] = {{0, 0}, {5, 5}, {5, 0}};
    //p = {3, 3};
    //n = sizeof(polygon2)/sizeof(polygon2[0]);
    //isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

    //p = {5, 1};
    //isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

    /*p = {8, 1};
    isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

    Point polygon3[] =  {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    p = {-1,10};
    n = sizeof(polygon3)/sizeof(polygon3[0]);
    isInside(polygon3, n, p)? cout << "Yes \n": cout << "No \n";
*/
    return 0;
}

