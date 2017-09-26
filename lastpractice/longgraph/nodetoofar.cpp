/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int g[51][51];

int vis[51];
int v[51];

map<int,int>nodemap;

void init(){
    memset(g,0,sizeof(g)); memset(vis,-1,sizeof(vis)); nodemap.clear();
    memset(v,0,sizeof(v));
}

void bfs(int src , int n){
    memset(vis,-1,sizeof(vis));
    memset(v,0,sizeof(v));
    vis[src]=0;
    v[src]=1;
    queue<int>nodes;
    nodes.push(src);
    while(!nodes.empty()){
        int nw = nodes.front();
        nodes.pop();
        int ll = vis[nw];
        FREP(i,1,n){
            if(g[nw][i]==1 && !v[i]){
                nodes.push(i);
                vis[i]=ll+1;
                v[i]=1;
            }
        }
    }
    return;
}

int getcnt(int nodes, int ttl){
    int c = 0;
    FREP(i,1,nodes){
        //cout<<v[i]<<" "<<vis[i]<<"\n";
        if( !v[i] || vis[i]>ttl){
            c++;
        }
    }
    return c;
}

int main(){
    int n;
    int cs = 1;
    while(scanf("%d",&n)==1){
        if(n==0)break;
        init();
        int nodes = 0;
        FREP(i,1,n){
            int u,v;
            scanf("%d %d",&u,&v);
            int nu, nv;
            if(nodemap.find(u)==nodemap.end()){
                nodemap[u]=(++nodes);
                nu = nodes;
            }
            else{
                nu = nodemap[u];
            }
            if(nodemap.find(v)==nodemap.end()){
                nodemap[v]=(++nodes);
                nv = nodes;
            }
            else{
                nv = nodemap[v];
            }
            g[nu][nv]=1;
            g[nv][nu]=1;
        }
        int nd,ttl;
        while(scanf("%d %d",&nd,&ttl)==2){
            if(!nd && !ttl)break;
            if(nodemap.find(nd)==nodemap.end()){
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cs++,nodes,nd,ttl);
            }
            else{
                int mynode = nodemap[nd];
                bfs(mynode,nodes);
                int ans = getcnt(nodes,ttl);
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cs++,ans,nd,ttl);

            }
        }
    }
    return 0;
}
