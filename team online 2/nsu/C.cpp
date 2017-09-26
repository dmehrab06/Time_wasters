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

int g[2503][2503];
int weights[25003];
vector< PII >original;
vector< VI >adj;
void init(int n){
    FREP(i,1,n){
        FREP(j,1,n){
            g[i][j]=-1;
        }
    }
    adj.clear();
    VI line;
    FREP(i,1,(n+3))adj.PB(line);
    original.clear();
}

void takeginput(int n, int m){
    FREP(i,1,m){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(v);
        adj[v].push_back(u);
        original.push_back(make_pair(u,v));
        weights[i-1]=w;
    }
    sort(weights,weights+m);
    /*FREP(i,1,n){
        SORTV(adj[i]);
    }*/
}

void printsol(int m){
    FREP(i,0,(m-1)){
        int u=original[i].first;
        int v=original[i].second;
        int w=g[u][v];
        printf("%d %d %d\n",u,v,w);
    }
}

void bfs(int src){
    queue<int>bfsq;
    int st=0;
    bfsq.push(src);
    while(!bfsq.empty()){
        int cur=bfsq.front();
        bfsq.pop();
        int deg=adj[cur].size();
        FREP(i,0,(deg-1)){
            int nxt=adj[cur][i];
            if(g[cur][nxt]!=-1){
                continue;
            }
            g[cur][nxt]=weights[st];
            g[nxt][cur]=weights[st++];
            bfsq.push(nxt);
        }
    }
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,m,src;
        scanf("%d %d %d",&n,&m,&src);
        init(n);
        takeginput(n,m);
        bfs(src);
        printf("Case %d:\n",cs++);
        printsol(m);
    }
    return 0;
}
