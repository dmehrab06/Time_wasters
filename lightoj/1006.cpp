#define DIV 10000007
#include <stdio.h>
long long int dp[10005];
long long int a, b, c, d, e, f;
long long int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=(fn(n-1)%DIV+fn(n-2)%DIV+fn(n-3)%DIV+fn(n-4)%DIV+fn(n-5)%DIV+fn(n-6)%DIV)%DIV;
    return dp[n];
}
int main() {
    int n;
    int caseno = 0;
    int cases;
    scanf("%d",&cases);
   //printf("esechi\n")'
    while( cases-- ) {
        int i=0;
        while(i<10005){
            dp[i]=-1;
            i++;
        }
        scanf("%lld %lld %lld %lld %lld %lld %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %lld\n", ++caseno, (fn(n)));
    }
    return 0;
}
