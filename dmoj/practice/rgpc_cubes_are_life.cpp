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

vector <  vector <PII> >g;

int vis[1003];

PII dp[1003];
int dpvis[1003];


int hascycle=0;

void dfs1(int src){
    vis[src]=1;
    int l=g[src].size();
    FREP(i,0,(l-1)){
        int nxt=g[src][i].first;
        if(vis[nxt]==1){
            hascycle=1;
            break;
        }
        else if(vis[nxt]==0){
            dfs1(nxt);
        }
    }
    vis[src]=2;
}

PII solve(int cur, int des){
    if(cur==des){
        return make_pair(0,1);
    }
    if(dpvis[cur]!=-1){
        return dp[cur];
    }
    int l=g[cur].size();
    int mxlen=0;
    int mxvis=0;
    FREP(i,0,(l-1)){
        PII oka=solve(g[cur][i].first,des);
        int len=oka.first;
        int vis=oka.second;
        int curlen=g[cur][i].second+len;
        if(curlen>mxlen){
            mxlen=curlen;
            mxvis=1+vis;
        }
        else if(curlen==mxlen){
            if((1+vis)>mxvis){
                mxvis=1+vis;
            }
        }
    }
    dpvis[cur]=1;
    dp[cur]=make_pair(mxlen,mxvis);
}

void takeg(int n, int m){
    g.clear();
    vector <PII> line;
    FREP(i,0,(n+3)){
        g.PB(line);
    }
    FREP(i,1,m){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        g[u].PB(make_pair(v,w));
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    takeg(n,m);
    memset(vis,-1,sizeof(vis));
    memset(dpvis,-1,sizeof(vis));
    dfs1(1);
    if(vis[n]==0 || hascycle){
        printf("-1\n");
        return 0;
    }
    PII ans=solve(1,des);
    printf("%d %d\n",ans.first,ans.second);
    return 0;
}
