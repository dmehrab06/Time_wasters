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

VI g; vector<VI>rg;


VI vis; //for rg;
VI visrev;
int xd;

int dfs_cycle(int src, int dis, int n){
    if(src==n)return -1; //cycle nai src theke
    vis[src]=1;
    int v = g[src];
    if(vis[v]==0){
        return dfs_cycle(v,dis+1,n);
    }
    return dis;
}

void dfs_depth(int cur, int len){
    visrev[cur]=1;
    if(cur==0)return;
    int l = rg[cur].size();
    FREP(i,0,(l-1)){
        int v = rg[cur][i];
        if(!visrev[v]){
            if(!vis[v]){
                xd = max(xd,len+1);
                dfs_depth(v,len+1);
            }
            else{
                dfs_depth(v,0);
            }
        }
    }
    return;
}

int solve_cycle(int n, int cycle_dis){
    //cycle thakle last edge ta kei add korte hobe
    xd = 0;
    dfs_depth(n,0); //proti node thek x er dis jani
    //src theke je node ta cycle toiri korse  sei edge ta jog kore dilei  hobe
    return cycle_dis+xd+1;
}

int solve_no_cycle(int n){
    int st = 0;
    int len = 0;
    while(true){
        //cout<<"mxdis: "<<mxdis<<"\n";
        if(st==n)break;
        st = g[st];
        len++;
    }
    return len+xd;
}

int solve(int n){
    int cyc = dfs_cycle(0,0,n);
    if(cyc==-1){
        //cout<<"no cycle\n";
        xd = 0;
        dfs_depth(n,0);
        //FREP(i,0,n)cout<<xdepth[i]<<" ";
        //cout<<"\n";
        return solve_no_cycle(n);
    }
    else{
        //cout<<"cycle\n";
        return solve_cycle(n,cyc);
    }
}

void takeg(int n){
    xd = 0;
    g.clear();rg.clear();vis.clear();visrev.clear();
    FREP(i,1,n+4){
        VI line;
        g.PB(0); rg.PB(line); vis.PB(0);visrev.PB(0);
    }
    FREP(i,1,n){
        int u;
        scanf("%d",&u);
        if(u==-1)u=n;
        g[i-1]=u; rg[u].PB(i-1);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        takeg(n);
        int ans = solve(n);
        printf("%d\n",ans);
    }
    return 0;
}
