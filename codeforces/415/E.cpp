
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

vector< pair< PII, PII> > hsnk;
vector< pair< PII, PII> > vsnk;

void init(){
    hsnk.clear();
    vsnk.clear();
}

void takeinp(int n){
    FREP(i,1,n){
        int x1,y1,x2,y2;
        if(x1==x2){
            vsnk.PB(make_pair(make_pair(x1,y1),make_pair(x2,y2)));
        }
        else{
            hsnk.PB(make_pair(make_pair(x1,y1),make_pair(x2,y2)));
        }
    }
}

int manhattan(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+abs(y1-y2);
}

int getminmove(){
    int ultimateminmove = 100000000;
    FREP(x,1,50){
        FREP(y,1,50){
            //x,y is cur intersection point
            int mxmove = 0;
            int hsz=hsnk.size();
            FREP(i,0,(hsz-1)){
                pair< PII,PII > cursnake=hsnk[i];
                int yy = cursnake.first.second;
                int minx = min(cursnake.first.first,cursnake.second.first);
                int maxx = max(cursnake.first.first,cursnake.second.first);
                int minmove = 100000000;
                FREP(k,minx,maxx){
                    int travel = manhattan(k,yy,x,y);
                    minmove = min(travel,minmove);
                }
                mxmove = max(mxmove,minmove);
            }
            int vsz=vsnk.size();
            FREP(i,0,(vsz-1)){
                pair< PII,PII > cursnake=vsnk[i];
                int xx = cursnake.first.first;
                int miny = min(cursnake.first.second,cursnake.second.second);
                int maxy = max(cursnake.first.second,cursnake.second.second);
                int minmove = 100000000;
                FREP(k,miny,maxy){
                    int travel = manhattan(xx,k,x,y);
                    minmove = min(travel,minmove);
                }
                mxmove = max(mxmove,minmove);
            }
            ultimateminmove = min(ultimateminmove,mxmove);
        }
    }
    return ultimateminmove;
}

int main(){
    int t;
    while(t--){
        init();
        int n;
        scanf("%d",&n);
        takeinp(n);
        int ans = getminmove();
        printf("%d\n",ans);
    }
    return 0;
}
