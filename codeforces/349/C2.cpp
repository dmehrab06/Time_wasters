#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define TASK ""
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define for1(i, n) for (int i = 1; i <= (int)n; i++)
#define forq(i, s, t) for (int i = s; i <= (int)t; i++)
#define ford(i, s, t) for (int i = s; i >= (int)t; i--)
#define mk make_pair
#define pk	push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

const double EPS = 1e-15;
const double PI = acos(-1.0);
const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
const ll LINF = (ll)2e18 + 7;
const int MOD = (int)1e9 + 7;
const ull P = 239017;
const ull MM = (ull)2147482661;

int solve();

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("test.txt", "w", stderr);
	double tstart = TIME;
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	return solve();
}

set<string> v[MAXN];

int solve()
{
	string s;
	cin >> s;
	int len = s.length();

	set<string> sans;
	for (int i = len - 1; i > 4; i--) {
		string t = s.substr(i, 1);
		cout<<"now substring "<<t<<"\n";
		for (int j = i - 1; j >= i - 2 && j > 4; j--) {
			t = s[j] + t;
			cout<<"inside inner substr "<<t<<"\n";
			cout<<"v[i+1].size "<<v[i+1].size()<<"\n";
			cout<<"v[i+1].count(t) "<<v[i+1].count(t)<<"\n";
			cout<<"i+1 "<<i+1<<"\n";
			cout<<"len "<<len<<"\n";
			if ((v[i + 1].size() == 1 && !v[i + 1].count(t)) || v[i + 1].size() > 1 || i + 1 >= len) {
				v[j].insert(t);
				sans.insert(t);
			}
		}
	}

	cout << sans.size() << '\n';
	for (auto x : sans) {
		cout << x << '\n';
	}
	return 0;
}
