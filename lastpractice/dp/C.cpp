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
#define ISVALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
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
#define PI acos(-1.0)
using namespace std;
using namespace __gnu_pbds;

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

char grid[103][103];

int dp[103][103][3][3]; //1 means came from left // 2 means came from up

void init(){
    memset(dp,-1,sizeof(dp));
}

int solve(int curx, int cury, int dir1, int dir2, int n, int m){ //dir1 is just the prev direction //
    int mouse = 0;
    if(grid[curx][cury]=='1')if(!dir1)mouse++;
    FREP(i,0,3){
        int nxtx = curx+dx[i];
        int nxty = cury+dy[i];
        if(i==2){
            if(ISVALID(nxtx,nxty,n,m) && grid[nxtx][nxty]=='1'){
                if(dir1==2){
                    continue;
                }
                else if(dir1==1 && dir2==2){
                    continue;
                }
                else{
                    mouse++;
                }
            }
        }
        else if(i==3){
            if(ISVALID(nxtx,nxty,n,m) && grid[nxtx][nxty]=='1'){
                if(dir1==1){
                    continue;
                }
                else if(dir1==2 && dir2==1){
                    continue;
                }
                else{
                    mouse++;
                }
            }
        }
        else{
            if(ISVALID(nxtx,nxty,n,m) && grid[nxtx][nxty]=='1'){
                mouse++;
            }
        }
    }
    if(curx==(n-1) && cury==(m-1))return dp[curx][cury][dir1][dir2]=mouse;
    if(dp[curx][cury][dir1][dir2]!=-1)return dp[curx][cury][dir1][dir2];

    int ret1 = 100000000; int ret2 = 100000000;
    if(ISVALID(curx+1,cury,n,m))ret1 = mouse + solve(curx+1,cury,2,dir1,n,m);
    if(ISVALID(curx,cury+1,n,m))ret2 = mouse + solve(curx,cury+1,1,dir1,n,m);
    return dp[curx][cury][dir1][dir2] = min(ret1,ret2);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        init();
        FREP(i,0,(n-1)){
            scanf("%s",grid[i]);
        }
        int ans = solve(0,0,0,0,n,m);
        printf("%d\n",ans);
    }
    return 0;
}
