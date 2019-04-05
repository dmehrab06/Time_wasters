#include <bits/stdc++.h>

using namespace std;

int arr[200005];

int main()
{
	int n, s;
	scanf("%d %d",&n,&s);
	for(int i = 1;i<=n; ++i){
		scanf("%d",&arr[i]);
	}
	sort(arr+1,arr+1+n);
	long long op = 0;
	int mididx = n/2+1;
	for(int i = 1; i<(mididx);++i){
		if(arr[i]>s){
			op = op+(abs(s-arr[i]));
		}
	}
	for(int i = (mididx+1);i<=n;++i){
		if(arr[i]<s){
			op = op+(abs(s-arr[i]));
		}
	}
	op = op + abs(s-arr[mididx]);
	printf("%lld\n",op );
	return 0;
} 