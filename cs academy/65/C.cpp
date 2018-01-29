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
#define MSET(V,a) memset(V,a,sizeof(V))
using namespace std;

vector<VI>g;

int distnc[100005];
int parnt[100005];

int vis[100005];

int nxt[100005];

int lsttraverse[100005];

void takeinp(int n){
    g.clear();
    FREP(i,0,n+3){
        VI line;
        g.PB(line);
    }
    FREP(i,1,(n-1)){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v); g[v].PB(u);
    }
}

void init(){
    MSET(distnc,-1); MSET(parnt,-1);
    MSET(nxt, -1);  MSET(lsttraverse,-1);
}

void dfs(int cur, int par, int dis){
    distnc[cur] = dis;
    parnt[cur] = par;
    FREP(i,0,g[cur].size()-1){
        int u  = g[cur][i];
        if(par==u)continue;
        dfs(u,cur,dis+1);
    }
    return;
}

void dfsans(int cur, int par){
    printf("%d ",cur);
    int f = 1;
    FREP(i,0,g[cur].size()-1){
        int u = g[cur][i];
        if(u==par)continue;
        if(u==lsttraverse[cur])continue;
        //f = 0;
        dfsans(u,cur);
        printf("%d ",cur);
    }
    //dfsans()
    //if(f==0)printf("%d ",cur);
    if(lsttraverse[cur]!=-1)dfsans(lsttraverse[cur],cur);
}

void solve(int n){
    dfs(1,-1,0);
    int mxdis = -1; int mxi = -1;
    FREP(i,1,n){
        if(distnc[i]>mxdis){
            mxdis = distnc[i];
            mxi = i;
        }
    }
    dfs(mxi,-1,0);
    int root = mxi;
    mxdis = -1; mxi = -1;
    FREP(i,1,n){
        if(distnc[i]>mxdis){
            mxdis = distnc[i];
            mxi = i;
        }
    }
    int cur = mxi;
    int path = 0;
    while(true){
        //cout<<cur<<" ";
        int pp = parnt[cur];
        if(pp==-1)break;
        path++;
        lsttraverse[pp] = cur;
        cur = pp;
    }
    cout<<"\n";
    int extra = (n-1)-path;
    cout<<path+(2*extra)<<"\n";
    dfsans(root,-1);
    cout<<"\n";
}

int main(){
    init();
    int n;
    scanf("%d",&n);
    takeinp(n);
    solve(n);
    return 0;
}
