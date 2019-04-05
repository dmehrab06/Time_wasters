#include <bits/stdc++.h>

using namespace std;

int arr[300005];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i<=n; ++i)scanf("%d",&arr[i]);
	sort(arr+1,arr+1+n);
	long long s = 0;
	for(int i = 1; i<=n/2; ++i){
		long long pp = arr[i]+arr[n-i+1];
		pp = pp*pp;
		s = s+pp;
	}
	printf("%lld\n",s);
	return 0;
}