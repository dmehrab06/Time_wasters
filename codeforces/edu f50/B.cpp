#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--){
		long long x,y;
		scanf("%lld %lld",&x,&y);
		long long k;
		scanf("%lld",&k);
		long long xx = max(x,y);
		long long yy = min(x,y);
		long long dif = abs(xx-yy);
		if(k<xx){
			cout<<"-1\n";
		}
		else{
			if(dif%2==0){
				if((k-xx)%2==0){
					cout<<k<<"\n";
				}
				else{
					cout<<k-2<<"\n";
				}
			}
			else{
				cout<<k-1<<"\n";
			}	
		}
		
	}
	return 0;
}