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

vector< VI >g;

int vis[300005];
int letcnt[30][300005];
int cycle = 0;
int letnode[300005];
int indeg[300005];

void init(){
    MSET(vis,0);
    MSET(letcnt,0);
}

void dfs(int cur){
    if(cycle==1)return;
    vis[cur] = 1;
    //letcnt[letnode[cur]][cur]+=1;
    FREP(i,0,g[cur].size()-1){
        int v = g[cur][i];
        if(vis[v]==1){
            cycle = 1;
            break;
        }
        else if(vis[v]==0){
            dfs(v);
            FREP(k,0,25){
                letcnt[k][cur]=max(letcnt[k][cur],letcnt[k][v]);
            }
        }
        else if(vis[v]==2){
            FREP(k,0,25){
                letcnt[k][cur]=max(letcnt[k][v],letcnt[k][cur]);
            }
        }
    }
    letcnt[letnode[cur]][cur]+=1;
    vis[cur] = 2;
}

char ss[300005];

void takeinp(int n, int m){
    scanf("%s",ss);
    FREP(i,1,n){
        letnode[i] = ss[i-1]-'a';
    }
    g.clear();
    FREP(i,1,(n+3)){
        VI line;
        g.PB(line);
    }
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v);
        indeg[v]++;
    }
}

int solve(int n){
    /*int ff = 0;
    FREP(i,1,n){
        if(indeg[i]==0){
            ff = 1;
            break;
        }
    }*/
    /*if(ff==0){
        cycle = 1;
        return -1;
    }*/
    FREP(i,1,n){
        if(vis[i]==0){
            dfs(i);
        }
        if(cycle==1)break;
    }
    int mxx = 0;
    FREP(i,1,n){
        FREP(j,0,25){
            mxx = max(mxx,letcnt[j][i]);
        }
    }
    return mxx;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    init();
    takeinp(n,m);
    int ans = solve(n);
    if(cycle==1){
        printf("-1\n");
    }
    else{
        printf("%d\n",ans);
    }
    return 0;
}
