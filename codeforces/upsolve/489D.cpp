#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define pi acos(-1.0)
#define float double
using namespace std;

int vis[3005];
int adj[3005][3005];
int came[3005];

void sg(int m){
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u][++adj[u][0]]=v;
        //adj[v][++adj[v][0]]=u;
    }
}

void init(int n){
    FREP(i,1,n){
        vis[i]=0;
        came[i]=0;
    }
}

LLI calc(int n){
    LLI s=0;
    FREP(i,1,n){
        LLI cur=(LLI)came[i]*(LLI)(came[i]-1);
        cur/=2;
        s+=cur;
    }
    return s;
}

void dfs(int cur, int depth, int par){
    if(depth==2){
        came[cur]++;
        return;
    }
    if(vis[cur])return;
    vis[cur]=1;
    int d=adj[cur][0];
    FREP(i,1,d){
        int nxt=adj[cur][i];
        if(nxt!=par){
            dfs(nxt,depth+1,cur);
        }
    }
    return;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    sg(m);
    LLI ans=0;
    FREP(i,1,n){
        init(n);
        dfs(i,0,i);
        ans+=calc(n);
    }
    cout<<ans<<"\n";
}
