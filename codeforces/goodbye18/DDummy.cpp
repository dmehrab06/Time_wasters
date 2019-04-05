#include <bits/stdc++.h>
#define MDD 998244353
using namespace std;

long long int dp1[1000006];
long long int dp2[1000006];

void pre(){
	dp1[1] = 1;
	dp2[1] = 1;
	for(int i = 2; i<=1000000; ++i){
		dp1[i] = (dp1[i-1]+dp2[i-1]-1)*i;
		dp1[i] = dp1[i]%MDD;
		dp2[i] = dp2[i-1]*i;
		dp2[i] = dp2[i]%MDD;
	}
}

int main(){
	pre();
	int n;
	scanf("%d",&n);
	printf("%lld\n",dp1[n]);
	return 0;
}