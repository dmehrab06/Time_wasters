/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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

vector< vector<PII> > g;
vector< map<int,int> > childinfo;
int up[200006];
int down[200006];
int par[200006];
int pardirection[200006];

int dfs1(int u, int p){
	par[u]=p;
	int l=g[u].size();
	FREP(i,0,(l-1)){
		int v=g[u][i].first;
		int w=g[u][i].second;
		//pardirection[v]=w;
		if(v==p)continue;
		pardirection[v]=w;
		int a=dfs1(v,u);
		childinfo[u][v]=a;
		a=a+(w>0?0:1);
		down[u]+=a;
	}
	return down[u];
}

void dfs2(int u, int p){
	//cout<<"in "<<u<<"\n";
	if(u==1){
		up[u]=0;
	}
	else{
		int a=(pardirection[u]==1?1:0);
		int b=up[p];
		int c=((down[p]-(1-a))-childinfo[p][u]);
		//cout<<a<<" "<<b<<" "<<c<<"\n";
		up[u]=a+b+c;
	}
	int l = g[u].size();
	FREP(i,0,(l-1)){
		int nxt=g[u][i].first;
		if(nxt==p){
			continue;
		}
		dfs2(nxt,u);
	}
}

void takeg(int n, int m){
	vector<PII> line;
	map<int,int>line2;
	FREP(i,1,(n+2)){
		g.PB(line);
		childinfo.PB(line2);
	}
	FREP(i,1,(n-1)){
		int u,v;
		scanf("%d %d",&u,&v);
		g[u].PB(make_pair(v,1));
		g[v].PB(make_pair(u,-1));
	}
}

int main(){
	int n;
	scanf("%d",&n);
	takeg(n,(n-1));
	int a=dfs1(1,0);
	dfs2(1,0);
	int mx=1000000007;
	/*FREP(i,1,n){
		cout<<i<<"\n"<<" "<<par[i]<<" "<<up[i]<<" "<<down[i]<<"\n";
		int l = childinfo[i].size();
		cout<<"children map\n";
		map<int,int>::iterator it;
		for(it=childinfo[i].begin(); it!=childinfo[i].end();++it){
			printf("%d %d\n",it->first,it->second);
		}
		cout<<"--end of children map---\n";
	}*/
	FREP(i,1,n){
		if(up[i]+down[i]<mx){
			mx=up[i]+down[i];
		}
	}
	printf("%d\n",mx );
	FREP(i,1,n){
		if((up[i]+down[i])==mx){
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}