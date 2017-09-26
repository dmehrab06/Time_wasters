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

double sq(double x){
    return x*x;
}

double dis(pair<double,double>p1, pair<double,double>p2){
    double a= sq(p1.first-p2.first)+sq(p1.second-p2.second);
    return sqrt(a);
}

vector < pair<double,double> >pts;

int printdis(){
    int cnt = 0;
    FREP(i,0,pts.size()-1){
        FREP(j,(i+1),pts.size()-1){
            //cout<<dis(pts[i],pts[j])<<"\n";
            if(fabs(dis(pts[i],pts[j])-1.0)<eps){
                cout<<"between "<<i<<" and "<<j<<"\n";
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    //circle eqn x^2+y^2=1
    int n;
    scanf("%d",&n);
    printf("0 0\n");
    double y = (sqrt(3.0))/2.0;
    double x1 = sqrt(1.0-y*y);
    double x2 = -sqrt(1.0-y*y);
    printf("%.10lf %.10lf\n",x1,y);
    printf("%.10lf %.10lf\n",x2,y);
    pts.PB(make_pair(0,0));pts.PB(make_pair(x1,y));pts.PB(make_pair(x2,y));
    int ptleft = (n-3);
    int level = ptleft+1;
    //cout<<level<<"\n";
    double step = (x1-x2)/(double)level;
    int did =0;
    for(double xx=x2+step;xx<x1;xx+=step){
        double yy=sqrt(1.0-xx*xx);
        printf("%.10lf %.10lf\n",xx,yy);
        pts.PB(make_pair(xx,yy));
        did++;
        if(did==ptleft)break;
    }
    //cout<<did<<"\n";
    //printf("distances\n");
    //cout<<printdis()<<"\n";
    return 0;
}
