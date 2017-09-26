/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

struct pt2d{
    double x;
    double y;
    pt2d(double _x=0.0, double _y=0.0){
        x=_x; y=_y;
    }
    double dis(pt2d p){
        double dx = x-p.x;
        double dy = y-p.y;
        return sqrt(dx*dx+dy*dy);
    }
    bool iszero(){
        return (fabs(x)<eps) && (fabs(y)<eps);
    }
};

struct tri{
    pt2d A,B,C;
    tri(pt2d a, pt2d b, pt2d c){
        A = a;
        B = b;
        C = c;
    }
    pt2d incentre(){
        //print();
        double a = B.dis(C); double b = C.dis(A); double c = A.dis(B);
        double ss = a+b+c;
        //cout<<"perimeter "<<ss<<"\n";
        double xx = a*A.x+b*B.x+c*C.x; double yy = a*A.y+b*B.y+c*C.y;
        //cout<<"xx "<<xx<<" yy "<<yy<<"\n";
        double x = xx/ss; double y = yy/ss;
        //cout<<"centrex "<<x<<" centrey "<<y<<"\n";
        return pt2d(x,y);
    }
    double getsemi(){
        double a = B.dis(C); double b = C.dis(A); double c = A.dis(B);
        double ss = a+b+c;
        return ss/2;
    }
    void print(){
        cout<<"mypoints\n";
        cout<<A.x<<" "<<A.y<<"\n";
        cout<<B.x<<" "<<B.y<<"\n";
        cout<<C.x<<" "<<C.y<<"\n";
    }
};

pair<double,PDD>getabc(pt2d st, pt2d ed){
    double a = st.y - ed.y;
    double b = ed.x - st.x;
    double c = -st.y*(b)-st.x*(a);
    return make_pair(c,make_pair(a,b));
}

double perpdis(pair<double,PDD> abc, pt2d p){
    double c = abc.first; double a = abc.second.first; double b = abc.second.second;
    double lob = fabs(a*p.x+b*p.y+c);
    double hor = sqrt(a*a+b*b);
    return lob/hor;
}

void solve(tri T){
    pt2d incentre = T.incentre();
    //cout<<"incentre "<<incentre.x<<" "<<incentre.y<<"\n";
    pair<double,PDD>abc = getabc(T.A,T.B);
    double inradii = perpdis(abc,incentre);
    double a = T.B.dis(T.C); double b = T.C.dis(T.A); double c = T.A.dis(T.B);
    double d = incentre.dis(T.A);
    double e = incentre.dis(T.B);
    double f = incentre.dis(T.C);
    double s = T.getsemi();

    double r1 = inradii*(s+d-inradii-e-f); r1/=(2*(s-a));
    double r2 = inradii*(s+e-inradii-d-f); r2/=(2*(s-b));
    double r3 = inradii*(s+f-inradii-d-e); r3/=(2*(s-c));

    printf("%.6lf %.6lf %.6lf\n",r1,r2,r3);
}

int main() {
    double x1,y1,x2,y2,x3,y3;
    while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)==6){
        pt2d p1(x1,y1);
        pt2d p2(x2,y2);
        pt2d p3(x3,y3);
        if(p1.iszero() && p2.iszero() && p3.iszero())break;
        tri T(p1,p2,p3);
        solve(T);
    }
	return 0;
}
