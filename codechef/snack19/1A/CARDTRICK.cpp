#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int arr2[100005];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 1;i<=n; ++i){
			scanf("%d",&arr[i]);
		}
		arr[n+1] = 0;
		int tot = 0;
		int j = 1;
		int bari = -1;
		while(j<=n){
			while(j<=n && arr[j]>=arr[j-1]){
				j++;
			}
			if(j<=n){
				//cout<<j<<" te ese bari khailam\n";
				bari = j;
				j++;
				tot++;	
			}
			
		}
		tot++;
		if(tot<=2){
			if(bari==-1){
				printf("YES\n");	
			}
			else{
				int kk = 1;
				for(int k = bari; k<=n; ++k){
					arr2[kk] = arr[k];
					kk++; 
				}	
				int k2 = 1;
				while(kk<=n){
					arr2[kk] = arr[k2];
					kk++;
					k2++;
				}
				int f = 1;
				for(int i = 2; i<=n;++i){
					if(arr2[i]<arr2[i-1]){
						f = 0;
						break;
					}
				}
				if(f){
					printf("YES\n");
				}
				else{
					printf("NO\n");
				}
			}
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}