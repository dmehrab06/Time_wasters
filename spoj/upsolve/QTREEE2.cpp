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

int ancestor[20][100005];
int parent[100005];
int depth[100005];
int subtreesize[100005];
int chainno[100005]; //node in which chain
int chainhead[100005]; //chain er shurute kon vertex
int segbasearray[100005]; //ekhane thakbe cost
int posinbasearray[100005]; //ekhane bola thakbe kon node er jonno cost basearray er koto no index e
int basearraynodes[100005]; //posinbasearray er thik ulta jinis ta thakbe
int curchainindex=1;
int curbaseindex=1;
LLI segtree[600005];
vector < vector <PII> >g;

void clearthings(){
    g.clear();
    curchainindex=1;
    curbaseindex=1;
    memset(ancestor,-1,sizeof(ancestor));
    memset(chainhead,-1,sizeof(chainhead));
}

void init(int l, int r, int curnode){
    if(l>r){
        return;
    }
    if(l==r){
        segtree[curnode]=segbasearray[l];
        return;
    }
    int mid=(l+r)/2;
    int lnode=curnode<<1;
    int rnode=lnode+1;
    init(l,mid,lnode);
    init(mid+1,r,rnode);
    segtree[curnode]=segtree[lnode]+segtree[rnode];
}


LLI query(int l, int r, int curnode, int lq, int rq){
    if(l>r || rq<l || lq>r){
        return 0;
    }
    if(l>=lq && r<=rq){
        return segtree[curnode];
    }
    int mid=(l+r)/2;
    int lnode=curnode<<1;
    int rnode=lnode+1;
    LLI lans=query(l,mid,lnode,lq,rq);
    LLI rans=query(mid+1,r,rnode,lq,rq);
    return lans+rans;
}

void HLD(int curnode, int cost, int prev){
    if(chainhead[curchainindex]==-1){
        chainhead[curchainindex]=curnode;
    }
    chainno[curnode]=curchainindex;
    posinbasearray[curnode]=curbaseindex;
    basearraynodes[curbaseindex]=curnode;
    segbasearray[curbaseindex]=cost;
    curbaseindex++;

    //now find the special child and add to current chain

    int l=g[curnode].size();
    int mx=-1;
    int sc=-1;
    int sccost=-1;
    FREP(i,0,(l-1)){
        int nxt=g[curnode][i].first;
        if(nxt==prev)continue;
        int sz=subtreesize[nxt];
        if(sz>mx){
            mx=sz;
            sc=nxt;
            sccost=g[curnode][i].second;
        }
    }

    if(sc!=-1){
        HLD(sc,sccost,curnode);
    }

    FREP(i,0,(l-1)){
        int nxt=g[curnode][i].first;
        int nxtcost=g[curnode][i].second;
        if(nxt==prev || nxt==sc){
            continue;
        }
        curchainindex++;
        HLD(nxt,nxtcost,curnode);
    }
}

void takeg(int n){
    vector<PII>line;
    g.clear();
    FREP(i,0,(n+3)){
        g.PB(line);
    }
    FREP(i,2,n){
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        PII oka1=make_pair(v,c);
        PII oka2=make_pair(u,c);
        g[u].PB(oka1);
        g[v].PB(oka2);
    }
}

void dfs(int cur, int prev, int _depth=0){
    subtreesize[cur]=1;
    parent[cur]=prev;
    depth[cur]=_depth;
    int l=g[cur].size();
    FREP(i,0,(l-1)){
        int nxt=g[cur][i].first;
        if(nxt==prev)continue;
        dfs(nxt,cur,_depth+1);
        subtreesize[cur]+=subtreesize[nxt];
    }
}

int LCA(int u, int v, int ln) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	FREP(i,0,(ln-1)){
        if((diff>>i)&1){
            u=ancestor[i][u];
        }
	}
	if(u == v) return u;
	RFREP(i,(ln-1),0){
        if(ancestor[i][u]!=ancestor[i][v]){
            u=ancestor[i][u];
            v=ancestor[i][v];
        }
	}
	return ancestor[0][u];
}

void precalc(int ln, int n){
    FREP(j,1,n){
        ancestor[0][j]=parent[j];
    }
    FREP(i,1,(ln-1)){
        FREP(j,1,n){
            if(ancestor[i-1][j]!=-1){
                ancestor[i][j]=ancestor[i-1][ancestor[i-1][j]];
            }
        }
    }
}

LLI hldsumquery(int u, int v, int n){
    //v upore ache karon v lca
    int uchain=chainno[u];
    int vchain=chainno[v];

    if(uchain==vchain){
        //era ek e chain e so segtree te era ekta range er vitor ache just sekhan theke return koro
        int posu=posinbasearray[u];
        int posv=posinbasearray[v];
        return query(1,n,1,posv+1,posu); //ulta kore karon segtree te oivabe ache
    }
    //naile alada chain e jete hobe
    int uhead=chainhead[uchain];
    int headpos=posinbasearray[uhead];
    int posu=posinbasearray[u]; //head ar u ek chain e ei tukur ta ber kore tarpor next chain e jaite hobe
    LLI tmp=query(1,n,1,headpos,posu);
    u=parent[uhead]; //chain change hoilo
    LLI nxtans=hldsumquery(u,v,n);
    return tmp+nxtans;
}

LLI getsumans(int u, int v, int n){
    int lca=LCA(u,v,18);
   // printf("lca of %d and %d is %d\n",u,v,lca);
    LLI ans1=hldsumquery(u,lca,n);
    LLI ans2=hldsumquery(v,lca,n);
    return ans1+ans2;
}

int kthfound;

int cntnodes(int u, int v){
    int uchain=chainno[u];
    int vchain=chainno[v];

    if(uchain==vchain){
        int posu=posinbasearray[u];
        int posv=posinbasearray[v];
        return (posu-posv+1);
    }
    int uhead=chainhead[uchain];
    int poshead=posinbasearray[uhead];
    int posu=posinbasearray[u];
    return (posu-poshead+1)+cntnodes(parent[uhead],v);
}

int hldkthqueryleft(int u, int v, int curlowval, int k, int n){
    //v upore ache karon v lca
    int uchain=chainno[u];
    int vchain=chainno[v];

    if(uchain==vchain){
        //era ek e chain e so segtree te era ekta range er vitor ache just sekhan theke return koro
        int posu=posinbasearray[u];
        int posv=posinbasearray[v];
        int total=(posu-posv)+1;
        if(k<=(curlowval+total-1) && k>=curlowval){
            kthfound=1;
            int dif=(k-curlowval);
            return basearraynodes[posu-dif];
        }
        return -1; //ulta kore karon segtree te oivabe ache
    }
    //naile alada chain e jete hobe
    int uhead=chainhead[uchain];
    int headpos=posinbasearray[uhead];
    int posu=posinbasearray[u]; //head ar u ek chain e ei tukur ta ber kore tarpor next chain e jaite hobe
    int total=(posu-headpos)+1;
    if(k<=(curlowval+total-1) && k>=curlowval){
        kthfound=1;
        int dif=(k-curlowval);
        return basearraynodes[posu-dif];
    }
    else{
        u=parent[uhead];
        return hldkthqueryleft(u,v,curlowval+total,k,n);
    }
}

int hldkthqueryright(int u, int v, int curlowval, int k, int n){
    //v upore ache karon v lca
    int uchain=chainno[u];
    int vchain=chainno[v];

    if(uchain==vchain){
        //era ek e chain e so segtree te era ekta range er vitor ache just sekhan theke return koro
        int posu=posinbasearray[u];
        int posv=posinbasearray[v];
        int total=(posu-posv)+1;
        if(k>=(curlowval-total+1) && k<=curlowval){
            kthfound=1;
            int dif=(curlowval-k);
            return basearraynodes[posu-dif];
        }
        return -1; //ulta kore karon segtree te oivabe ache
    }
    //naile alada chain e jete hobe
    int uhead=chainhead[uchain];
    int headpos=posinbasearray[uhead];
    int posu=posinbasearray[u]; //head ar u ek chain e ei tukur ta ber kore tarpor next chain e jaite hobe
    int total=(posu-headpos)+1;
    if(k>=(curlowval-total+1) && k<=curlowval){
        kthfound=1;
        int dif=(curlowval-k);
        return basearraynodes[posu-dif];
    }
    else{
        u=parent[uhead];
        return hldkthqueryright(u,v,curlowval-total,k,n);
    }
}


int getkthans(int u, int v, int n, int k){
    int lca=LCA(u,v,18);
    kthfound=0;
   // printf("lca of %d and %d is %d\n",u,v,lca);
   int cntleft=cntnodes(u,lca);
    int cntright=cntnodes(v,lca);
    int tot=cntleft+cntright-1;
    if(k>tot){
        return v;
    }
    int ans1=hldkthqueryleft(u,lca,1,k,n);
    if(kthfound==1)return ans1;
    int ans2=hldkthqueryright(v,lca,tot,k,n);
    if(kthfound==1)return ans2;
    //return 0;
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
        int n;
        scanf("%d",&n);
        takeg(n);
        dfs(1,-1); //subtree size ber hobe, parent ber hobe
        precalc(18,n); //lca er jonno precalc
        HLD(1,-1,-1); //chain toiri hoilo, segtree er jonno base array toiri hoilo
        /*FREP(i,1,n){
            printf("chain no of %d: %d\n",i,chainno[i]);
            printf("chain head of this chain: %d\n",chainhead[chainno[i]]);
        }*/
        init(1,n,1); //segtree toiri hoilo
        while(scanf("%s",str)==1){
            if(str[0]=='D' && str[1]=='O'){
                break;
            }
            else if(str[0]=='D' && str[1]=='I'){
                int u,v;
                scanf("%d %d",&u,&v);
                LLI ans=getsumans(u,v,n);
                printf("%lld\n",ans);
            }
            else if(str[0]=='K'){
                int u,v,k;
                scanf("%d %d %d",&u,&v,&k);
                int ans=getkthans(u,v,n,k);
                printf("%d\n",ans);
            }
            //printsegtree(1,n,1);

        }
        if(cs!=t)printf("\n");
        cs++;
    }
    return 0;
}
