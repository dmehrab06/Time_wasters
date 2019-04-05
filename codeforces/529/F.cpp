#include <bits/stdc++.h>

using namespace std;

vector< pair< long long int, pair<int,int> > >specialedge;

vector< pair<long long int,int> >vval;

int par[200005];

int findrep(int v){
	if(par[v]==v)return v;
	else{
		int k = findrep(par[v]);
		par[v] = k;
		return par[v];
	}
}

int dis_union(int u, int v){
	int pu = findrep(u);
	int pv = findrep(v);
	if(pu==pv){
		return 0;
	}
	else{
		par[pu] = pv;
		return 1;
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 1; i<=n; ++i){
		long long int v; cin>>v;
		par[i] = i;
		vval.push_back(make_pair(v,i));
	}
	for(int i = 1; i<=m; ++i){
		int u,v; long long int w;
		cin>>u>>v>>w;
		pair<long long int, pair<int,int> >thing = make_pair(w,make_pair(u,v));
		specialedge.push_back(thing);
	}
	vval.push_back(make_pair(10000000000000000,200003));
	specialedge.push_back(make_pair(10000000000000000,make_pair(200003,200003)));
	sort(vval.begin(),vval.end());
	sort(specialedge.begin(), specialedge.end());
	int i1 = 0;
	int j1 = 1;
	int i2 = 0;
	int edgeadded = 0;
	long long int tot = 0;
	while(edgeadded<(n-1)){
		int u1 = vval[i1].second;
		int v1 = vval[j1].second;
		long long int w1 = vval[i1].first+vval[j1].first;
		int u2 = specialedge[i2].second.first;
		int v2 = specialedge[i2].second.second;
		long long int w2 = specialedge[i2].first;
		if(w1<w2){
			if(dis_union(u1,v1)){
				edgeadded++;
				tot+=w1;
			}
			j1++;
			if(j1==n){
				i1++;
				j1=i1+1;
			}

		}
		else{
			if(dis_union(u2,v2)){
				edgeadded++;
				tot+=w2;
			}
			i2++;
		}
	}
	cout<<tot<<"\n";
	return 0;
}