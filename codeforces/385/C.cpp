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

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector < VI >g;

int vis[1005];
int isgov[1005];
int compsize[1005];
int ispar[1005];
int totedg[1005];
int hastoadd[1005];

void takeg(int n, int m){
    VI line;
    FREP(i,0,(n+3))g.PB(line);
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
}

int sim(int i, int n){
    int initnode=ispar[i];
    int initedge=(initnode*(initnode-1))/2-totedg[i];
    FREP(i,1,n){
        if(ispar[i]<0){
            //ere add korbo
            int nd=-ispar[i];
            int possbl=(nd*(nd-1))/2-totedg[i];
            initedge+=possbl;
            initedge+=(initnode*nd);
            initnode+=nd;
        }
    }
    return initedge;
}

PII dfs(int cur){
    int sz=1;
    vis[cur]=1;
    int l=g[cur].size();
    int deg=l;
    FREP(i,0,(l-1)){
        int v=g[cur][i];
        if(!vis[v]){
            PII oka = dfs(v);
            sz+=oka.first;
            deg+=oka.second;
        }
    }
    return make_pair(sz,deg);
}


int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    FREP(i,1,k){
        int a;
        scanf("%d",&a);
        isgov[a]=1;
    }
    takeg(n,m);
   // cout<<"graph input nisi\n";
    FREP(i,1,n){
        if(isgov[i]){
            PII oka=dfs(i);
            ispar[i]=oka.first;
            totedg[i]=oka.second/2;
        }
    }
   // cout<<"govt er dfs chalaisi\n";
    //ekhan theke ber holo jei component er sathe sobdire jog korbo seitar idx ar seitay koyta edg ase, koyta vertex ase
    FREP(i,1,n){
        if(!ispar[i] && !vis[i]){
            PII dd=dfs(i);
            ispar[i]=-dd.first;
            totedg[i]=dd.second/2;
            //int possible=(compsize*(compsize-1))/2;
            hastoadd[i]=1;
        }
    }
   // cout<<"bakider comp calc korsi\n";
    int canadd=0;
    FREP(i,1,n){
        if(ispar[i]>0){
            int gg=sim(i,n);
            if(canadd<gg){
                canadd=gg;
            }
        }
    }
   // cout<<"res ber korsi\n";
    printf("%d\n",canadd);
}

