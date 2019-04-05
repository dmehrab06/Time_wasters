#include <bits/stdc++.h>
#define MDD 1000000007
using  namespace std;

int dp[40003][3];

vector<long long int>meh;


void solve(int n, int k){
	for(int i = 0; i<n; ++i){
		dp[i][1] = 1;
	}
	for(int i = 2; i<=k; ++i){
		for(int j = (n-1); j>=0; --j){
			int s = 0;
			for(int k = j; k<n; ++k){
				if((meh[k]%meh[j])==0){
					s = s+dp[k][1];
					s = s%MDD;
				}
			}
			dp[j][2] = s;
		}
		for(int j = 0; j<n; ++j){
			dp[j][1] = dp[j][2];
		}
	}
}


void cntdiv(long long int n){
	long long int sq = sqrt(n);
	for(long long int i = 1; i<=sq; ++i){
		if((n%i)==0){
			long long int j = n/i;
			meh.push_back(i);
			if(j!=i){
				meh.push_back(j);
			}
		}
	}
	sort(meh.begin(),meh.end());
	return;
}

long long int bigmod(long long int a, long long int P){
	if(P==0)return (long long)1;
	long long int ret = bigmod(a,P/2);
	if((P%2)==0){
		return (ret*ret)%MDD;
	}
	else{
		return (((a*(ret))%MDD)*ret)%MDD;
	}
}

long long int PQinv(long long int P, long long int Q){
	long long int modinv = bigmod(Q,MDD-2);
	return (P*modinv)%MDD;
}


int main(){
	//long long int n;
	//scanf("%lld",&n);
	//cout<<PQinv(20,9)<<"\n";
	long long int n; int k;
	scanf("%lld %d",&n,&k);
	cntdiv(n);
	int sz = (int)meh.size();
	solve(sz,k);
	long long int Q = 0, P = 0;
	for(int i = 0; i<n;++i){
		P = P + meh[i]*dp[i][1];
		Q = Q + dp[i][1];
		P = P%MDD;
		Q = Q%MDD;
	}
	printf("%lld\n",PQinv(P,Q));
	return 0;
}