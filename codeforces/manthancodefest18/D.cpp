#include <bits/stdc++.h>

using namespace std;

int lev[200005];
int par[200005];
int pos[200005];

vector< vector <int> > g;
vector<int> tocheck;

void takeg(int n){
	memset(lev,-1,sizeof(lev));
	for(int i = 1;i<(n+4);++i){
		vector<int>line;
		g.push_back(line);
	}
	for(int i = 1;i<n;++i){
		int u,v;
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void bfs(int src){
	queue<int>bfsq;
	bfsq.push(src);
	lev[src] = 0;
	tocheck.push_back(lev[src]);
	while(!bfsq.empty()){
		int ss = bfsq.front();
		bfsq.pop();
		for(int i = 0;i<g[ss].size();++i){
			int v = g[ss][i];
			if(lev[v]==-1){
				bfsq.push(v);
				lev[v] = lev[ss]+1;
				par[v] = ss;
				tocheck.push_back(lev[v]);
			}
		}
	}
	return;
}

vector<int>seq;

int main(){
	int n;
	scanf("%d",&n);
	takeg(n);
	bfs(1);
	int f = 1;
	for(int i = 0;i<n;++i){
		int a;
		scanf("%d",&a);
		if(lev[a]!=tocheck[i]){
			f = 0;
		}
		pos[a] = i;
		seq.push_back(a);
	}
	if(f){
		int prev = -1;
		for(int i = 1;i<n;++i){
			int pp = par[seq[i]];
			int pospp = pos[pp];
			if(pospp<prev){
				printf("No\n");
				return 0;
			}
			prev = pos[pp];
		}
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}