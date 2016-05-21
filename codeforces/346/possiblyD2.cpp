#include <bits/stdc++.h>
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define INSIDE 0
#define OUTSIDE 1
#define eps 0.00000001
using namespace std;

struct Point
{
    double x;
    double y;
    Point(){
        x=0.0;
        y=0.0;
    }
    Point(double a,double b){
        x=a;
        y=b;
    }
};

Point polygon1[10005];

int InsidePolygon(Point *polygon,int N,Point p)
{
  int counter = 0;
  int i;
  double xinters;
  Point p1,p2;

  p1 = polygon[0];
  for (i=1;i<=N;i++) {
    p2 = polygon[i % N];
    if (p.y > MIN(p1.y,p2.y)) {
      if (p.y <= MAX(p1.y,p2.y)) {
        if (p.x <= MAX(p1.x,p2.x)) {
          if (p1.y != p2.y) {
            xinters = (p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
            if (p1.x == p2.x || p.x <= xinters)
              counter++;
          }
        }
      }
    }
    p1 = p2;
  }

  if (counter % 2 == 0)
    return(OUTSIDE);
  else
    return(INSIDE);
}

//The following code is by Randolph Franklin, it returns 1 for interior points and 0 for exterior points.

    int pnpoly(int npol, float *xp, float *yp, float x, float y)
    {
      int i, j, c = 0;
      for (i = 0, j = npol-1; i < npol; j = i++) {
        if ((((yp[i] <= y) && (y < yp[j])) ||
             ((yp[j] <= y) && (y < yp[i]))) &&
            (x < (xp[j] - xp[i]) * (y - yp[i]) / (yp[j] - yp[i]) + xp[i]))
          c = !c;
      }
      return c;
    }

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
        if(fabs(cur.x-prev.x)<eps){
            curx=0.0;
            if(cur.y>prev.y){
                cury=0.2;
            }
            else{
                cury=-0.2;
            }
        }
        else if(fabs(cur.y-prev.y)<eps){
            cury=0.0;
            if(cur.x>prev.x){
                curx=0.2;
            }
            else{
                curx=-0.2;
            }
        }
        Point tocheck(cur.x+curx,cur.y+cury);
        cout<<tocheck.x<<" "<<tocheck.y<<"\n";
        if(InsidePolygon(polygon1,n+1,tocheck)){
            c++;
            cout<<"yes\n";
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
