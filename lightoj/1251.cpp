#include <bits/stdc++.h>

using namespace std;

int used[50000];
int comp[50000];
int assigned[50000];
vector<int>topo;
vector< vector< int > >g,gt;

void init(){
	memset(used,0,sizeof(used));
	memset(comp,-1,sizeof(comp));
	memset(assigned,-1,sizeof(assigned));
	topo.clear();
	g.clear(); gt.clear();
}

void dfs1(int cur){
	used[cur] = 1;
	for(auto v: g[cur]){
		if(!used[v]){
			dfs1(v);
		}
	}
	topo.push_back(cur);
}

void dfs2(int cur, int c){
	comp[cur] = c;
	for(auto v: gt[cur]){
		if(comp[v]==-1){
			dfs2(v,c);
		}
	}
}

int getnode(int v){
	int val = 2*abs(v);
	if(v<0)val = val+1;
	return val;
}

void addedge(int fc, int sc){
	int notfc = fc*(-1);
	g[getnode(notfc)].push_back(getnode(sc));
	gt[getnode(sc)].push_back(getnode(notfc));

	int notsc = sc*(-1);
	g[getnode(notsc)].push_back(getnode(fc));
	gt[getnode(fc)].push_back(getnode(notsc));
}

bool solve2SAT(int m){
	for(int i = 2; i<= (2*m+1); ++i){
		if(!used[i]){
			dfs1(i);
		}
	}

	int tot = (int)topo.size();
	
	for(int i = 0, j = 0; i<tot; ++i){
		int cur = topo[tot-i-1];
		if(comp[cur]==-1){
			dfs2(cur,j);
			j++;
		}
	}

	for(int i = 0, j = 0; i<tot; ++i){
		int cur = topo[tot-i-1];
		if(comp[cur]==-1){
			dfs2(cur,j);
			j++;
		}
	}

	for(int i = 1; i<=m; ++i){
		if(comp[2*i]==comp[2*i+1]){
			return false;
		}
		assigned[i] = (comp[2*i]>comp[2*i+1])?1:0;
	}

	return true;
}

void makeg(int n, int m){
	for(int i = 1; i<=(3*m); ++i){
		vector<int>line;
		g.push_back(line);
		gt.push_back(line);
	}

	for(int i = 1; i<=n; ++i){
		int u,v;
		scanf("%d %d",&u,&v);
		addedge(u,v);
	}
}

void solve(int cs, int m){

	printf("Case %d: ",cs);
	if(solve2SAT(m)){
		
		int cnt = 0;

		for(int i = 1; i<=m; ++i){
			if(assigned[i]==1){
				cnt++;
			}
		}

		printf("Yes\n%d",cnt);
		for(int i = 1; i<=m; ++i){
			if(assigned[i]==1){
				printf(" %d",i);
			}
		}
		printf("\n");		
	}
	else{
		printf("No\n");
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cs = 1; cs<=t; ++cs){
		int n,m;
		scanf("%d %d",&n,&m);
		init();
		makeg(n,m);
		solve(cs,m);
	}
	return 0;
}


