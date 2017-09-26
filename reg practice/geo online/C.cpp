#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define PI acos(-1.0)
using namespace std;

struct Point
{
    double x, y;
    Point(double _x=0.0, double _y=0.0){
        x=_x;
        y=_y;
    }
    void update(double xd, double yd){
        x=x+xd;
        y=y+yd;
    }
    double product(Point a, Point b) {
        return (this->x - a.x)*(b.y - a.y) - (this->y - a.y)*(b.x - a.x);
    }

    bool right(Point a, Point b) {
        return product(a, b) > 0;
    }

    bool operator <(const Point& p) const {
        if (this->x != p.x) return this->x < p.x;
        return this->y < p.y;
    }

    bool operator ==(const Point& p) const {
        return this->x == p.x and this->y == p.y;
    }
};

struct Line{
    double A,B,C;
    Line(Point p1, Point p2){
        if(fabs(p1.x-p2.x)<eps){
            A=1.0;
            B=0.0;
            C=-p1.x;
        }
        else{
            A=-(double)(p1.y-p2.y)/(p1.x-p2.x);
            B=1.0;
            C=-(double)(A*p1.x)-p1.y;
        }
    }
};

bool areparallel(Line &l1, Line &l2){
    return ((fabs(l1.A-l2.A)<eps) && (fabs(l1.B-l2.B)<eps));
}

bool areintersect(Line &l1, Line &l2, Point &ret){
    if(areparallel(l1,l2))return false;
    ret.x=(l2.B*l1.C-l1.B*l2.C)/(l2.A*l1.B-l1.A*l2.B);
    if(fabs(l1.B)>eps)ret.y=-(l1.A*ret.x+l1.C);
    else{
        ret.y=-(l2.A*ret.x+l2.C);
    }
    return true;
}

Point midpoint(Point &p1, Point &p2){
    return Point((p1.x+p2.x)/2.0,(p1.y+p2.y)/2.0);
}


Point points[6003],meh[6003];

int convexHull(Point* P, int n, Point* S) {
    sort(P, P+n);

    int m=0;
    for(int i=0; i<n; i++) {
        while(m >= 2 && !S[m-1].right(S[m-2], P[i])) m--;
        S[m++] = P[i];
    }
    m--;

    for(int i=n-1, k=m; i >= 0; i--) {
        while(m >= k+2 && !S[m-1].right(S[m-2], P[i])) m--;
        S[m++] = P[i];
    }
    m--;

    return m;
}

double area(Point* A, int a) {
    double area = 0;
    for(int i=0; i<a; i++) {
        int j = (i+1)%a;
        area += (A[i].x + A[j].x) * (A[i].y - A[j].y);
    }
    return area / 2;
}

int main()
{
    int test;
    scanf("%d",&test);
    double xc,yc,w,h,ang;
    while(test--){
        int mod;
        scanf("%d",&mod);
        int sz=0;
        double rectarea=0.00;
        FREP(i,0,(mod-1)){
            scanf("%lf %lf %lf %lf %lf",&xc,&yc,&w,&h,&ang);
            if(fabs(w)<eps && fabs(h)<eps){
                Point A(xc,yc);
                points[sz++]=A;
            }
            else if(fabs(w)<eps){
                double theta=(PI*ang)/180.00;
                double hsin=h*sin(theta);
                double hcos=h*cos(theta);
                Point A(0.0,0.0);
                Point B(hsin,hcos);
                Point mid=midpoint(A,B);
                double dx=xc-mid.x;
                double dy=yc-mid.y;
                A.update(dx,dy);
                B.update(dx,dy);
                points[sz++]=A;
                points[sz++]=B;
            }
            else{
                if(false){
                    ang=ang*(-1.0);
                    double theta=(PI*ang)/(180.00);
                    double wcos=w*cos(theta);
                    double wsin=w*sin(theta);
                    double hcos=h*cos(theta);
                    double hsin=h*sin(theta);
                    Point A(-wcos,0.0);
                    Point B(-(wcos+hsin),hcos);
                    Point C(-hsin,-(wsin+hcos));
                    Point D(0.0,wsin);
                    Point ka=midpoint(B,C);
                    Point ga=midpoint(A,D);
                    Line l1(ka,ga);
                    Point kha=midpoint(A,B);
                    Point gha=midpoint(C,D);
                    Line l2(kha,gha);
                    //cout<<l1.A<<" "<<l1.B<<" "<<l1.C<<"\n";
                    //cout<<l2.A<<" "<<l2.B<<" "<<l2.C<<"\n";
                    Point ct;
                    if(areintersect(l1,l2,ct)){
                        double curxc=ct.x;
                        double curyc=ct.y;
                        double dx=xc-curxc;
                        double dy=yc-curyc;
                        A.update(dx,dy);
                        B.update(dx,dy);
                        C.update(dx,dy);
                        D.update(dx,dy);
                       cout<<A.x<<" "<<A.y<<"\n";
                        cout<<B.x<<" "<<B.y<<"\n";
                        cout<<C.x<<" "<<C.y<<"\n";
                        cout<<D.x<<" "<<D.y<<"\n";
                        points[sz++]=A;
                        points[sz++]=B;
                        points[sz++]=C;
                        points[sz++]=D;
                        rectarea=rectarea+(w*h);
                    }
                    else{
                        printf("moira gesi\n");
                    }
                }
                else{
                    //ang=ang*(-1.0);
                    double theta=(PI*ang)/(180.00);
                    double wcos=w*cos(theta);
                    double wsin=w*sin(theta);
                    double hcos=h*cos(theta);
                    double hsin=h*sin(theta);
                    Point A(wcos,0.0);
                    Point B((wcos+hsin),hcos);
                    Point C(hsin,(wsin+hcos));
                    Point D(0.0,wsin);
                    Point ka=midpoint(B,C);
                    Point ga=midpoint(A,D);
                    Line l1(ka,ga);
                    Point kha=midpoint(A,B);
                    Point gha=midpoint(C,D);
                    Line l2(kha,gha);
                  //  cout<<l1.A<<" "<<l1.B<<" "<<l1.C<<"\n";
                   // cout<<l2.A<<" "<<l2.B<<" "<<l2.C<<"\n";
                    Point ct;
                    if(areintersect(l1,l2,ct)){
                        double curxc=ct.x;
                        double curyc=ct.y;
                        double dx=xc-curxc;
                        double dy=yc-curyc;
                        A.update(dx,dy);
                        B.update(dx,dy);
                        C.update(dx,dy);
                        D.update(dx,dy);
                        points[sz++]=A;
                        points[sz++]=B;
                        points[sz++]=C;
                        points[sz++]=D;
                       // cout<<A.x<<" "<<A.y<<"\n";
                       // cout<<B.x<<" "<<B.y<<"\n";
                       // cout<<C.x<<" "<<C.y<<"\n";
                       // cout<<D.x<<" "<<D.y<<"\n";
                        rectarea=rectarea+(w*h);
                    }
                    else{
                        printf("moira gesi\n");
                    }
                }
            }

        }
        int got=convexHull(points,sz,meh);
        double polyarea=area(meh,got);
        if(polyarea<0.00)polyarea=polyarea*(-1.0);
        double percentage=(rectarea/polyarea)*(100.00);
        printf("%.1lf \%\n",percentage);

    }
    return 0;
}



