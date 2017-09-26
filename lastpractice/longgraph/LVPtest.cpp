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

VI color; //for cycle checking
VI xdepth;

VI vis; //for rg;

int dfs_cycle(int src, int dis, int n){
    if(src==n)return -1; //cycle nai src theke
    color[src]=1;
    int v = g[src];
    if(color[v]==0){
        return dfs_cycle(v,dis+1,n);
    }
    else if(color[v]==1){
        return dis;
    }
    color[src]=2;
    return -1;
}

void dfs_depth(int cur, int dis){
    vis[cur]=1;
    xdepth[cur]=dis;
    int l = rg[cur].size();
    FREP(i,0,(l-1)){
        int v = rg[cur][i];
        if(!vis[v])dfs_depth(v,dis+1);
    }
    return;
}

int solve_cycle(int n, int cycle_dis){
    //cycle thakle last edge ta kei add korte hobe
    dfs_depth(n,0); //proti node thek x er dis jani
    //src theke je node ta cycle toiri korse  sei edge ta jog kore dilei  hobe
    int mxx = -1000000;
    FREP(i,0,n)mxx = max(mxx,xdepth[i]);
    return cycle_dis+mxx+1;
}

int solve_no_cycle(int n){
    set<PII>xds;
    FREP(i,0,(n)){
        xds.insert(make_pair(-xdepth[i],i));
        cout<<xdepth[i]<<" "<<i<<"\n";
    }
    int mxdis = -1;
    int st = 0;
    int dis = 0;
    set<PII>::iterator it;
    while(true){
        if(st==n)break;
        cout<<"st: "<<st<<"\n";
        PII tofind = make_pair(-xdepth[st],st);
        xds.erase(tofind);
        it = xds.begin(); int dis2 = -((*it).first); int nd = (*it).second;
        cout<<dis2<<" "<<nd<<"\n";
        cout<<dis2<<" "<<dis<<"\n";
        mxdis = max(mxdis,dis2+dis+1);
        cout<<"mxdis: "<<mxdis<<"\n";
        dis++;
        st = g[st];
    }
    return mxdis;
}

int solve(int n){
    int cyc = dfs_cycle(0,0,n);
    if(cyc==-1){
        cout<<"no cycle\n";
        dfs_depth(n,0);
        FREP(i,0,n)cout<<xdepth[i]<<" ";
        cout<<"\n";
        return solve_no_cycle(n);
    }
    else{
        cout<<"cycle\n";
        return solve_cycle(n,cyc);
    }
}

void takeg(int n){
    g.clear();rg.clear();color.clear();xdepth.clear();vis.clear();
    FREP(i,1,n+4){
        VI line;
        g.PB(0); rg.PB(line);color.PB(0); xdepth.PB(-1000000);vis.PB(0);
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
