/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define eps 1e-9
#define MDD 1000000007

using namespace std;

long long dp[503][503];

long long solve(int st, int ed, int n){
    if(st+1==ed){
        long long v1 = st;
        long long v2 = (st+1)%n;
        long long v3 = (ed+1)%n;
        return (v1+1)*(v2+1)*(v3+1); 
    }
    if(st+2==ed){
        long long v1 = st;
        long long v2 = (st+1)%n;
        long long v3 = (st+2)%n;
        long long v4 = (st+3)%n;
        long long cost1 = (v1+1)*(v2+1)*(v3+1)+(v1+1)*(v3+1)*(v4+1);
        long long cost2 = (v1+1)*(v2+1)*(v4+1)+(v2+1)*(v3+1)*(v4+1);
        return min(cost1,cost2);
    }
    if(dp[st][ed]!=-1)return dp[st][ed];

    long long ret1 = 0, ret2 = 0;
    long long v1 = st;
    long long v2 = (st+1)%n;
    long long v3_1 = (ed+1)%n;
    long long v3_2 = (st+2)%n;

    ret1 = (v1+1)*(v2+1)*(v3_1+1) + solve(st+1,ed-1,n);
    ret2 = (v1+1)*(v2+1)*(v3_2+1) + solve(st+2,ed,n);

    return dp[st][ed] = min(ret1,ret2);
}

int main(){
    int n;
    cin>>n;
    
    long long ans = 0;
    for(int i = 2; i<n; ++i){
        ans = ans + (i*(i+1));
    }

    
    cout<<ans<<"\n";
    return 0;
}