#include <bits/stdc++.h>
using namespace std;

long long dp[5003][5003][3];

char ss[5003];

long long solve(int beg, int ed, int caninsert){
    if(beg==ed)return dp[beg][ed][caninsert]=0;
    if(beg>ed)return 100000000000;
    if(dp[beg][ed][caninsert]!=-1)return dp[beg][ed][caninsert];
    long long ret1 = 10000000000, ret2 = 10000000000, ret3 = 10000000000;
    if(ss[beg]==ss[ed])ret1 = solve(beg+1,ed-1,0);
    if(caninsert)ret2 = (long long)1+solve(beg+1,ed,1);
    ret3 = (long long)1+solve(beg+1,ed-1,0);
    return dp[beg][ed][caninsert] = min(ret1,min(ret2,ret3));
}

int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%s",ss);
    int ll = strlen(ss);
    long long ans = solve(0,ll-1,1);
    printf("%lld\n",ans);
    return 0;
}
