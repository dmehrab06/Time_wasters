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

int col[100005];

int node[200005];

int deg[200005];

vector<VI>g;

void dfs(int cur, int par){
    int l=g[cur].size();
    FREP(i,0,(l-1)){
        int nxt=g[cur][i];
        if(nxt==par)continue;
        dfs(nxt,cur);
        if(col[nxt]==col[cur]){
            int hisdeg=deg[nxt];
            deg[nxt]=0;
            deg[cur]-=1;
            deg[cur]+=(hisdeg-1);
        }
    }
    return;
}

void takeg(int n){
    g.clear();
    VI line;
    FREP(i,0,(n+3))g.PB(line);
    FREP(i,1,(n-1)){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
        deg[u]++;
        deg[v]++;
    }
}

int dfscolor(int cur, int par){
    int l=g[cur].size();
    int ret=0;
    FREP(i,0,(l-1)){
        int nxt=g[cur][i];
        if(nxt==par)continue;
        if(col[nxt]!=col[cur]){
            ret=1;
        }
        ret|=dfscolor(nxt,cur);
    }
    return ret;
}

int can(int n){
    int greaterthanone=0;
    int activenode=0;
    int root=1;
    int node1=-1;
    int node2=-1;
    FREP(i,1,n){
        if(deg[i]>1){
            greaterthanone++;
            root=i;
        }
        if(deg[i]>0){
            activenode++;
            if(node1==-1){
                node1=i;
            }
            else if(node2==-1){
                node2=i;
            }
        }
    }
    //cout<<activenode<<"\n";
    if(greaterthanone<=1){
        if(activenode==2){
            int l1=g[node1].size();
            int ret=0;
            FREP(i,0,(l1-1)){
                ret=ret|(dfscolor(g[node1][i],node1));
            }
            if(ret==0){
                return node1;
            }
            int l2=g[node2].size();
            ret=0;
            FREP(i,0,(l2-1)){
                ret=ret|(dfscolor(g[node2][i],node2));
            }
            if(ret==0){
                return node2;
            }
        }
        else return root;
    }
    else{
        return -1;
    }
}


int main(){
    int n;
    scanf("%d",&n);
    takeg(n);
    FREP(i,1,n){
        scanf("%d",&col[i]);
    }
    dfs(1,0);
    int ans=can(n);
    if(ans==-1){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        printf("%d\n",ans);
    }
    return 0;
}
