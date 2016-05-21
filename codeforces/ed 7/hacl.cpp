/// /* Bismillahir Rahmanir Rahim *\

/// S. M. Shakir Ahsan Romeo
/// Khulna University
/// CSE Discipline
#include <bits/stdc++.h>
using namespace std;
typedef long long lng;
#define     rt             return
#define     PI             acos(-1.0)
#define     eps            1e-9
#define     inf            (1<<30)
#define     FAST           ios_base::sync_with_stdio(0);cin.tie(0);
#define     endl           '\n'
#define     pb             push_back
#define     sf             scanf
#define     pf             printf
#define     bin_sea        binary_search
#define     dbg(x)         cout << x << " came here\n";
#define     all(x)         x.begin(), x.end()
#define     mem(x, y)      memset(x, y, sizeof(x));
#define     rep(i, x)      for(int i = 0; i < x; ++i)
#define     rep1(i, x)     for(int i = 1; i <= x; ++i)
#define     pmat2(A, x, y) rep(i, x) { rep(j, y) cout << A[i][j] << ' '; cout << endl; }
#define     smat2(A, x, y) rep(i, x) rep(j, y) cin >> A[i][j];
#define MX 100000000000000
#define N 14142140
int main()
{
    lng n, t;
    cin >> n;
    lng nn = n;
    for(lng i = 1;;++i)
    {
        n -= i;
        //cout << n << endl;
        if(n == 0)
        {
            cout << i << endl;
            return 0;
        }
        else if(n < 0)
        {
            n += i;
            cout << n << endl;
            return 0;
        }
    }
    return 0;
}
