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

vector<VI>g;
int active[1003];
int vis[1003];
int incycle[1003];
int col[1003];

void takeg(int n, int m){
    g.clear();
    FREP(i,1,n+3){
        VI line;
        g.PB(line);
        active[i]=1;
        vis[i]=0;
        incycle[i]=0;
        col[i]=0;
    }
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v);
    }
}

bool reach(int src, int n){
    vis[src]=1;
    if(src==n)return true;
    int dd = g[src].size();
    bool val = false;
    FREP(i,0,dd-1){
        int vv = g[src][i];
        if(!vis[vv] && active[vv]){
            val|=reach(vv,n);
        }
    }
    return val;
}

void dfs1(int src, vector<int> pred){
    col[src]=1;
    int dd = g[src].size();
    FREP(i,0,dd-1){
        int vv = g[src][i];
        if(col[vv]==0){
            pred.PB(src);
            dfs1(vv,pred);
            pred.pop_back();
        }
        else if(col[vv]==1){
            incycle[src]=1;
            for(int k = pred.size()-1;k>=0;--k){
                incycle[pred[k]]=1;
                if(pred[k]==vv)break;
            }
        }
    }
    col[src]=2;
}

vector<int>oka;

void dfs2(int src){
    vis[src]=1;
    oka.PB(src);
    int dd = g[src].size();
    FREP(i,0,dd-1){
        int vv = g[src][i];
        if(vis[vv]==0){
            dfs2(vv);
        }
    }
}

void solve(int n){
    if(!reach(1,n)){
        cout<<"0\n\n";
    }
    else{
        set<int>sz;
        sz.insert(1); sz.insert(n);
        FREP(i,2,n-1){
            memset(vis,0,sizeof(vis));
            active[i]=0;
            if(!reach(1,n))sz.insert(i);
            active[i]=1;
        }
        vector<int>ln;
        dfs1(1,ln);
        set<int>::iterator it;
        for(it = sz.begin(); it!=sz.end();++it){
            if(incycle[*it])sz.erase(it);
        }
        memset(vis,0,sizeof(vis));
        oka.clear();
        dfs2(1);
        cout<<sz.size()<<"\n";
        FREP(i,0,oka.size()-1)if(sz.find(oka[i])!=sz.end())cout<<oka[i]<<" ";
        cout<<"\n";
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        cin>>n>>m;
        takeg(n,m);
        solve(n);
    }
    return 0;
}
