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



int representative[200005];

int cntcomponent[200005];

int visited[200005];

vector < vector <int> >g;

vector < int > componentorder;

vector < LLI > componentorderprefix;

LLI forhis[200005];

void calcforhis(){
    forhis[1]=0;
    FREP(i,2,200004){
        forhis[i] = (LLI) i*(i-1);
        forhis[i] += forhis[i-1];
    }
}

void init(){
    g.clear();
    componentorder.clear();
    componentorderprefix.clear();
    memset(visited,0,sizeof(visited));
    memset(cntcomponent,0,sizeof(cntcomponent));
    memset(representative,0,sizeof(representative));
}

int dfs(int cur){
    visited[cur]=1;
    int l=g[cur].size();
    int sz=1;
    FREP(i,0,(l-1)){
        int nxt=g[cur][i];
        if(!visited[nxt]){
            sz+=dfs(nxt);
        }
    }
    return sz;
}

void takeg(int n, int m){
    VI line;
    FREP(i,0,(n+3)){
        g.push_back(line);
    }
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
}

void calcgroup(int n, int m){
    FREP(i,1,n){
        if(!visited[i]){
            int cmphere=dfs(i);
            cntcomponent[i]=cmphere;
            componentorder.PB(-cmphere);
        }
    }
    sort(componentorder.begin(),componentorder.end());
    int ll=componentorder.size();
    int totaledgeconsidered=0;
    FREP(i,0,(ll-1)){
        componentorder[i]=componentorder[i]*(-1);
        totaledgeconsidered+=(componentorder[i]-1);
    }
    int left=m-totaledgeconsidered;
    componentorder.PB(left+1);
}

void calccomporderprefix(){
    componentorderprefix.PB( (LLI)0);
    int cursz=0;
    int ll=componentorder.size();
    FREP(i,1,(ll-1)){
        int chilo=componentorder[i-1];
        LLI joghobe= (LLI) (chilo)*(chilo-1);
        componentorderprefix.PB(joghobe);
        cursz++;
        componentorderprefix[cursz]+=componentorderprefix[cursz-1];
    }
}

LLI thealgo(){
    int ll=componentorder.size();
    LLI ans=0;
    FREP(i,0,(ll-1)){
       // cout<<"at "<<i<<" "<<componentorder[i]<<"\n";
        if(i<(ll-1))ans+=forhis[componentorder[i]];
       // cout<<"nijer jonno add holo "<<forhis[componentorder[i]]<<"\n";
        ans+=((LLI)(componentorder[i]-1)*(componentorderprefix[i]));
       // cout<<"aro jog hobe "<<componentorderprefix[i]<<", "<<componentorder[i]-1<<" bar\n";
       // cout<<"ekhon ans "<<ans<<"\n";
    }
    return ans;
}

int main(){
    int q;
    calcforhis();
    scanf("%d",&q);
    while(q--){
        init();
        int n,m;
        scanf("%d %d",&n,&m);
        takeg(n,m);
        calcgroup(n,m);
        calccomporderprefix();
        LLI ans=thealgo();
        printf("%lld\n",ans);
    }
    return 0;
}


