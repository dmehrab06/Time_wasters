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
#define MAXLOG 40
#define MP make_pair
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int par[100005][MAXLOG]; // initially all -1
int dis[100005];

vector< VI > g;

void init(int n){
    memset(par,-1,sizeof(par));
    g.clear();
    FREP(i,1,n+4){
        VI line;
        g.PB(line);
    }
}

void dfs(int v,int p = -1){
	par[v][0] = p;
	if(p + 1)dis[v] = dis[p] + 1;
    else dis[v] = 0;

	FREP(i,1,MAXLOG-1)
        if(par[v][i-1] + 1)
			par[v][i] = par[par[v][i-1]][i-1];

	for(auto u : g[v])	if(p - u)
		dfs(u,v);
}

int findLCA(int v,int u){
	if(dis[v] < dis[u])
		swap(v,u);
	RFREP(i,MAXLOG-1,0)if((par[v][i] + 1) && (dis[par[v][i]] >= dis[u]))v = par[v][i];
	if(v == u)
		return v;
	RFREP(i,MAXLOG-1,0)
		if(par[v][i] - par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

void takeg(int n){
    FREP(i,1,n-1){
        int v;
        scanf("%d",&v);
        g[i+1].PB(v);
        g[v].PB(i+1);
    }
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    init(n);
    takeg(n);
    dfs(1);
    FREP(i,1,q){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int lc1 = findLCA(a,b); int lc2 = findLCA(b,c); int lc3 = findLCA(c,a);
        pair<int, pair<int,int> >lcset1 = MP(lc1,MP(a,b));
        pair<int, pair<int,int> >lcset2 = MP(lc2,MP(b,c));
        pair<int, pair<int,int> >lcset3 = MP(lc3,MP(c,a));
        if(lc1==lc2 && lc1==lc3){
            int d1 = dis[a]-dis[lc1]; int d2 = dis[b]-dis[lc1]; int d3 = dis[c]-dis[lc1];
            printf("%d\n",1+max(d1,max(d2,d3)));
        }
        else{
            if(lcset1.first==lcset2.first){
                int d2 = dis[a]-dis[lcset3.first];
                int d3 = dis[c]-dis[lcset3.first];
                if(lcset1.first==b){
                    int d1 = dis[lcset3.first]-dis[b];
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
                else{
                    int lcc = findLCA(b,lcset3.first);
                    int d1 = (dis[lcset3.first]-dis[lcc])+(dis[b]-dis[lcc]);
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
            }
            else if(lcset2.first == lcset3.first){
                int d2 = dis[a]-dis[lcset1.first];
                int d3 = dis[b]-dis[lcset1.first];
                if(lcset2.first==c){
                    int d1 = dis[lcset1.first]-dis[c];
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
                else{
                    int lcc = findLCA(c,lcset1.first);
                    int d1 = (dis[lcset1.first]-dis[lcc])+(dis[c]-dis[lcc]);
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
            }
            else{
                int d2 = dis[b]-dis[lcset2.first];
                int d3 = dis[c]-dis[lcset2.first];
                if(lcset1.first==a){
                    int d1 = dis[lcset2.first]-dis[a];
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
                else{
                    int lcc = findLCA(a,lcset2.first);
                    int d1 = (dis[lcset2.first]-dis[lcc])+(dis[a]-dis[lcc]);
                    printf("%d\n",1+max(d1,max(d2,d3)));
                }
            }
        }
    }
    return 0;
}

