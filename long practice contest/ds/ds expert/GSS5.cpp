#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <set>
#include <numeric>
#include <stack>
using namespace std;
#define mp make_pair
#define INF (int)1e9
#define X first
#define Y second
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
#define sz(x)    ((int) x.size())
#define si(x) scanf("%d", &x)
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define MAXN 110000

int sum[2*MAXN], leftmax[2*MAXN], rightmax[2*MAXN], midmax[2*MAXN], best[2*MAXN], A[MAXN], cumsum[MAXN];
int N, Q;

struct node {
	int sum, left, right, mid, curmax, res, mres; 
	node (int a=0, int b=-INF, int c= -INF, int d = -INF, int e = -INF) :
	 sum(a), left(b), right(c), mid(d), curmax(e) {
		res = max(max(sum, left), max(mid, right));
		res = max(res, curmax);
	}
};

void build_tree(int a, int b, int x) {
	if (a > b) return;
	if (a == b) {
		sum[x] = leftmax[x] = rightmax[x] = midmax[x] = best[x] = A[a];
		return;
	}
	int lt = 2*x, rt = 2*x+1, mid = (a+b)/2;
	build_tree(a, mid, lt);
	build_tree(mid+1, b, rt);
	sum[x] = sum[lt] + sum[rt];
	leftmax[x] = max(sum[lt] + leftmax[rt], leftmax[lt]);
	rightmax[x] = max(rightmax[rt], sum[rt] + rightmax[lt]);
	midmax[x] = max(max(leftmax[rt] + rightmax[lt], rightmax[lt]), leftmax[rt]);
	int cands[] = {sum[x], leftmax[x], rightmax[x], midmax[x], best[lt], best[rt]};
	best[x] = *max_element(cands, cands+6);
}

node query(int a, int b, int x, int i, int j) {
	// printf("(dbg) %d %d %d %d %d\n", a, b, x, i, j);
	if (a > b || a > j || b < i) {
		node n;
		n.res = -INF;
		return n;
	} 
	if (a >= i && b <= j) {
		return node(sum[x], leftmax[x], rightmax[x], midmax[x], best[x]);
	}
	int lt = 2*x, rt = 2*x+1, mid = (a + b) / 2;
	node nleft = query(a, mid, lt, i, j);
	node nright = query(mid+1, b, rt, i, j);
	return node (
			nleft.sum + nright.sum, 
			max(nleft.left, nleft.sum + nright.left), 
			max(nright.right, nright.sum + nleft.right),
			max(max(nleft.right, nleft.right + nright.left), nright.left),
			max(nleft.res, nright.res)
		);
}

void preprocess() {
	fill(cumsum, 0);
	for(int i=1; i <= N; i++)
		cumsum[i] = cumsum[i-1] + A[i];
}

int rsq(int a, int b) {
	if (a > b) return 0;
	return cumsum[b] - cumsum[a-1];
}


int solve(int x1, int y1, int x2, int y2) {
	if (y1 < x2) {
		int lquery = query(1, N, 1, x1, y1).right;
		int middle = rsq(y1+1, x2-1);
		int rquery = query(1, N, 1, x2, y2).left;
		return lquery + middle + rquery;
	}
	else {
	// Case 2
		int left1 = query(1, N, 1, x1, x2).right;
		int right1 = query(1, N, 1, x2+1, y2).left;
		int piv1 = max(left1, left1+right1);

		int left2 = query(1, N, 1, x1, y1).right;
		int right2 = query(1, N, 1, y1+1, y2).left;
		int piv2 = max(left2, left2+right2);

		int piv3 = query(1, N, 1, x2, y1).res;

		return max(max(piv1, piv2), piv3);
	}
}

void task() {
	si(N);
	REP(i, N) {
		si(A[i+1]);
	}
	preprocess();
	build_tree(1, N, 1);
	si(Q);
	REP(i, Q) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", solve(x1, y1, x2, y2));
	}
}	

int main() {
	int t;
	si(t);
	REP(i, t) task();
}