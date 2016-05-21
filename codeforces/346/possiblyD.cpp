#include <iostream>
#include <cmath>
using namespace std;

// Define Infinite (Using INT_MAX caused overflow problems)
#define INF 10009.0
#define eps 0.0000001
struct Point
{
    float x;
    float y;
    Point(){
        x=0.0;
        y=0.0;
    }
    Point(float a,float b){
        x=a;
        y=b;
    }
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if ((q.x < max(p.x, r.x) || (fabs(q.x-max(p.x,r.x))<eps)) && (q.x > min(p.x, r.x) || (fabs(q.x-min(p.x,r.x))<eps)) &&
            (q.y < max(p.y, r.y) || (fabs(q.y-max(p.y,r.y))<eps)) && (q.y > min(p.y, r.y) || (fabs(q.y-min(p.y,r.y))<eps)))
        return true;
    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    float val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (fabs(val) < eps) return 0;  // colinear
    return (val > 0.0)? 1: 2; // clock or counterclock wise
}

// The function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

// Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(Point polygon[], int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;

    // Create a point for line segment from p to infinite
    Point extreme = {INF, p.y};

    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;

        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polygon[i], p, polygon[next]) == 0)
               return onSegment(polygon[i], p, polygon[next]);

            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}

// Driver program to test above functions
Point polygon1[10005];
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
        float xx=x;
        float yy=y;
        Point p(xx,yy);
            polygon1[(i-1)]=p;
    }
    int c=0;
    for(int i=1;i<(n+1);++i){
        float curx,cury;
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
        if(isInside(polygon1,n,tocheck)){
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
