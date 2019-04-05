#include <bits/stdc++.h>
#define MDD 1000000007

using namespace std;

map<long long int,int>val_to_idx;
map<int,long long int>idx_to_val;

vector<long long>allvals;

long long segtree[500003];

void init(){
	memset(segtree,0,sizeof(segtree));
	val_to_idx.clear();
	idx_to_val.clear();
	allvals.clear();
}

void setMap(int n){
	vector<long long>temp;

	for(int i = 1; i<=n; ++i){
		int a;
		scanf("%d",&a);
		allvals.push_back(a);
	}

	temp = allvals;
	sort(temp.begin(),temp.end());

	int used = 1; long long minval = temp[0]-1;
	val_to_idx[minval] = used; idx_to_val[used] = minval;
	used++;

	for(long long v: temp){
		if(val_to_idx.find(v)==val_to_idx.end()){
			val_to_idx[v] = used; idx_to_val[used] = v;
			used++;
		}
	}
}

void update(int b, int e, int node, int idx, long long val){
	if(b==e && b==idx){
		segtree[node] = (segtree[node]+val)%MDD;
		return;
	}
	if(b>e || b>idx || e<idx)return;

	int mid = b+(e-b)/2;
	int ln = node<<1; int rn = ln+1;

	update(b,mid,ln,idx,val);
	update(mid+1,e,rn,idx,val);

	segtree[node] = (segtree[ln]+segtree[rn])%MDD;
}

long long query(int b, int e, int node, int i, int j){
	if(b>=i && e<=j)return segtree[node];
	if(b>j || e<i || b>e)return 0;

	int mid = b+(e-b)/2;
	int ln = node<<1; int rn = ln+1;

	long long lans = query(b,mid,ln,i,j);
	long long rans = query(mid+1,e,rn,i,j);

	return (lans+rans)%MDD;
}

long long solve(int n){

	long long tot = 0;

	for(long long val: allvals){
		int idx = val_to_idx[val];
		long long ans = query(1,n,1,1,idx-1);
		//cout<<"for val: "<<val <<" idx: "<<idx<<" ans: "<<ans+1<<"\n";
		tot = (tot+ans+1)%MDD;
		update(1,n,1,idx,ans+1);
	}

	return tot;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cs = 1; cs<=t; ++cs){
		int n;
		scanf("%d",&n);
		init();
		setMap(n);
		printf("Case %d: %lld\n",cs,solve(n));
	}
	return 0;
}