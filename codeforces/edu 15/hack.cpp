#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_CHECK
#define trace(x) cerr << #x << ": " << x << " ";
#define trnl cerr << "\n";
#else
#define trace(x) {}
#define trnl {}
#endif
typedef long long lolo;
typedef unsigned long long ulolo;
typedef pair<int, int> pii;
#define F(i,a,b) for(int i=(a);i<(b);++i)
#define R(i,n) F(i,0,n)
#define FD(i,n) for(int i=(n-1);i>=0;--i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define fi first
#define se second
#define M_PI           3.14159265358979323846

const int INF = 1e9 + 23;
const int MOD = 1e9 + 9;
const int N = 2e5 + 100;

char good[] = {'A', 'H', 'I', 'M', 'O', 'o',
  'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y'};

bool sym(char a, char b) {
  if (a == 'b' && b == 'd') {
    return true;
  }
  if (a == 'd' && b == 'b') {
    return true;
  }
  if (a != b) {
    return false;
  }
  for (int i = 0; i < 15; ++i) {
    if (a == good[i]) {
      return true;
    }
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  bool ok = true;
  for (int i = 0, j = SZ(s)-1; i <= j; ++i, --j) {
    ok &= sym(s[i], s[j]);
  }
  cout << (ok ? "TAK" : "NIE") << "\n";
}
