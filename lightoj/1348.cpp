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

#define N 30005
#define LN 18

int st[5*N];
int nodeval[N];
int baseArray[N];

void init(int node, int b, int e){
    if(b>e)return;
    if(b==e){
        st[node]=baseArray[b];
        return;
    }
    int mid = (b+e)/2;
    int lnode = node<<1; int rnode = lnode+1;
    init(lnode,b,mid); init(rnode,mid+1,e);
    st[node]=st[lnode]+st[rnode];
}

void update(int node, int b, int e, int idx, int val){
    if(b>e)return;
    if(b==idx && b==e){
        baseArray[b]=val;
        st[node]=nodeval[b];
        return;
    }
    int mid = (b+e)/2;
    int lnode = node<<1; int rnode = lnode+1;
    update(lnode,b,mid,idx,val); update(rnode,mid+1,e,idx,val);
    st[node]=st[lnode]+st[rnode];
}

int query(int node, int b, int e, int i, int j){
    if(b>j || e<i)return 0;
    if(b>=i && e<=j){
        return st[node];
    }
    int mid = (b+e)/2;
    int lnode = node<<1; int rnode = lnode+1;
    int lans = query(lnode,b,mid,i,j); int rans = query(rnode,mid+1,e,i,j);
    return lans+rans;
}

int depth[N]; int pa[LN][N]; int subsize[N];
vector < VI >adj;
int ptr,chainNo;
int chainHead[N], chainInd[N], posInBase[N];

void change(int u, int val){
    update(1,0,ptr,posInBase[u],val);
}

int query_up(int u, int ancestor){
    if(u == ancestor) return nodeval[u]; // Trivial
	int uchain, achain = chainInd[ancestor], ans = 0;
	while(1) {
		uchain = chainInd[u];
		if(uchain == achain) {
			if(u==ancestor){
                ans = nodeval[u];
                break;
			}
			ans+=query(1, 0, ptr, posInBase[ancestor], posInBase[u]);
			break;
		}
		ans+=query(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]);
		u = chainHead[uchain]; // move u to u's chainHead
		u = pa[0][u]; //Then move to its parent, that means we changed chains
	}
	return ans;
}

int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

void mainquery(int u, int v) {
	int lca = LCA(u, v);
	int ans1 = query_up(u, lca); // One part of path
	int ans2 = query_up(v, lca); // another part of path
	int ans3 = query_up(lca,lca);
	printf("%d\n", ans1+ans2-ans3);
}

void HLD(int curNode, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode; // Assign chain head
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr++] = nodeval[curNode];

	int sc = -1;
	// Loop to find special child
	for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
			sc = adj[curNode][i];
		}
	}

	if(sc != -1) {
		// Expand the chain
		HLD(sc, curNode);
	}

	for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc != adj[curNode][i]) {
			// New chains at each normal node
			chainNo++;
			HLD(adj[curNode][i], curNode);
		}
	}
}

void inp_tree(int n){
    adj.clear();
    FREP(i,1,(n+3)){
        VI line;
        adj.PB(line);
    }
    FREP(i,1,n)scanf("%d",&nodeval[i]);
    FREP(i,1,(n-1)){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].PB(v);
        adj[v].PB(u);
    }
}

void dfs(int cur, int prev, int _depth=0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	subsize[cur] = 1;
	for(int i=0; i<adj[cur].size(); i++)
		if(adj[cur][i] != prev) {
			//otherEnd[indexx[cur][i]] = adj[cur][i];
			dfs(adj[cur][i], cur, _depth+1);
			subsize[cur] += subsize[adj[cur][i]];
		}
}

void initeverything(int n){
    chainNo = 0;
    for(int i=0; i<n; i++) {
        chainHead[i] = -1;
        for(int j=0; j<17; j++) pa[j][i] = -1;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int n;
        scanf("%d",&n);
        initeverything(n);
        inp_tree(n);
        dfs(0,-1);
        HLD(0,-1);
        init(1,0,ptr);
        int q;
        scanf("%d",&q);
        FREP(i,1,q){
            int type;
            scanf("%d",&type);
            if(type==0){
                int u,v;
                scanf("%d %d",&u,&v);
                mainquery(u,v);
            }
            else{
                int u,val;
                scanf("%d %d",&u,&val);
                change(u,val);
            }
        }
    }
    return 0;
}
