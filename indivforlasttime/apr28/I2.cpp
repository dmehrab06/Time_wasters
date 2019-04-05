 #include <stdio.h>
#include <string.h>
#include <algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace  std;
Const int  N = 17;
Const int  MAXN = (1<<N);
Const int  XN = 105;
Int  n, x, y, big[N], sum[MAXN];
Bool  dp[MAXN][XN], vis[MAXN][XN];

Int  bitcount( int  x) {
    If  (x == 0)  return  0;
    Return  bitcount(x>>1) + (x&1);
}
Bool  solve( int  s,  int  x) {
    If  (vis[s][x])  return  dp[s][x];
    Vis[s][x] = 1;
    If  (bitcount(s) == 1)  return  dp[s][x] =  true ;
    If  (sum[s] % x)  return  dp[s][x] =  false ;
    Int  y = sum[s] / x;
    For  ( int  s0 = (s - 1)&s; s0 > 0; s0 = (s0 - 1)&s) {
        Int  s1 = (s^s0);
        If  (sum[s0]%x==0 && solve(s0, min(x, sum[s0]/x)) && solve(s1, min(x, sum[s1]/x)))
            Return  dp[s][x] =  true ;
        If  (sum[s0]%y==0 && solve(s0, min(y, sum[s0]/y)) && solve(s1, min(y, sum[s1]/y)))
            Return  dp[s][x] =  true ;
    }
    Return  dp[s][x] =  false ;
}

Int  main() {
    Int  cas = 0;
    While  (~scanf( "%d" , &n) && n) {
        Scanf( "%d%d" , &x, &y);
        Memset(vis, 0,  sizeof (vis));
        Memset(sum, 0,  sizeof (sum));
        For  ( int  i = 0; i < n; i++)
            Scanf( "%d" , &big[i]);
        For  ( int  state = 0; state < (1<<n); state++) {
            For  ( int  i = 0; i < n; i++)
                If  (state&(1<<i))
                    Sum[state] += big[i];
        }
        If  (sum[(1<<n)-1] != x * y) {printf( "Case %d: No\n" , ++cas);  continue ;}
        Printf( "Case %d: %s\n" , ++cas, solve((1<<n) - 1, min(x, y))? "Yes" : "No" );
    }
    Return  0;
}
