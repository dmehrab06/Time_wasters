#include <bits/stdc++.h>
#define MDD 998244353
using namespace std;

vector< long long int > allfun;


int main(){
	int n;
	scanf("%d",&n);
	if(n>3){
		long long int s = 1;
		for(int i = 4; i<=n; ++i){
			s = s*i;
			s = s%MDD;
		}
		long long int s2 = (n-1)*3+(n-2)*2+(n-3);
		s2 = s2%MDD;
		s = s*s2;
		s = s%MDD;
		printf("%lld\n",s);
	}
	else{
		printf("\n");	
	}
	
	return 0;
}