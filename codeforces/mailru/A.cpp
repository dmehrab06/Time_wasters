#include <bits/stdc++.h>

using namespace std;

int a[1003];
int b[1003];

int main(){
	int n,s;
	cin>>n>>s;
	for(int i = 1;i<=n;++i)scanf("%d",&a[i]);
	for(int i = 1;i<=n;++i)scanf("%d",&b[i]);

	if(a[1]!=1){
		cout<<"NO\n";
	}
	else{
		if(a[s]==1){
			cout<<"YES\n";
		}
		else{
			if(b[s]!=1){
				cout<<"NO\n";
			}
			else{
				int f = 0;
				for(int j=1;j<=n;++j){
					if(a[j]){
						if(b[j]){
							f = 1;
							break;
						}
					}
				}
				if(!f){
					cout<<"NO\n";
				}
				else{
					cout<<"YES\n";
				}
			}
		}
	}
	return 0;
}