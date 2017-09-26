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

//--debugging func---//

void printv(VI oka){
    int l=oka.size();
    FREP(i,0,(l-1)){
        cout<<oka[i]<<" ";
    }
    cout<<"\n";
}

void printvv(vector<VI>oka){
    int l=oka.size();
    FREP(i,0,(l-1))printv(oka[i]);
    cout<<"\n";
}

//--debugging func---//


int vis[200005];
int col[200005];

int maxdepth=0;

int newcol[200005];
int chain1[200005];
int chain2[200005];
int maxdis[200005];

vector <VI> edg;

vector <VI> newedg;

void dfs(int cur, int par, int color){
    vis[cur]=1;
    int l=edg[cur].size();
    FREP(i,0,(l-1)){
        int v=edg[cur][i];
        if(!vis[v]){
            if(col[v]!=color){
                newedg[v].PB(par);
                newedg[par].PB(v);
                dfs(v,v,col[v]);
            }
            else{
                dfs(v,par,color);
            }
        }
    }
    newcol[par]=color;
    return;
}

void newdfs(int cur){
    vis[cur]=1;
    chain1[cur]=-1;
    chain2[cur]=-1;
    maxdis[cur]=0;
    //if(d>maxdepth)maxdepth=d;
    int l=newedg[cur].size();
    FREP(i,0,(l-1)){
        int v=newedg[cur][i];
        if(!vis[v]){
            newdfs(v);
            //chain[cur]=max(chain[cur],1+chain[newedg[cur][i]]);
            if((1+chain1[v])>chain1[cur]){
                chain2[cur]=chain1[cur];
                chain1[cur]=1+chain1[v];
            }
            else if((1+chain1[v])>chain2[cur]){
                chain2[cur]=1+chain1[v];
            }
            maxdis[cur]=max(maxdis[cur],maxdis[v]);
        }
    }
    maxdis[cur]=max(maxdis[cur],2+chain1[cur]+chain2[cur]);
    maxdepth=max(maxdis[cur],maxdepth);
    return;
}

void takeg(int n, int m){
    edg.clear();
    newedg.clear();
    VI line;
    FREP(i,1,n){
        scanf("%d",&col[i]);
    }
    memset(vis,0,sizeof(vis));
    memset(newcol,-1,sizeof(newcol));
    FREP(i,1,(n+2)){
        newedg.PB(line);
        edg.PB(line);
    }
    FREP(i,1,m){
        int u,v;//--debugging func---//
        scanf("%d %d",&u,&v);
        edg[u].PB(v);
        edg[v].PB(u);
    }
}


int main(){
    int n;
    scanf("%d",&n);
    takeg(n,(n-1));
    dfs(1,1,col[1]);
    //printvv(newedg);
    memset(vis,0,sizeof(vis));
    newdfs(1);


   // int w=cntwhite(n,0);
   // int b=cntwhite(n,1);
    cout<<(maxdepth+1)/2<<"\n";
    return 0;
}
