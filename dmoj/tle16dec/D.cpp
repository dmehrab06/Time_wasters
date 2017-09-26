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
#define MXX 1000000000000000000
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

vector <  vector <PII> > g;

int intermed;
LLI curmaxd;

LLI d1[100005];
LLI d2[100005];

int vis[100005];

void dfs1(int cur, int par, LLI dis){
    d1[cur]=dis;
    if(d1[cur]>curmaxd){
        curmaxd=d1[cur];
        intermed=cur;
    }
    int l=g[cur].size();
    FREP(i,0,(l-1)){
        int v=g[cur][i].first;
        int w=g[cur][i].second;
        if(v==par)continue;
        dfs1(v,cur,dis+w);
    }
    return;
}

void dfs2(int cur, int par, LLI dis){
    d2[cur]=dis;
    vis[cur]=1;
    if(d2[cur]>curmaxd){
        curmaxd=d2[cur];
        intermed=cur;
    }
    int l=g[cur].size();
    FREP(i,0,(l-1)){
        int v=g[cur][i].first;
        int w=g[cur][i].second;
        if(v==par)continue;
        dfs2(v,cur,dis+w);
    }
    return;
}

void takeg(int n, int m){
    vector<PII>line;
    FREP(i,1,(n+5))g.PB(line);
    FREP(i,1,m){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        g[u].PB(make_pair(v,w));
        g[v].PB(make_pair(u,w));
    }
}

int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    takeg(n,m);
    if(q==1){
        LLI s=0;
        int cmp=0;
        FREP(i,1,n){
            if(!vis[i]){
                curmaxd=-1;
                intermed=-1;
                dfs1(i,i,0);
                curmaxd=-1;
                dfs2(intermed,intermed,0);
                cmp++;
                s+=curmaxd;
            }
        }
        s+=(cmp-1);
        cout<<s<<"\n";
    }
    else{
        printf("janina\n");
    }
    return 0;
}

