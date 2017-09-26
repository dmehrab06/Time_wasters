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

struct P2D
{
    double x, y;
    double len;
    P2D(double _x=0.0, double _y=0.0){
        x=_x;
        y=_y;
        len=sqrt(x*x+y*y);
    }
};

//typedef Point3 Vector3;

P2D add(P2D a, P2D b){
    P2D res(a.x+b.x,a.y+b.y);
    return res;
}
P2D sub(P2D a, P2D b){
    P2D res(a.x-b.x,a.y-b.y);
    return res;
}

double dprod(P2D a, P2D b){
    return a.x*b.x+a.y*b.y;
}

double sq(double x){
    return x*x;
}

double ang(P2D a, P2D b){
    double val=dprod(a,b);
    double ll=a.len*b.len;
    double ang=acos(val/ll);
    return ang;
}

double area(P2D A, P2D B, P2D C){
    P2D AB=sub(B,A);
    P2D AC=sub(C,A);
    double x1=AB.x;
    double x2=AB.y;
    double y1=AC.x;
    double y2=AC.y;
    double oka=sq(x1*y2-x2*y1);
    oka=sqrt(oka);
    return oka/2.0;
}

struct Line{
    double A,B,C;
    Line(P2D p1, P2D p2){
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

bool areintersect(Line &l1, Line &l2, P2D &ret){
    if(areparallel(l1,l2))return false;
    ret.x=(l2.B*l1.C-l1.B*l2.C)/(l2.A*l1.B-l1.A*l2.B);
    if(fabs(l1.B)>eps)ret.y=-(l1.A*ret.x+l1.C);
    else{
        ret.y=-(l2.A*ret.x+l2.C);
    }
    return true;
}


bool isinside(P2D A,P2D B,P2D C,P2D P){
    double a1=area(P,A,B);
    double a2=area(P,B,C);
    double a3=area(P,C,A);
    double asol=area(A,B,C);
    double tmp=a1+a2+a3;
    if(fabs(tmp-asol)<eps){
        return true;
    }
    return false;
}

P2D rotate_point(double cx,double cy,double angle,P2D p)
{
  double s = sin(angle);
  double c = cos(angle);
  p.x -= cx;
  p.y -= cy;
  double xnew = p.x * c - p.y * s;
  double ynew = p.x * s + p.y * c;
  p.x = xnew + cx;
  p.y = ynew + cy;
  return p;
}

P2D calcD(P2D A, P2D B, P2D C){
        //cout<<"in d\n";
        P2D BC=sub(C,B);
        P2D CB=sub(B,C);
        P2D CA=sub(A,C);
        P2D BA=sub(A,B);
        double ang1=ang(BC,BA);
        double ang2=ang(CB,CA);
        //cout<<ang1<<" "<<ang2<<"\n";
        double rot1=ang1/3.0;
        double rot2=ang2/3.0;
        P2D newC=rotate_point(B.x,B.y,rot1,C);
        P2D newB=rotate_point(C.x,C.y,-rot2,B);
        Line l1(B,newC);
        Line l2(C,newB);
        P2D I1;
        areintersect(l1,l2,I1);
        return I1;
}

P2D calcE(P2D A, P2D B, P2D C){
        //cout<<"in e\n";
        P2D CB=sub(B,C);
        P2D CA=sub(A,C);
        P2D AB=sub(B,A);
        P2D AC=sub(C,A);
        double ang1=ang(CB,CA);
        double ang2=ang(AB,AC);
        double rot1=ang1/3.0;
        double rot2=ang2/3.0;
       // cout<<ang1<<" "<<ang2<<"\n";
        P2D newA=rotate_point(C.x,C.y,rot1,A);
        P2D newC=rotate_point(A.x,A.y,-rot2,C);
        Line l1(A,newC);
        Line l2(C,newA);
        P2D I1;
        areintersect(l1,l2,I1);
        return I1;
}

P2D calcF(P2D A, P2D B, P2D C){
        //cout<<"in f\n";
        P2D BC=sub(C,B);
        P2D AC=sub(C,A);
        P2D AB=sub(B,A);
        P2D BA=sub(A,B);
        double ang1=ang(AC,AB);
        double ang2=ang(BC,BA);
        //cout<<ang1<<" "<<ang2<<"\n";
        double rot1=ang1/3.0;
        double rot2=ang2/3.0;
        P2D newB=rotate_point(A.x,A.y,rot1,B);
        P2D newA=rotate_point(B.x,B.y,-rot2,A);
        Line l1(A,newB);
        Line l2(B,newA);
        P2D I1;
        areintersect(l1,l2,I1);
        return I1;
}


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        double xa,ya,xb,yb,xc,yc;
        scanf("%lf %lf %lf %lf %lf %lf",&xa,&ya,&xb,&yb,&xc,&yc);
        P2D A(xa,ya);
        P2D B(xb,yb);
        P2D C(xc,yc);
        P2D D=calcD(A,B,C);
        P2D E=calcE(A,B,C);
        P2D F=calcF(A,B,C);
        printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",D.x,D.y,E.x,E.y,F.x,F.y);
    }
    return 0;
}
