/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int grid[20][20];

map<pair<PII,LLI>,int>dpmap;

int solve(int curx, int cury, LLI val){
    if(grid[curx][cury]>val){
        return 0;
    }
    if(curx==1 && cury==1){
        if(grid[curx][cury]<=val){
            return 1;
        }
        return 0;
    }
    pair<PII,LLI>oka=make_pair(make_pair(curx,cury),val);
    if(dpmap.find(oka)!=dpmap.end())return dpmap[oka];
    int ret=0;
    LLI left=val/grid[curx][cury];
    if(curx>1){
        ret=ret+solve(curx-1,cury,left);
        ret%=1000000007;
    }
    if(cury>1){
        ret=ret+solve(curx,cury-1,left);
        ret%=1000000007;
    }
    return dpmap[oka]=ret;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        dpmap.clear();
        FREP(i,1,n){
            FREP(j,1,n){
                scanf("%d",&grid[i][j]);
            }
        }
        LLI k;
        scanf("%lld",&k);
        int ans=solve(n,n,k);
        printf("%d\n",ans);
    }
    return 0;
}
