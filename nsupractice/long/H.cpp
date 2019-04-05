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

vector < vector <PII> >g; //my graph
vector < pair<PII,int> > edgs; //stores my edges

int sz[10005]; //finds subtree size for each parent vertex
int par[10005]; //find parent for each vertex
int depth[10005]; //find depth of each node

int ancestor[20][10005]; //for storing LCA information

int segbase[10005]; //corresponding array for segtree, stores cost of and edge;
int segtree[40005]; //for range query in a chain
int posbase[10005]; //posbase[i] = idx of segbase array for ith node, ith node stores cost of the edge to its parent
//posbase and segbase will be filled with HLD

int chainno[10005]; //for each node which chain it belongs to
int chainhead[10005]; //for each chain idx its topmost node, going to its parent chain will change

int curchain  = 1;
int curbase = 1;

void HLD(int curnode, int cost, int prev){ //this is almost like another dfs
    if(chainhead[curchain]==-1){
        chainhead[curchain] = curnode; //the topmost node of curchain
    }
    chainno[curnode] = curchain;
    posbase[curnode] = curbase; //corresponds to pos in seg tree.. node in a chain will be in consecutive pos in segbase
    segbase[curbase] = cost; //curnode keeps the cost of the edge going to its parent
    curbase++;

    int mxsub = -1, mxcost = -1, mxv = -1;

    FREP(i,0,g[curnode].size()-1){
        int v = g[curnode][i].first; int w = g[curnode][i].second;
        if(v==prev)continue;
        if(sz[v]>mxsub){
            mxsub = sz[v]; mxcost = w; mxv = v;
        }
    }

    //will be part of current chain
    if(mxsub!=-1)HLD(mxv,mxcost,curnode);

    FREP(i,0,g[curnode].size()-1){
        int v = g[curnode][i].first; int w = g[curnode][i].second;
        if(v==prev || v==mxv)continue;
        curchain++;
        HLD(v,w,curnode); //each a different chain so curchain will increase
    }
}

void init(int b, int e, int nd){
    if(b>e)return;
    if(b==e){segtree[nd]=segbase[b];return;}
    int m = (b+e)>>1; int ln = nd<<1; int rn = ln+1;
    init(b,m,ln); init(m+1,e,rn);
    segtree[nd] = max(segtree[ln],segtree[rn]);
}

void update(int b, int e, int nd, int vidx, int cst){
    if(b>e || b>vidx || e<vidx)return;
    if(b==e && b==vidx){segbase[b]=cst;segtree[nd]=cst;return;}
    int m = (b+e)>>1; int ln = nd<<1; int rn = ln+1;
    update(b,m,ln,vidx,cst); update(m+1,e,rn,vidx,cst);
    segtree[nd] = max(segtree[ln],segtree[rn]);
}

int query(int b, int e, int nd, int lq, int rq){ //querying on a single chain
    if(b>e || b>rq || e<lq)return -1;
    if(b>=lq && e<=rq)return segtree[nd];
    int m = (b+e)>>1; int ln = nd<<1; int rn = ln+1;
    int lans = query(b,m,ln,lq,rq); int rans = query(m+1,e,rn,lq,rq);
    return max(lans,rans);
}

int LCA(int u, int v, int ln=18){ //finds LCA of U and V
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u]-depth[v];
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

void precalc(int n, int ln = 18){ //preprocessing before LCA, has to be done after DFS
    FREP(j,1,n){
        ancestor[0][j]=par[j];
    }
    FREP(i,1,(ln-1)){
        FREP(j,1,n){
            if(ancestor[i-1][j]!=-1){
                ancestor[i][j]=ancestor[i-1][ancestor[i-1][j]];
            }
        }
    }
}

void dfs(int cur, int p, int _d = 0){ //fills the sz,par and depth array
    sz[cur] = 1;
    depth[cur] = _d;
    FREP(i,0,g[cur].size()-1){
        int v = g[cur][i].first;
        if(v==p)continue;
        dfs(v,cur,_d+1);
        sz[cur]+=sz[v];
    }
    par[cur] = p;
}

void clearthingy(){
    g.clear();
    edgs.clear();
    MSET(ancestor,-1); MSET(chainhead,-1);
    curchain = 1; curbase = 1;
}

void initg(int n){
    vector<PII>ln; FREP(i,1,(n+3))g.PB(ln);
}

void takeg(int n){
    FREP(i,1,(n-1)){
        int u,v,cst;
        scanf("%d %d %d",&u,&v,&cst);
        g[u].PB(make_pair(v,cst)); g[v].PB(make_pair(u,cst));
        edgs.PB(make_pair(make_pair(u,v),cst));
    }
}

void change(int idx, int newcost, int n){
    pair<PII,int>e = edgs[idx-1];
    int u = e.first.first; int v = e.first.second;
    //cout<<"update kortesi\n";
    //cout<<depth[u]<<" "<<depth[v]<<"\n";
    //cout<<posbase[u]<<" "<<posbase[v]<<"\n";
    if(depth[u]>depth[v])update(1,n,1,posbase[u],newcost); //u is associated with this edg cost
    else update(1,n,1,posbase[v],newcost);
}

int HLDQUERY(int u, int v, int n){
    //v is lca, so will be at higher distance;
    //two case
    //case 1: same chain
    if(chainno[u]==chainno[v]){
        //just one query
        int upos = posbase[u]; int vpos = posbase[v];
        return query(1,n,1,vpos+1,upos); //vpos+1 because vpos stores an irrelevant edg cost
    }
    else{
        int uhead = chainhead[chainno[u]];
        int tmp = query(1,n,1,posbase[uhead],posbase[u]);
        int uheadpar = par[uhead];
        int qq = HLDQUERY(uheadpar,v,n);
        return max(tmp,qq);
    }
    //case 2: diff chain
}

int solve(int u, int v, int n){
    int lcc = LCA(u,v);
    int ans1 = HLDQUERY(u,lcc,n);
    int ans2 = HLDQUERY(v,lcc,n);
    return max(ans1,ans2);
}

char comm[10];

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        clearthingy();
        int n; scanf("%d",&n);
        initg(n);
        takeg(n);
        dfs(1,-1); precalc(n); //ready for HLD?
        HLD(1,-1,-1);
        init(1,n,1);
        while(true){
            scanf("%s",comm);
            if(comm[0]=='D')break;
            else if(comm[0]=='C'){
                int idx,newcost;
                scanf("%d %d",&idx,&newcost);
                change(idx,newcost,n);
            }
            else{
                int u,v;
                scanf("%d %d",&u,&v);
                printf("%d\n",solve(u,v,n));
            }
        }
    }
    return 0;
}
