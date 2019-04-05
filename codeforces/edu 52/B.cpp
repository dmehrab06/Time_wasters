#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,m;
	cin>>n>>m;
	if(m==0){
		cout<<n<<" "<<n<<"\n";
		return 0;
	}
	long long mnn = max((long long)0,n-2*m);
	long long curn = 1;
	long long curedge = 0;
	for(int i = 2; i<=n && curedge<m; ++i){
		curedge = curedge + (i-1);
		curn = i;
	}
	cout<<mnn<<" "<<(n-curn)<<"\n";
	return 0;
}