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
using namespace std;
using namespace __gnu_pbds;
#define MDD 1000000007
#define FEMSIZE 200005

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector < VI > g;

LLI vals[200005];

int twopow[32];

int height = 0;

vector<LLI>xors;

void dfs_height(int src, int par, int lev){
    height = max(height,lev);
    int  l = g[src].size();
    FREP(i,0,(l-1)){
        int v = g[src][i];  if(par==v)continue;
        dfs_height(v,src,lev+1);
    }
}



int gettwopow(){
    int lo = 0;
    int hi = 31;
    while(true){
        int mid = (lo+hi)/2;
        int val = twopow[mid];
        if(val>height){
            if(mid>0 && twopow[mid-1]>height){
                hi = mid;
            }
            else{
                return twopow[mid];
            }
        }
        else{
            lo  = mid+1;
        }
    }
}

void takeg(int n){

    twopow[0]=1;
    FREP(i,1,31)twopow[i] = twopow[i-1]*2;
    g.clear();xors.clear();
    FREP(i,1,(2*n+2)){
        VI line;
        g.PB(line); xors.PB(0);
    }
    FREP(i,1,n-1){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v); g[v].PB(u);
    }
    FREP(i,1,n){
        scanf("%lld",&vals[i-1]);
    }
}

void dfs(int src, int par){
    int l = g[src].size();
    LLI nowxor = vals[src];
    FREP(i,0,(l-1)){
        int v = g[src][i]; if(par==v)continue;
        dfs(v,src);
        nowxor = nowxor^vals[v];
    }
    vals[src] = nowxor;
    return;
}

void go(int day, int n){
    xors[0]=vals[0];
    FREP(i,1,day){
        dfs(0,-1);
        xors[i]=vals[0];
        /*cout<<"after day "<<i<<"\n";
        FREP(i,0,(n-1)){
            cout<<vals[i]<<" ";
        }
        cout<<"\n";*/
    }
}

void solve(int n, int q){
    dfs_height(0,-1,0);
    //cout<<height<<"\n";
    int mxday = gettwopow();
    //cout<<mxday<<"\n";
    go(mxday,n);
    FREP(i,1,q){
        LLI day;
        scanf("%lld",&day);
        LLI vv = day%(LLI)mxday;
        int v = (int)vv;
        printf("%lld\n",xors[v]);
    }
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    takeg(n);
    solve(n,q);
    return 0;
}
