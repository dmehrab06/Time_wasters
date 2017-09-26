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

int parent[100005];
int depth[100005];
int subtreesize[100005];
int chainno[100005];
int chainhead[100005]; //chain er shurute kon vertex
int segbasearray[100005]; //ekhane thakbe cost
int posinbasearray[100005]; //ekhane bola thakbe kon node er jonno cost basearray er koto no index e
int curchainindex=1;
int curbaseindex=1;
int segtree[600005];
vector < vector <int> >g;

void clearthings(){
    g.clear();
    curchainindex=1;
    curbaseindex=1;
    memset(chainhead,-1,sizeof(chainhead));
}

void init(int l, int r, int curnode){
    if(l>r) return;
    if(l==r){
        if(segbasearray[l]==1)segtree[curnode]=l;
        else segtree[curnode]=-1;
        return;
    }
    int mid=(l+r)/2; int lnode=curnode<<1;  int rnode=lnode+1;
    init(l,mid,lnode);  init(mid+1,r,rnode);
    if(segtree[lnode]!=-1) segtree[curnode]=segtree[lnode];
    else segtree[curnode]=segtree[rnode];
}

void update(int l, int r, int curnode, int idx){
    if(l>r || idx<l || idx>r)return;
    if(l==r && l==idx){
        segbasearray[l]=1-segbasearray[l];
        if(segbasearray[l]==1)segtree[curnode]=l;
        else segtree[curnode]=-1;
        return;
    }
    int mid=(l+r)/2; int lnode=curnode<<1; int rnode=lnode+1;
    update(l,mid,lnode,idx);    update(mid+1,r,rnode,idx);
    if(segtree[lnode]!=-1)  segtree[curnode]=segtree[lnode];
    else segtree[curnode]=segtree[rnode];
}


int query(int l, int r, int curnode, int lq, int rq){
    if(l>r || rq<l || lq>r) return -1;
    if(l>=lq && r<=rq)return segtree[curnode];
    int mid=(l+r)/2;
    int lnode=curnode<<1;int rnode=lnode+1;
    int lans=query(l,mid,lnode,lq,rq);  int rans=query(mid+1,r,rnode,lq,rq);
    if(lans!=-1)return lans;
    return rans;
}

void change(int u, int n){
    int upos=posinbasearray[u];
    update(1,n,1,upos);
}

void HLD(int curnode, int prev){
    if(chainhead[curchainindex]==-1){
        chainhead[curchainindex]=curnode;
    }
    chainno[curnode]=curchainindex;
    posinbasearray[curnode]=curbaseindex;
    segbasearray[curbaseindex]=0;
    curbaseindex++;

    //now find the special child and add to current chain

    int l=g[curnode].size();
    int mx=-1;
    int sc=-1;
    FREP(i,0,(l-1)){
        int nxt=g[curnode][i];
        if(nxt==prev)continue;
        int sz=subtreesize[nxt];
        if(sz>mx){
            mx=sz;
            sc=nxt;
        }
    }

    if(sc!=-1){
        HLD(sc,curnode);
    }

    FREP(i,0,(l-1)){
        int nxt=g[curnode][i];
        if(nxt==prev || nxt==sc)continue;
        curchainindex++;
        HLD(nxt,curnode);
    }
}

void takeg(int n){
    vector<int>line;
    g.clear();
    FREP(i,0,(n+3)){
        g.PB(line);
    }
    FREP(i,2,n){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
}

void dfs(int cur, int prev, int _depth=0){
    subtreesize[cur]=1; parent[cur]=prev; depth[cur]=_depth;
    int l=g[cur].size();
    FREP(i,0,(l-1)){
        int nxt=g[cur][i];
        if(nxt==prev)continue;
        dfs(nxt,cur,_depth+1);
        subtreesize[cur]+=subtreesize[nxt];
    }
}

int hldquery(int u, int v, int n){
    //v upore ache karon v lca
    int uchain=chainno[u];
    int vchain=chainno[v];

    if(uchain==vchain){
        //era ek e chain e so segtree te era ekta range er vitor ache just sekhan theke return koro
        int posu=posinbasearray[u];
        int posv=posinbasearray[v];
        return query(1,n,1,posv,posu); //ulta kore karon segtree te oivabe ache
    }
    //naile alada chain e jete hobe
    int uhead=chainhead[uchain];
    int headpos=posinbasearray[uhead];
    int posu=posinbasearray[u]; //head ar u ek chain e ei tukur ta ber kore tarpor next chain e jaite hobe
    int tmp=query(1,n,1,headpos,posu);
    u=parent[uhead]; //chain change hoilo
    int prevans=hldquery(u,v,n);
    if(prevans!=-1)return prevans;
    return tmp;
}

int getans(int u, int n){
    return hldquery(u,1,n);
}


void printsegtree(int l, int r, int curnode){
    if(l>r)return;
    if(l==r){
        printf("in range %d %d : %d\n",l,r,segtree[curnode]);
        return;
    }
    int mid=(l+r)/2;
    int lnode=curnode<<1;
    int rnode=lnode+1;
    printf("in range %d %d : %d\n",l,r,segtree[curnode]);
    printsegtree(l,mid,lnode);
    printsegtree(mid+1,r,rnode);
}

char str[10];

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(cs<=t){
        clearthings();
        int n,q;
        scanf("%d %d",&n,&q);
        takeg(n);
        dfs(1,-1); //subtree size ber hobe, parent ber hobe
        HLD(1,-1); //chain toiri hoilo, segtree er jonno base array toiri hoilo
        /*FREP(i,1,n){
            printf("chain no of %d: %d\n",i,chainno[i]);
            printf("chain head of this chain: %d\n",chainhead[chainno[i]]);
        }*/
        init(1,n,1); //segtree toiri hoilo
        int type;
        while(q--){
            scanf("%d",&type);
            if(type==0){
                int idx;
                scanf("%d",&idx);
                change(idx,n);
            }
            else{
                int v;
                scanf("%d",&v);
                printf("%d\n",getans(v,n));
            }

        }
    }
    return 0;
}
