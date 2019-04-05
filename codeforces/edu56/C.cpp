#include <bits/stdc++.h> 
#define MDD 998244353

using namespace std;

long long int dp[2003][2003];

long long int solve(int i, int k, int n, int m){
	if(i==n && k==0)return 1;
	if(i==n && k!=0)return 0;
	if(dp[i][k]!=-1)return dp[i][k];
	long long int way = 0;
	if(i==0){
		way = way + solve(i+1,k,n,m);
		way = way%MDD;
	}
	else{
		way = way + solve(i+1,k,n,m);
		way = way%MDD;
		if(k>0){
			way = way+(m-1)*solve(i+1,k-1,n,m);
		}
		way = way%MDD;
	}
	return dp[i][k] = way;
}

int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	memset(dp,-1,sizeof(dp));
	long long ans = m*solve(0,k,n,m);
	cout<<ans%MDD<<"\n";
	return 0;
}