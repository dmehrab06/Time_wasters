#include <bits/stdc++.h>

using namespace std;

vector< vector<int> >g;

int vis[100005];

void make_g(int n, int m){
	for(int i = 0; i<n+4; ++i){
		vector<int>line;
		g.push_back(line);
	}
	for(int i =1; i<=m ; ++i){
		int u,v;
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void bfs_variant(){
	set<int>myq;
	myq.insert(1);
	vis[1] = 1;
	while((int)myq.size()>0){
		int a = *(myq.begin());
		myq.erase(a);
		printf("%d ",a);
		for(int v: g[a]){
			if(!vis[v]){
				vis[v] = 1;
				myq.insert(v);
			}
		}
	}
	return;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	make_g(n,m);
	bfs_variant();
	printf("\n");
	return 0;
}