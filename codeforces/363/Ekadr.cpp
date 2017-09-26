#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:66777216")
#else
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#endif
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <chrono>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

inline pdd operator +(const pdd &a, const pdd &b) {
	return mp(a.x + b.x, a.y + b.y);
}
inline pdd operator -(const pdd &a, const pdd &b) {
	return mp(a.x - b.x, a.y - b.y);
}
inline pdd operator *(const pdd &a, const double &b) {
	return mp(a.x * b, a.y * b);
}
inline pdd operator /(const pdd &a, const double &b) {
	return mp(a.x / b, a.y / b);
}

int a, b, c, d, n, m, k;
double p[22];

inline static int _popcnt(unsigned a) {
#ifdef _MSC_VER
	return _mm_popcnt_u32(a);
#else
	return __builtin_popcount(a);
#endif
}
inline static int _ctz(unsigned a) {
#ifdef _MSC_VER
	return _tzcnt_u32(a);
#else
	return __builtin_ctz(a);
#endif
}

double s[1 << 20];
pdd f[1 << 20];
double solve(int pos) {
	if (p[pos] == 1) return 1.0;
	if (p[pos] == 0) return 0.0;
	C(f);
	f[0] = mp(1.0, 0);
	pdd ov = mp(1.0, 0.0);
	rept(mask, 1 << n) {
		if (!mask) continue;
		if (mask & 1 << pos) continue;
		pdd sum = mp(0, 0);
		rept(j, n) {
			if (~mask & 1 << j) continue;
			auto cur = f[mask ^ 1 << j] * p[j];
			sum = sum + cur;
		}

		sum = sum / (1.0 - s[mask]);
		f[mask] = sum;
		ov = ov + sum;
	}

	double x = (1.0 - ov.y) / ov.x;

	double ans = 0.0;
	rept(mask, 1 << n) {
		if (_popcnt(mask) >= k) continue;
		ans += x * f[mask].x + f[mask].y;
	}
	return ans;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	rept(i, n) {
		scanf("%lf", &p[i]);
	}
	C(s);
	rept(i, 1 << n) {
		if (!i) continue;
		int t = _ctz(i);
		s[i] = p[t] + s[i ^ (1 << t)];
	}

	rept(i, n) {
		double ans = solve(i);
		if (i) printf(" ");
		printf("%.15lf", ans);
	}
	printf("\n");
}
