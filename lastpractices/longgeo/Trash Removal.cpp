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
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

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

pair<double,PDD>getabc(pt2d st, pt2d ed){
    double a = st.y - ed.y;
    double b = ed.x - st.x;
    double c = -st.y*(b)-st.x*(a);
    return make_pair(c,make_pair(a,b));
}

double pointval(pair<double,PDD> abc, pt2d p){
    double c = abc.first; double a = abc.second.first; double b = abc.second.second;
    return (a*p.x)+(b*p.y)+c;
}

double perpdis(pair<double,PDD> abc, pt2d p){
    double c = abc.first; double a = abc.second.first; double b = abc.second.second;
    double lob = fabs(a*p.x+b*p.y+c);
    double hor = sqrt(a*a+b*b);
    return lob/hor;
}

int main(){
    int n;
    int cs = 1;
    while(scanf("%d",&n)==1){
        if(n==0)break;
        vector<pt2d>allpts;
        FREP(i,1,n){
            int x,y;
            scanf("%d %d",&x,&y);
            allpts.PB(pt2d(x,y));
        }
        double mindistance = 100000000000.00;
        FREP(i,0,allpts.size()-1){
            FREP(k,(i+1),allpts.size()-1){
                pt2d cur = allpts[i];
                pt2d nxt = allpts[k];
                pair<double,PDD>edg = getabc(cur,nxt);
                vector<double>disc;disc.PB(0.0);
                vector<double>discw;discw.PB(0.0);
                FREP(j,0,allpts.size()-1){
                    double dis = perpdis(edg,allpts[j]);
                    double dir = pointval(edg,allpts[j]);
                    if(dir<0)disc.PB(dis);
                    else discw.PB(dis);
                }
                SORTV(disc); SORTV(discw); REVV(disc); REVV(discw);
                mindistance = min(mindistance,disc[0]+discw[0]);
            }
        }
        printf("Case %d: %.2lf\n",cs++,mindistance);
    }
    return 0;
}
