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
#define VD vector<double>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(int)(N);(i)++)
#define eps 0.0001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGEI(val,l,r) ((l)<=(val) && (val)<=(r))
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;

//-----------------------vector operations-----------------//
//---------------------------------------------------------//
//---------------------------------------------------------//

using namespace std;

int seq[1003];
int compnumber[100005];
int vis[100005];

vector< vector <int> >g;

void takeg(int n, int m){
    for(int i=1;i<=(n+3);++i){
        vector<int>line;
        g.push_back(line);
    }
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int dp[1003][1003];

void init(){
    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));
    g.clear();
}

void dfs(int cur, int comp){
    vis[cur]=1;
    compnumber[cur]=comp;
    int deg = g[cur].size();
    for(int i=0;i<deg;++i){
        int v = g[cur][i];
        if(!vis[v])dfs(v,comp);
    }
    return;
}

void dodfs(int n, int m){
    int curcomp=1;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            dfs(i,curcomp);
            curcomp++;
        }
    }
    for(int i=1;i<=m;++i){
      //  cout<<"in i: "<<i<<"\n";
        int val=seq[i];
       // cout<<"ase val: "<<val<<"\n";
        int cc=compnumber[val];
        seq[i]=cc;
       // cout<<"change korlam "<<cc<<" te\n";
    }
}



int solve(int st, int ed){
    if(st>ed){
        return 0;
    }
    if(st==ed){
        return dp[st][ed]=1;
    }
    if(dp[st][ed]!=-1){
        return dp[st][ed];
    }
    if(seq[st]==seq[ed]){
        dp[st][ed]=2+solve(st+1,ed-1);
    }
    else{
        dp[st][ed]=max(solve(st+1,ed),solve(st,ed-1));
    }
    return dp[st][ed];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    init();
    takeg(n,k);
    for(int i=1;i<=m;++i){
        scanf("%d",&seq[i]);
    }
    dodfs(n,m);
    int ans = solve(1,m);
    printf("%d\n",ans);
    return 0;
}
