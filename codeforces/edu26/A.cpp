#include "assert.h"
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <vector>

using namespace std;

#if LOCAL
	#define DO_NOT_SEND
#endif

typedef long long LL;

int IntMaxVal = (int) 1e20;
int IntMinVal = (int) -1e20;
LL LongMaxVal = (LL) 1e20;
LL LongMinVal = (LL) -1e20;

#define FOR(i, a, b) for(int i = a; i < b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)

template<typename T> inline void minimize(T &a, T b) { a = std::min(a, b); }
template<typename T> inline void maximize(T &a, T b) { a = std::max(a, b); }

template<typename T> inline void swap(pair<T, T> &p) { swap(p.first , p.second ); }

#define all(v) v.begin(),v.end()

#define endl '\n'
template<typename T> struct argument_type;
template<typename T, typename U> struct argument_type<T(U)> { typedef U type; };
#define next(t, i) argument_type<void(t)>::type i; cin >> i;

template <typename T1, typename T2> istream& operator >>(istream& is, pair<T1, T2>& s) { is >> s.first >> s.second; return is; }
template <typename T> ostream& operator << (ostream& os, const vector<T> &v) { for (int i = 0 ; i < v.size() ; i++) { if (i) os << ' '; os << v[i]; } os << endl; return os; }
template <typename T1, typename T2> ostream& operator << (ostream& os, const vector<pair<T1, T2>> &v) { for (int i = 0 ; i < v.size() ; i++) { os << v[i] << endl; } return os; }
template <typename T1, typename T2> ostream& operator <<(ostream& s, const pair<T1, T2>& t) { s << t.first << ' ' << t.second; return s; }
template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

int main() {
	srand (time(NULL));
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	fixed(cout); cout << setprecision(10);

	next(int, n);
	string s;
	getline(cin, s);
	getline(cin, s);

	int cur = 0;
	int total = 0;

	s += ' ';
	for (auto c : s) {
		if (c == ' ') {
			maximize(total, cur);
			cur = 0;
		} else if (c >= 'A' && c <= 'Z') {
			cur++;
		}
	}

	cout << total;
}
