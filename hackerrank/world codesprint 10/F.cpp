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
#define MXX 10000000000000000
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

struct Point{
    int x,y;
    Point(int _x=0, int _y=0){
        x=_x; y=_y;
    }
    void print(){
        printf("x: %d y: %d\n",x,y);
    }
};

Point getdir(Point a, Point b){
    return Point(b.x-a.x,b.y-a.y);
}

struct Line{
    Point p,dp;
    Line(){

    }
    Line(Point a, Point b){
        p=a;
        dp=getdir(a,b);
    }
    void print(){
        printf("starting point: ");p.print();
        printf("direction: ");dp.print();
        printf("\n");
    }
};

pair<double,double>solve(Line a, Line b){
    LLI hor=b.dp.x*a.dp.y-a.dp.x*b.dp.y;
    LLI lob=a.dp.x*(b.p.y-a.p.y)-a.dp.y*(b.p.x-a.p.x);
    if(hor==0){
        return make_pair(MXX,MXX);
    }
    double t2=(double)lob/(double)hor;
    double val1=(double)b.p.y+t2*b.dp.y-(double)a.p.y;
    double val2=(double)b.p.x+t2*b.dp.x-(double)a.p.x;
    if(a.p.x==0){
        double t1= (double)val1/(double)a.p.y;
        return make_pair(t1,t2);
    }
    double t1=(double)val2/(double)a.p.x;
    return make_pair(t1,t2);
}

bool isvalid(Line a, Line b){
    pair<double,double>tt=solve(a,b);
    double t1=tt.first; double t2=tt.second;
    //a.print();
    //b.print();
    //printf("%.2lf %.2lf\n",t1,t2);
    if((fabs(t1)<eps || fabs(t1-1.0)<eps) && (fabs(t2)<eps || fabs(t2-1.0)<eps))return true;
    if(INRANGED(t1,0.0+eps,1.0-eps) || INRANGED(t2,0.0+eps,1.0-eps))return false;
    return true;
}

Line lines[1005];
Point pts[1005];
pair<int,int> edges[1005];
vector<int>shuffler;
int newmap[1005];

void fillnewmap(int n){
    FREP(i,0,(n-1)){
        newmap[shuffler[i]]=i+1;
    }
}

void takeedges(int n){
    FREP(i,1,(n-1)){
        scanf("%d %d",&edges[i].first,&edges[i].second);
    }
}

void takepts(int n){
    FREP(i,1,(n)){
        int x,y;
        scanf("%d %d",&x,&y);
        Point p(x,y);
        pts[i]=p;
    }
}

void makelines(int n){
    FREP(i,1,(n-1)){
        int u=edges[i].first;
        int v=edges[i].second;
        int p1=newmap[u];
        int p2=newmap[v];
        Line l(pts[p1],pts[p2]);
        lines[i]=l;
    }
}

bool ok(int n){
    FREP(i,1,(n-1)){
        FREP(j,(i+1),(n-1)){
            Line l1=lines[i];
            Line l2=lines[j];
            if(!isvalid(l1,l2)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    takeedges(n);
    takepts(n);
    FREP(i,0,(n-1)){
        shuffler.PB(i+1);
    }
    srand(time(0));
    while(true){
        fillnewmap(n);
        makelines(n);
        if(ok(n)){
            break;
        }
        random_shuffle(shuffler.begin(),shuffler.begin()+(rand()%(n+1)));

    }
    FREP(i,0,(n-1)){
        printf("%d ",shuffler[i]);
    }
    printf("\n");
    return 0;
}
