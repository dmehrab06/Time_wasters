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
#define MDD 1000003
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<VI>g;
vector<VI>g2;
int vis[20003];
int indegree[20003];
set<int>ans;
int hasto[20003];

void init(int n){
    g.clear();
    g2.clear();
    ans.clear();
    VI line;
    FREP(i,0,(n+3)){
        g.PB(line);
        g2.PB(line);
    }
    memset(vis,-1,sizeof(vis));
    memset(hasto,0,sizeof(hasto));
    memset(indegree,0,sizeof(indegree));
}

void takeg(int n){
    FREP(i,1,n){
        int deg;
        scanf("%d",&deg);
        FREP(j,1,deg){
            int v;
            scanf("%d",&v);
            g[i].PB(v);
            g2[v].PB(i);
            indegree[i]++;
        }
    }
}

int dfs(int cur){
    if(vis[cur]!=-1)return vis[cur];
    int l=g[cur].size();
    int mx=0;
    FREP(i,0,(l-1)){
        int nxt=g[cur][i];
        mx=max(mx,dfs(nxt));
    }
    return vis[cur]=mx+1;
}

int main(){
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        int n,m;
        scanf("%d %d",&n,&m);
        init(n);
        takeg(n);
        FREP(i,1,m){
            int v;
            scanf("%d",&v);
            hasto[v]=1;
            dfs(v);
        }
        FREP(i,1,n){
            if(vis[i]!=-1 && indegree[i]==0){
                ans.insert(i);
            }
        }
        int installed=0;
        set<int>::iterator it;
        VI printans;
        while(installed<m){
            it=ans.begin();
            int cur=*it;
            ans.erase(cur);
            printans.PB(cur);
            if(hasto[cur]==1){
                hasto[cur]=0;
                installed++;
            }
            int deg=g2[cur].size();
            FREP(k,0,(deg-1)){
                int v=g2[cur][k];
                indegree[v]--;
                if(indegree[v]==0 && vis[v]!=-1){
                    ans.insert(v);
                }
            }
        }
        int sz=printans.size();
        printf("%d\n",sz);
        FREP(i,0,(sz-1)){
            printf("%d ",printans[i]);
        }
        printf("\n");
    }
    return 0;
}
