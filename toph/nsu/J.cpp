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
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

int g[1004][1004];

vector<PII>edg;

vector< VI >gg;

void init(){
    memset(g,0,sizeof(g));
    edg.clear();
    gg.clear();
}

void takeg(int n, int m){
    VI line;
    FREP(i,0,(n+3))gg.PB(line);
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u][v]=1;
        g[v][u]=1;
        gg[u].PB(v);
        gg[v].PB(u);
        edg.PB(make_pair(u,v));
    }
}

bool check3(int n, int m){
    int mm=m/3;
    FREP(i,mm,(2*mm)){
        if(i==m)break;
        PII oka=edg[i];
        int u=oka.first;
        int v=oka.second;
        FREP(i,0,(n-1)){
            if(i==u || i==v)continue;
            if(g[u][i] && g[u][v])return true;
        }
    }
    FREP(i,(2*mm+1),(m-1)){
        //if(i==m)break;
        PII oka=edg[i];
        int u=oka.first;
        int v=oka.second;
        FREP(i,0,(n-1)){
            if(i==u || i==v)continue;
            if(g[u][i] && g[u][v])return true;
        }
    }
    FREP(i,0,(mm-1)){
        if(i==m)break;
        PII oka=edg[i];
        int u=oka.first;
        int v=oka.second;
        FREP(i,0,(n-1)){
            if(i==u || i==v)continue;
            if(g[u][i] && g[u][v])return true;
        }
    }
    return false;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        init();
        takeg(n,m);
        bool f=check3(n,m);
        if(f){
            if(m<=(3*n-6) || n<3){
                f=false;
            }
            else{
                f=true;
            }
        }
        else{
            if(m<=(2*n-4) || n<3){
                f=false;
            }
            else{
                f=true;
            }
        }
        printf("Case %d: %s\n",cs++,(f?"Yes":"No"));
    }
    return 0;
}
