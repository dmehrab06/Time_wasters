#include <bits/stdc++.h>

using namespace std;

pair<int,int> segtree[600005];

pair<int,int>ans[100005];

void prop(int b, int e, int node){
	int m = (b+e)/2;
	int ln = node<<1; int rn = ln+1;

	int wn = segtree[node].first; 
	int dn = segtree[node].second;

	int lwn = segtree[ln].first;
	int ldn = segtree[ln].second;

	int rwn = segtree[rn].first;
	int rdn = segtree[rn].second;

	if(wn>lwn){
		segtree[ln] = segtree[node];
	}
	else if(wn==lwn){
		segtree[ln].second = max(segtree[ln].second,dn);
	}

	if(wn>rwn){
		segtree[rn] = segtree[node];
	}
	else if(wn==rwn){
		segtree[rn].second = max(segtree[rn].second,dn);
	}
}

void update(int b, int e, int node, int l, int r, int d, int w){
	if(l>e || r<b || b>e)return;
	if(b>=l && e<=r){
		if(segtree[node].first<w){
			segtree[node].first = w;
			segtree[node].second = d;
		}
		else if(segtree[node].first == w){
			segtree[node].second = max(segtree[node].second,d);
		}
		return;
	}
	int mid = (b+e)/2;
	int ln = node<<1; int rn = ln+1;
	update(b,mid,ln,l,r,d,w); update(mid+1,e,rn,l,r,d,w);
	//porer line ta mone hoy dorkar nai
}

pair<int,int>query(int b, int e, int node, int time){
	if(b>e || b>time || e<time){
		return make_pair(0,0);
	}
	if(b==e && b==time){
		return segtree[node];
	}
	prop(b,e,node);
	int mid = (b+e)/2;
	int ln = node<<1; int rn = ln+1;
	pair<int,int>lans = query(b,mid,ln,time);
	pair<int,int>rans = query(mid+1,e,rn,time);
	if(lans.first>rans.first){
		return lans;
	}
	else{
		return rans;
	}
}

long long dp[100005][203];

void init(){
	memset(dp,-1,sizeof(dp));
}

long long solve(int tm, int left, int n){
	if(tm>n)return 0;
	if(dp[tm][left]!=-1)return dp[tm][left];
	long long ret1 = 1e15; long long ret2 = 1e15;
	//cout<<ret1<<" "<<ret2<<"\n";
	if(left>0){
		ret1 = solve(tm+1,left-1,n);
	}
	pair<int,int>a = ans[tm];
	if(a.first==0){
		ret2 = solve(tm+1,left,n);
	}
	else{
		ret2 = (long long)a.first+solve(a.second+1,left,n);
	}
	return dp[tm][left] = min(ret1,ret2);
}

int main(){
	int n,disturb,env;
	scanf("%d %d %d",&n,&disturb,&env);
	for(int i = 1; i<=env; ++i){
		int s,t,d,w;
		scanf("%d %d %d %d",&s,&t,&d,&w);
		update(1,n,1,s,t,d,w);
	}
	for(int i = 1; i<=n; ++i){
		ans[i] = query(1,n,1,i);
		//printf("%d: %d %d\n",i,ans[i].first,ans[i].second);
	}
	init();
	long long ok = solve(1,disturb,n);
	printf("%lld\n",ok);
	return 0;
}