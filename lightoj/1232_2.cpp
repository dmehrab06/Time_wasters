#include <bits/stdc++.h>
#define MDD 100000007
using namespace std;

int value[103];

int dp[103][10003];

int solve(int n, int k){
	dp[0][0] = 1;
	for(int i = 1;i<=k; ++i){
		dp[0][i] = 0;
	}
	for(int i = 1;i<=n; ++i){
		dp[i][0] = 1;
	}
	for(int i = 1; i<=n; ++i){
		for(int j = 1; j<=k; ++j){
			int val = -value[i];
			for(int kk = 0; kk<=k; ++kk){
				val = val+value[i];
				if((j-val)>=0){
					dp[i][j] = dp[i][j]+dp[i-1][j-val];
					if(dp[i][j]>=MDD){
						dp[i][j]-=MDD;
					}
				}
				else{
					break;
				}
			}
		}
	}
	return dp[n][k];
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int cs = 1; cs<=t; ++cs){
		int n,k;
		scanf("%d %d",&n,&k);
		for(int i =1; i<=n; ++i)scanf("%d",&value[i]);
		sort(value+1,value+1+n);
		memset(dp,0,sizeof(dp));
		printf("Case %d: %d\n",cs,solve(n,k));
	}
	return 0;
}