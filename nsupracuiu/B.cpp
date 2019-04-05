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

vector < VI >g;

int vis[2503];

void init(int n){
    g.clear();
    FREP(i,1,(n+4)){
        VI line;
        g.PB(line);
    }
}

void makeg(int n){
    FREP(i,1,n){
        int num;
        scanf("%d",&num);
        FREP(j,1,num){
            int v;
            scanf("%d",&v);
            g[i-1].PB(v); //g[v].PB(i-1);
        }
    }
}

pair<int,int> solve(int n){
    int day[2503]; MSET(day,0);
    int mxd = -1;
    FREP(i,0,(n-1)){
        int d = vis[i];
        day[d]++;
        mxd = max(mxd,d);
    }
    int mxx = 0, d = -1;
    FREP(i,1,mxd){
        if(day[i]>mxx){
            mxx = day[i];
            d = i;
        }
    }
    return make_pair(mxx,d);
}

void bfs(int src){
    MSET(vis,-1);
    vis[src] = 0;
    queue<int>bfsq;
    bfsq.push(src);
    while(!bfsq.empty()){
        int t = bfsq.front();
        bfsq.pop();
        FREP(i,0,g[t].size()-1){
            int v = g[t][i];
            if(vis[v]==-1){
                vis[v] = vis[t]+1;
                bfsq.push(v);
            }
        }
    }
    return;
}

int main(){
    int e;
    scanf("%d",&e);
    init(e);
    makeg(e);
    int t;
    scanf("%d",&t);
    while(t--){
        int s; scanf("%d",&s);
        bfs(s);
        PII ans = solve(e);
        if(ans.second==-1){
            printf("%d\n",ans.first);
        }
        else{
            printf("%d %d\n",ans.first,ans.second);
        }
    }
    return 0;
}
