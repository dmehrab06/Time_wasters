#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

struct Point
{
   long long int x, y;
};

Point p0;

Point nextTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

long long int squaredist(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y);
}

int orient(Point p, Point q, Point r)
{
   long long int v = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (!v) return 0;  // colinear
    if(v>0)return 1;
    return 2; // clock or counterclock wise
}

int comp(const void *pp1, const void *pp2)
{
   Point *p1 = (Point *)pp1;
   Point *p2 = (Point *)pp2;

   // Find orientation
   int o = orient(p0, *p1, *p2);
   if (o == 0)
     return (squaredist(p0, *p2) >= squaredist(p0, *p1))? -1 : 1;

   if(o==2)return -1;
   return 1;
}

// Prints convex hull of a set of n points.

long long int pointx[100005];
long long int pointy[100005];

double findarea(int N){
    if(N<3)return 0.0000;
    double area=0.0000;
    for(int i=0;i<N;++i){
        area=area+((double)pointx[i]*(double)pointy[(i+1)%N]-(double)pointy[i]*(double)pointx[(i+1)%N]);
    }
    area=area/2.00000;
    if(area<0){
        area=area*(-1.0000);
    }
    return area;
}
int cHull(Point points[], int n)
{
   long long int ymn = points[0].y;
   long long int mn = 0;
   for (int i = 1; i < n; i++)
   {
     long long int y = points[i].y;

     // Pick the bottom-most or chose the left
     // most point in case of tie
     if ((y < ymn) || (ymn == y && points[i].x < points[mn].x)){
        ymn = points[i].y;
        mn = i;
    }
   }

   swap(points[0], points[mn]);
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), comp);
    int m = 1;
   for (int i=1; i<n; i++)
   {

       while (i < n-1 && orient(p0, points[i],points[i+1]) == 0){
          i++;
        }
       points[m] = points[i];
       m++;
   }
    if (m < 3) return 0;
    stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);

   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      while (orient(nextTop(S), S.top(), points[i]) != 2){
        S.pop();
      }

      S.push(points[i]);
   }

   // Now stack has the output points, print contents of stack
   int sz=0;
   while (!S.empty())
   {
       Point p = S.top();
      // cout << "(" << p.x << ", " << p.y <<")" << endl;
       pointx[sz]=p.x;
       pointy[sz]=p.y;
       sz++;
       S.pop();
   }
   return sz;
}

typedef pair<long long int,long long int> pairs;

Point points[100005];

int main()
{
    int t;
    scanf("%d",&t);
    set<pairs>::iterator it;
    set<pairs>pointset;
    while(t--){
        pointset.clear();
        int q;
        scanf("%d",&q);
        while(q--){
            string cc;
            long long int x,y;
            //scanf("%c %d %d",&cc,&x,&y);
            cin>>cc>>x>>y;
            pairs pt=make_pair(x,y);
            if(cc[0]=='+'){
                pointset.insert(pt);
            }
            else{
                pointset.erase(pt);
            }
            int nn=0;
            for(it=pointset.begin();it!=pointset.end();it++){
                Point pp;
                pp.x=it->first;
                pp.y=it->second;//(it->first,it->second);
                points[nn]=pp;
                nn++;
            }
            //int nn = sizeof(points)/sizeof(points[0]);
            int sz=cHull(points, nn);
            double area=findarea(sz);
            printf("%.1lf\n",area);


        }
    }
    return 0;
}
