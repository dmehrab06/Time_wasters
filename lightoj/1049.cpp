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

vector< vector<PII> >g;
int vis[103];

int minval=1000000007;
int curval=0;

void takeg(int n, int m){
    g.clear();
    vector<PII>line;
    FREP(i,1,(n+2))g.PB(line);
    FREP(i,1,m){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        g[u].PB(make_pair(v,0));
        g[v].PB(make_pair(u,w));
    }
}

void dfs(int cur, int flag, int par){
    //curval+=val;
    if(vis[cur])return;
    vis[cur]=1;
    int nxt,w;
    if(flag<2){
        nxt=g[cur][flag].first;
        curval+=(w=g[cur][flag].second);
        dfs(nxt,2,cur);
    }
    else{
        int l=g[cur].size();
        FREP(i,0,(l-1)){
            nxt=g[cur][i].first;
            if(nxt==par)continue;
            curval+=(w=g[cur][i].second);
            dfs(nxt,2,cur);
        }
    }
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        minval=1000000007;
        scanf("%d",&n);
        takeg(n,n);
        memset(vis,0,sizeof(vis));
        curval=0;
        dfs(1,0,0);
      //  cout<<curval<<"\n";
        minval=min(curval,minval);
        memset(vis,0,sizeof(vis));
        curval=0;
        dfs(1,1,0);
      //  cout<<curval<<"\n";
        minval=min(curval,minval);
        printf("Case %d: %d\n",cs++,minval);
    }
    return 0;
}
