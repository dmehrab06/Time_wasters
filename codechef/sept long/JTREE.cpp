#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;


LLI segtree[600005];
LLI ans[200005];
vector< vector < PII >  >tickets;

//b1 ar e1 hoilo row

//b2 ar e2 hoilo column
vector<VI>edges;
int N;


void init(int b, int e, int node){
    //cout<<"aschi\n";
    //cout<<b1<<" "<<b2<<" "<<e1<<" "<<e2<<" "<<node<<"\n";
    if(b==e){
        if(b!=1)segtree[node]=MXX;
        else{
            segtree[node]=0;
        }
        return;
    }
    if(b>e)return;
    else{
  //  printf("in node %d, range %d to %d\n",node,b,e);
        int lt=node<<1;
        int rt=lt+1;
        int mid=(b+e)>>1;
        init(b,mid,lt);
        init(mid+1,e,rt);
        LLI mx1=min(segtree[lt],segtree[rt]);
        segtree[node]=mx1;
        return;
    }
}

LLI query(int i, int j, int b, int e, int node){
    //int cur=0;
    if(b>=i && e<=j){
        //cur=segtree[node];
        return segtree[node];
    }
    if(e<i || b>j){
        return MXX;
    }
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    LLI leftinfo=query(i,j,b,mid,lt);
    LLI rightinfo=query(i,j,mid+1,e,rt);
    return min(leftinfo,rightinfo);
}

void update(int i,int b,int e, int node, LLI val){
    if(b==i && e==i){
        if(b!=1)segtree[node]=val;
        return;
    }
    if(e<i || b>i){
        return;
    }
    //if(b1>e1 || b2>e2)return;
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    update(i,b,mid,lt,val);
    update(i,mid+1,e,rt,val);
    //segtree[node]=segtree[left]+segtree[right];
    LLI mx1=min(segtree[lt],segtree[rt]);
    segtree[node]=mx1;
    return;
}

void dfs(int curnode, int depth){
    int d;
    if(depth!=1){
        d=tickets[curnode].size();
        if(d==0){
            update(depth,1,N,1,MXX);
            ans[curnode]=MXX;
        }
        else{
            LLI mnn=MXX;
            FREP(i,0,(d-1)){
                LLI curcost=tickets[curnode][i].first;
                LLI l=max(1,depth-tickets[curnode][i].second);
                LLI r=max(1,depth-1);
                LLI get=query(l,r,1,N,1);
                LLI cc=get+curcost;
                mnn=min(cc,mnn);
            }
            update(depth,1,N,1,mnn);
            ans[curnode]=mnn;
        }
    }
    d=edges[curnode].size();
    FREP(i,0,(d-1)){
        int nxt=edges[curnode][i];
        dfs(nxt,depth+1);
    }
    return;
}

int main(){
    int M,Q;
    scanf("%d %d",&N,&M);
    init(1,N,1);
    VI line;
    FREP(i,1,(N+3))edges.PB(line);
    FREP(i,1,(N-1)){
        int u,v;
        scanf("%d %d",&u,&v);
        edges[v].push_back(u);
    }
    vector< pair<int,int> >line2;

    FREP(i,1,N+3){
        tickets.push_back(line2);
    }
    FREP(i,1,M){
        int node,k,cost;
        scanf("%d %d %d",&node,&k,&cost);
        pair <int,int> pp=make_pair(cost,k);
        tickets[node].push_back(pp);
    }
    dfs(1,1);
    scanf("%d",&Q);
    FREP(i,1,N){
        printf("%d: %lld\n",i,ans[i]);
    }
    FREP(i,1,Q){
        int nd;
        scanf("%d",&nd);
        printf("%lld\n",ans[nd]);
    }
    return 0;
}
