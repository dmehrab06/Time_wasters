
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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector < vector <int> >orig_graph;

vector <PII> edge_in_dfs_tree;

vector < int > fin_ans;

vector < vector <int> >dfs_tree_graph;

int visited[100005];
int orig_deg[100005];

void init(int n){
    memset(visited,0,sizeof(visited));
    memset(orig_deg,0,sizeof(orig_deg));
    edge_in_dfs_tree.clear();
    orig_graph.clear();
    fin_ans.clear();
    dfs_tree_graph.clear();
    FREP(i,0,(n+3)){
        VI line;
        orig_graph.PB(line);
        dfs_tree_graph.PB(line);
        fin_ans.PB(0);
    }
}

void takegraph(int m){
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        orig_graph[u].PB(v);
        orig_graph[v].PB(u);
        orig_deg[u]++;
        orig_deg[v]++;
    }
}

void dfs(int src){
    visited[src]=1;
    int ll=orig_graph[src].size();
    FREP(i,0,ll-1){
        int nxt = orig_graph[src][i];
        if(!visited[nxt]){
            dfs_tree_graph[src].PB(nxt);
            dfs_tree_graph[nxt].PB(src);
            dfs(nxt);
            PII edg = make_pair(src,nxt);
            edge_in_dfs_tree.PB(edg);
        }
    }
    return;
}

void getcompnumber(int n){
    int comp = 0;
    FREP(i,1,n){
        if(!visited[i]){
            dfs(i);
            comp++;
        }
    }
    fin_ans[0]=comp-1;
}

void getans(int node){
    int curdeg = orig_deg[node];
    //cout<<"for node "<<node<<" degree is: "<<curdeg<<"\n";
    int ll = dfs_tree_graph[node].size();
    int cnt = 0;
    FREP(i,0,ll-1){
        int neigh = dfs_tree_graph[node][i];
        int neighdeg = orig_deg[neigh];
        if(neighdeg >= curdeg){
            cnt++;
        }
    }
    //cout<<"found neighbors "<<cnt<<"\n";
    fin_ans[curdeg]+=cnt;
}

void getcumsum(int n){
    FREP(i,1,(n-1)){
       // printf("%d ",fin_ans[i]);
        fin_ans[i]+=fin_ans[i-1];
    }
    //printf("\n");
}

void final_check(){
    int ll = edge_in_dfs_tree.size();
    FREP(i,0,(ll-1)){
        PII curedge = edge_in_dfs_tree[i];
        int node1 = curedge.first;
        int node2 = curedge.second;
        if(orig_deg[node1] == orig_deg[node2]){
            fin_ans[orig_deg[node1]]--;
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        init(n);
        takegraph(m);
        getcompnumber(n);
        FREP(i,1,n){
            getans(i);
        }
        final_check();
        getcumsum(n);
        FREP(i,0,(n-1)){
            printf("%d ",fin_ans[i]);
        }
        printf("\n");
    }
    return 0;
}
