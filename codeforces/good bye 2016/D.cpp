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

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<PII>rating;

int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};

bool dp[312][312][10][32][6];
bool vis[312][312];


int n;

int reclevel[39];

void solve(int x, int y, int dir, int rec, int lev){
    if(x<0 || y<0)return;
    if(rec>n)return;
    if(dp[x][y][dir][rec][lev])return;
    dp[x][y][dir][rec][lev]=true;
    vis[x][y]=true;
    if(lev==reclevel[rec]){
        int dir1=dir-1;
        if(dir1<0)dir1+=8;
        int dir2=(dir+1)%8;
        solve(x+dx[dir1],y+dy[dir1],dir1,rec+1,1);
        solve(x+dx[dir2],y+dy[dir2],dir2,rec+1,1);
        return;
    }
    solve(x+dx[dir],y+dy[dir],dir,rec,lev+1);
    return;
}

int main(){
    memset(vis,false,sizeof(vis));
    memset(dp,false,sizeof(dp));
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&reclevel[i]);
    }
    solve(312/2,312/2,6,1,1);
    int ans=0;
    /*FREP(i,312/2-30,312/2+30){
        FREP(j,0,30){
            printf("%d",vis[i][j]);
        }
        printf("\n");
    }*/
    FREP(i,0,311){
        FREP(j,0,311){
            if(vis[i][j]==true){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}


