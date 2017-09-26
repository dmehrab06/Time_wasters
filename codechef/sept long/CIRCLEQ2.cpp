#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
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
#define pi acos(-1.0)
#define float double
using namespace std;

double calcarea(double xc, double yc, double r, double xl, double yb, double xr, double yu){
   // find the signed (negative out) normalized distance from the circle centerto each of the infinitely extended rectangle edge lines,
   double darr[6];
   darr[1]=(xc-xl)/r;
   darr[2]=(yc-yb)/r;
   darr[3]=(xr-xc)/r;
   darr[4]=(yu-yc)/r;
    darr[5]=darr[1];
    FREP(i,1,4){
        if(darr[i]<=(-1.00))return 0.00;
    }
    int f=1;

    FREP(i,1,4){
        if(!(darr[i]>=1.00))f=0;
    }

    if(f)return pi*r*r;

    //this leave only one remaining fully outside case: circle center in
    //an external quadrant, and distance to corner greater than circle radius:

    FREP(i,1,4){
        if(darr[i]<=0.00 && darr[i+1]<=0.00){
            double dd=darr[i]*darr[i]+darr[i+1]*darr[i+1];
            if(dd>1.00)return 0;
        }
    }
     //if d_i<=0 and d_j <= 0 and d_i^2+d_j^2 > 1 return 0

    //now begin with full circle area  and subtract any areas in the
    //four external half planes

    double Area= pi*r*r;
    double arr[10];
    for(int i=1;i<=4;++i){
        if(darr[i]>(-1.00) && darr[i]<(1.00)){
            arr[i]=asin(darr[i]);
            double kk=(r*r)*(pi-2*arr[i]-sin(2 *arr[i]));
            Area=Area-(kk/2.0);
        }
    }

//At this point note we have double counted areas in the four external
//quadrants, so add back in:
    FREP(i,1,4){
        if(darr[i]<1.00 && darr[i+1]<1.00){
            double dd=darr[i]*darr[i]+darr[i+1]*darr[i+1];
            if(dd<1.00){
               double ff= (pi- 2*arr[i] - 2* arr[i+1]-sin(2*arr[i]) -sin(2* arr[i+1]) + 4*sin(arr[i])*sin(arr[i+1]));
               Area=Area+(ff/4.0);
            }//return 0;
        }
    }
    return Area;
}

double cx[50005];
double cy[50005];
double r[50005];

float section(float h, float r=1) // returns the positive root of intersection of line y = h with circle centered at the origin and radius r
{
    // assume r is positive, leads to some simplifications in the formula below (can factor out r from the square root)
    return (h<r)?sqrt(r*r-h*h):0; // http://www.wolframalpha.com/input/?i=r+*+sin%28acos%28x+%2F+r%29%29+%3D+h
}

float g(float x, float h, float r=1) // indefinite integral of circle segment
{
    return (.5)*(sqrt(1-x*x/(r*r))*x*r+r*r*asin(x/r)-2*h*x); // http://www.wolframalpha.com/input/?i=r+*+sin%28acos%28x+%2F+r%29%29+-+h
}

float area(float x0, float x1, float h, float r) // area of intersection of an infinitely tall box with left edge at x0, right edge at x1, bottom edge at h and top edge at infinity, with circle centered at the origin with radius r
{
    if(x0>x1)
        swap(x0, x1); // this must be sorted otherwise we get negative area
    float s = section(h, r);
    return g(max(-s,min(s,x1)),h,r)-g(max(-s,min(s,x0)),h,r); // integrate the area
}

float area(float x0, float x1, float y0, float y1, float r) // area of the intersection of a finite box with a circle centered at the origin with radius r
{
    if(y0>y1)
        swap(y0,y1); // this will simplify the reasoning
    if(y0<0) {
        if(y1<0)
            return area(x0, x1, -y0, -y1, r); // the box is completely under, just flip it above and try again
        else
            return area(x0, x1, 0, -y0, r) + area(x0, x1, 0, y1, r); // the box is both above and below, divide it to two boxes and go again
    } else {
        assert(y1 >= 0); // y0 >= 0, which means that y1 >= 0 also (y1 >= y0) because of the swap at the beginning
        return area(x0, x1, y0, r) - area(x0, x1, y1, r); // area of the lower box minus area of the higher box
    }
}

float area(float x0, float x1, float y0, float y1, float cx, float cy, float r) // area of the intersection of a general box with a general circle
{
    x0 -= cx; x1 -= cx;
    y0 -= cy; y1 -= cy;

    return area(x0, x1, y0, y1, r);
}

int main(){
    int N,Q;
    scanf("%d %d",&N,&Q);
    FREP(i,1,N){
        scanf("%lf %lf %lf",&cx[i],&cy[i],&r[i]);
    }
    FREP(k,1,Q){
        double xl,yb,xr,yu;
        scanf("%lf %lf %lf %lf",&xl,&yb,&xr,&yu);
        double ans=0.00;
        FREP(i,1,N){
            ans=ans+area(xl,xr,yb,yu,cx[i],cy[i],r[i]);
        }
        printf("%.10lf\n",ans);
    }
   // double a=area(2, 5, 2, 5, 5, 5, 2);
   // double b=area(2, 5, 2, 5, 2, 2, 1);
   // printf("%.8lf\n",a+b);
    return 0;
}
