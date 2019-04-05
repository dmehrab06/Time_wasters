#include <bits/stdc++.h>

using namespace std;

long long int A[100005];
long long int B[100005];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int f = 1;
		for(int i = 1;i<=n;++i)scanf("%lld",&A[i]);
		for(int i = 1;i<=n;++i)scanf("%lld",&B[i]);

		for(int i = 1;i<=(n-2); ++i){
			int dif = B[i]-A[i];
			if(dif==0){
				continue;
			}
			if(dif<0){
				f = 0;
				break;
			}
			A[i] = A[i] + dif;
			A[i+1] = A[i+1]+ 2*dif;
			A[i+2] = A[i+2] + 3*dif;
		}
		if(!f){
			printf("NIE\n");
		}
		else{
			if(A[n-1]==B[n-1] && A[n]==B[n]){
				printf("TAK\n");
			} 
			else{
				printf("NIE\n");
			}
		}
	}
	return 0;
}