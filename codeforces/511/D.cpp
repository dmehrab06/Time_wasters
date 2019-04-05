#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n,m;
	cin>>n>>m;
	long long mn = min(n,m);
	long long mx = max(n,m);
	if(mx<=2){
		cout<<"0\n";
	}
	else{
		if(mn==2){
			if(mx==3){
				cout<<"4\n";
			}
			else{
				cout<<mn*mx<<"\n";
			}
		}
		else if(mn==1){
			if(mx<=3){
				cout<<"0\n";
			}
			else if(mx==4){
				cout<<"1\n";
			}
			else{
				if(mx%2){
					cout<<mx-1<<"\n";
				}
				else{
					cout<<mx<<"\n";
				}
			}
		}
		else{
			long long ok = mx*mn;
			if(ok%2){
				cout<<ok-1<<"\n";
			}
			else{
				cout<<ok<<"\n";
			}
		}
	}
	return 0;
}