/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
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
//using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

#define MAXN 30005
#define MXLOG 20

int segbasearray[MAXN];
int seg[4*MAXN];
int posbase[MAXN];
int ancestor[MXLOG][MAXN];
int depth[MAXN];
int sz[MAXN];
int par[MAXN];
int chainno[MAXN];
int chainhead[MAXN];

int curbase = 1;
int curchain = 1;

vector < VI > g;

int genie[MAXN];

void init(){
    g.clear();
    MSET(ancestor,-1);
    MSET(par,-1);
    MSET(chainhead,-1);
    curbase = 1, curchain = 1;
}

void HLD(int curnode, int cost, int prev){
    if(chainhead[curchain]==-1){
        chainhead[curchain] = curnode;
    }
    chainno[curnode] = curchain;
    segbasearray[curbase] = cost;
    posbase[curnode] = curbase;
    curbase++;

    int mxsz = -1, gov = -1, ww = -1;
    FREP(i,0,g[curnode].size()-1){
        int v = g[curnode][i];
        if(v==prev)continue;
        if(sz[v]>mxsz){
            mxsz = sz[v];
            gov = v;
            ww = genie[v];
        }
    }

    if(gov!=-1){
        HLD(gov,ww,curnode);
    }

    FREP(i,0,g[curnode].size()-1){
        int v = g[curnode][i];
        if(v==prev || v==gov)continue;
        curchain++;
        HLD(v,genie[v],curnode);
    }

}

void build(int b, int e, int nd){
    if(b>e)return;
    if(b==e){seg[nd] = segbasearray[b];return;}
    int m = (b+e)>>1;  int ln = nd<<1; int rn = ln+1;
    build(b,m,ln); build(m+1,e,rn);
    seg[nd] = seg[ln]+seg[rn];
}

void update(int b, int e, int idx, int val, int nd){
    if(b>idx || e<idx)return;
    if(b==e && b==idx){segbasearray[b] = val; seg[nd] = segbasearray[b];return;}
    int m = (b+e)>>1;  int ln = nd<<1; int rn = ln+1;
    update(b,m,idx,val,ln); update(m+1,e,idx,val,rn);
    seg[nd] = seg[ln]+seg[rn];
}

int query(int b, int e, int l, int r, int nd){
    if( b>e ||  b>r || e<l)return 0;
    if(b>=l && e<=r){return seg[nd];}
    int m = (b+e)>>1;  int ln = nd<<1; int rn = ln+1;
    int lans = query(b,m,l,r,ln); int rans = query(m+1,e,l,r,rn);
    return lans+rans;
}

int HLDQUERY(int u, int v, int n){
    //v is above u
    //cout<<u<<" "<<v<<"\n";
    //cout<<"chain: "<<chainno[u]<<" "<<chainno[v]<<"\n";
    if(chainno[u]==chainno[v]){
        int pu = posbase[u]; int pv = posbase[v];
        return query(1,n,pv,pu,1);
    }
    else{
        int hd = chainhead[chainno[u]];
        int phead = posbase[hd]; int pu = posbase[u];
        int tans = query(1,n,phead,pu,1);
        int t2ans = HLDQUERY(par[hd],v,n);
        return tans+t2ans;
    }
}


void dfs(int cur, int p, int _d = 0){
    sz[cur]  = 1;
    par[cur] = p;
    depth[cur] = _d;
    FREP(i,0,g[cur].size()-1){
        int v = g[cur][i];
        if(v==p)continue;
        dfs(v,cur,_d+1);
        sz[cur]+=sz[v];
    }
    return;
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

int solve(int p, int q, int n){
    int lca = LCA(p,q);
    //cout<<"lca of "<<p<<" and q is "<<lca<<"\n";
    int lans = HLDQUERY(p,lca,n);
    int rans = HLDQUERY(q,lca,n);
    return lans+rans-HLDQUERY(lca,lca,n);
}

void change(int u, int n, int newval){
    int pos  = posbase[u];
    update(1,n,pos,newval,1);
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        init();
        int n;
        scanf("%d",&n);
        FREP(i,1,n)scanf("%d",&genie[i]);
        VI line; FREP(i,1,(n+3))g.PB(line);
        FREP(i,1,(n-1)){
            int u,v;
            scanf("%d %d",&u,&v);
            g[u+1].PB(v+1);
            g[v+1].PB(u+1);
        }
        dfs(1,-1); precalc(n); HLD(1,genie[1],-1); build(1,n,1);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cs);
        FREP(i,1,q){
            int type;
            scanf("%d",&type);
            if(type==0){
                int u,v;
                scanf("%d %d",&u,&v);
                printf("%d\n",solve(u+1,v+1,n));
            }
            else{
                int u,val;
                scanf("%d %d",&u,&val);
                change(u+1,n,val);
            }
        }
    }
    return 0;
}
