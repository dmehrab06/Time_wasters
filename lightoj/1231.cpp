#include <bits/stdc++.h>
#define MDD 100000007
using namespace std;

int value[61];
int ase[61];

long long dp[61][1003];

long long solve(int cur, int baki, int n){
	if(cur>n){
		if(baki==0)return 1;
		else return 0;
	}
	if(dp[cur][baki]!=-1)return dp[cur][baki];

	long long ret = 0;
	for(int i = 0; i<= ase[cur]; ++i){
		int val = i*value[cur];
		if((baki-val)>=0){
			ret = ret + solve(cur+1,baki-val,n);
			ret = ret%MDD;
		}
		else break;
	}

	return dp[cur][baki]  = ret;

}

int main()
{
	int t;
	scanf("%d",&t);
	for(int cs = 1; cs<=t; ++cs){
		int n,k;
		scanf("%d %d",&n,&k);
		memset(dp,-1,sizeof(dp));
		for(int i  = 1; i<=n; ++i){
			scanf("%d",&value[i]);
		}
		for(int i  = 1; i<=n; ++i){
			scanf("%d",&ase[i]);
		}
		printf("Case %d: %lld\n",cs, solve(1,k,n));
	}
	return 0;
}