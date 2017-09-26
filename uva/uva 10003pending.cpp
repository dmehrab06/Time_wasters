#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000009
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
using namespace std;

int cuts;
int cutpos[56];
int dp[1003][1003];
//algo: 2D dp
//try to find ans for start to end
//try to find ans for each cut withing s and e, take the minimum
void init(){
    for(int i=0;i<1003;++i){
        for(int j=0;j<1003;++j){
            dp[i][j]=-1;
        }
    }
}
int solve(int s, int e){
    if(s==e)return 0;
    if(dp[s][e]!=-1)return dp[s][e];
    int len=e-s;
    int mincost=MXX;
    for(int i=1;i<=cuts;++i){
        int p=cutpos[i];
        if(p>s && p<e){
            mincost=min(mincost,len+solve(s,p)+solve(p,e));
        }
    }
    if(mincost==MXX)mincost=0;
    return dp[s][e]=mincost;
}
int main(){
    int L;
    while(scanf("%d",&L)==1 && L){
        init();
        scanf("%d",&cuts);
        for(int i=1;i<=cuts;++i){
            scanf("%d",&cutpos[i]);
        }
        int ans=solve(0,L);
        printf("The minimum cutting is %d.\n",ans);
    }
    return 0;
}
