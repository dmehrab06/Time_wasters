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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;


vector< vector<int> > g;

vector<VI>teams3;
vector<VI>teams1;
vector<VI>teams2;


vector<int>curteam;

int vis[50];

void takeg(int n, int m){
    VI line;
    g.clear();
    FREP(i,1,(n+2)){
        g.PB(line);
    }
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    memset(vis,0,sizeof(vis));
}

int dfs(int cur){
    vis[cur]=1;
    curteam.PB(cur);
    int deg=g[cur].size();
    int sz=1;
    FREP(i,0,(deg-1)){
        int nxt=g[cur][i];
        if(!vis[nxt]){
            sz+=dfs(nxt);
        }
    }
    return sz;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    takeg(n,m);
    FREP(i,1,n){
        if(!vis[i]){
            curteam.clear();
            int sz=dfs(i);
            if(sz>3){
                printf("-1\n");
                return 0;
            }
            if(sz==3){
                teams3.PB(curteam);
            }
            if(sz==2){
                teams2.PB(curteam);
            }
            if(sz==1){
                teams1.PB(curteam);
            }
        }
    }
    int t1size=teams1.size();
    int t2size=teams2.size();
    int t3size=teams3.size();
    if(t2size>t1size){
        printf("-1\n");
        return 0;
    }
    FREP(i,0,(t3size-1)){
        VI tt=teams3[i];

            printf("%d %d %d\n",tt[0],tt[1],tt[2]);

    }
    FREP(i,0,(t2size-1)){
        VI tt1=teams2[i];
        VI tt2=teams1[i];
        printf("%d %d %d\n",tt1[0],tt1[1],tt2[0]);

    }
    for(int i=t2size;i<t1size;i+=3){
        VI tt1=teams1[i];
        VI tt2=teams1[i+1];
        VI tt3=teams1[i+2];
        printf("%d %d %d\n",tt1[0],tt2[0],tt3[0]);
    }
    return 0;
}
