#include <bits/stdc++.h>

using namespace std;

int a[100005];
long long c[100005];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 1; i<=n; ++i){
			scanf("%d",&a[i]);
			c[i] = a[i];
			c[i] = c[i] + c[i-1]; 
		}
		int day = 0;
		long long tot_know = 1;
		long long spread = a[1];
		while(tot_know<n){
			day++;
			long long prev = tot_know;
			tot_know = tot_know + spread;
			if(tot_know>=n){
				break;
			}
			spread = spread + (c[(int)tot_know]-c[prev]);
			//printf("%d %d\n",tot_know,spread);
			
		}
		printf("%d\n",day);
	}
	return 0;
}