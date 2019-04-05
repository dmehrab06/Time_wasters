#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int inf = 1000000 + 10;

using namespace std;

typedef long long llint;

struct Edge { int x, y, b; long long w; };

long long dmst(int N, vector<Edge> E, int root, int pr = 0) {
  const long long oo = 100000000000LL;

  vector<long long> cost(N); vector<int> back(N), label(N), bio(N);
  long long ret = 0;

  for (;;) {
    REP(i, N) cost[i] = oo;
    for (auto e : E) {
      if (e.x == e.y) continue;
      if (e.w < cost[e.y]) cost[e.y] = e.w, back[e.y] = e.x;
    }
    cost[root] = 0;
    REP(i, N) if (cost[i] == oo) return -1;
    REP(i, N) ret += cost[i];

    int K = 0;
    REP(i, N) label[i] = -1;
    REP(i, N) bio[i] = -1;

    REP(i, N) {
      int x = i;
      for (; x != root && bio[x] == -1; x = back[x]) bio[x] = i;

      if (x != root && bio[x] == i) {
        for (; label[x] == -1; x = back[x]) label[x] = K;
        ++K;
      }
    }
    if (K == 0) break;

    REP(i, N) if (label[i] == -1) label[i] = K++;

    for (auto &e : E) {
      int xx = label[e.x];
      int yy = label[e.y];
      if (xx != yy) e.w -= cost[e.y];
      e.x = xx;
      e.y = yy;
    }

    root = label[root];
    N = K;
  }

  if(pr){
  	
  	for(int i = 0; i<N; ++i){
  		cout<<i<<": back = "<<back[i]<<": label = "<<label[i]<<": bio = "<<bio[i]<<"\n";
  	}
  }

  return ret;
}

vector<Edge>alledg;

bool can(int curb, int N, int mxcost, int pr = 0){
	if(pr)cout<<"checking for "<<curb<<"\n";
	vector<Edge>valid;
	for(auto e: alledg){
		if(e.b>=curb)valid.push_back(e);
	}
	long long cc = dmst(N,valid,0,pr);
	return (cc!=-1) && (cc<=mxcost);
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cs = 1; cs<=t; ++cs){
		alledg.clear();
		int n,m,c;
		scanf("%d %d %d",&n,&m,&c);
		int lo = 0, hi = 0;
		for(int i = 1; i<=m; ++i){
			Edge e;
			scanf("%d %d %d %lld",&e.x,&e.y,&e.b,&e.w);
			alledg.push_back(e);
			hi = max(hi,e.b);
		}
		while((lo+1)<hi){
			int mid = lo+(hi-lo)/2;
			if(can(mid,n,c)){
				lo = mid;
			}
			else{
				hi = mid;
			}
		}
		if(can(hi,n,c,1)){
			printf("Case %d: %d kbps\n",cs,hi);
		}
		else if(can(lo,n,c,1)){
			printf("Case %d: %d kbps\n",cs,lo);
		}
		else{
			printf("Case %d: impossible\n",cs);
		}
	}
	return 0;
}
