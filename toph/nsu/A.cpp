/*-------property of the half blood prince-----*/

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
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

int dp[100005][3];

vector <VI> g;

void init(int n){
    memset(dp,-1,sizeof(dp));
    g.clear();
    VI line;
    FREP(i,0,(n+2)){
        g.PB(line);
    }
}

void takeg(int n, int m){
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v);
    }
}

int solve(int node, int curp){
    int l=g[node].size();
    if(l==0){
        return dp[node][curp]=(1-curp);
    }
    if(dp[node][curp]!=-1)return dp[node][curp];
    int f=0;
    FREP(i,0,(l-1)){
        int ret=solve(g[node][i],1-curp);
        if(ret==curp){
            f=1;
            break;
        }
    }
    if(f)return dp[node][curp]=curp;
    else return dp[node][curp]=1-curp;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,m,x;
        scanf("%d %d %d",&n,&m,&x);
        init(n);
        takeg(n,m);
        int ans=solve(x,0);
        if(ans==0){
            printf("Case %d: Yes\n",cs++);
        }
        else{
            printf("Case %d: No\n",cs++);
        }
        //return 0;
    }
    return 0;
}
