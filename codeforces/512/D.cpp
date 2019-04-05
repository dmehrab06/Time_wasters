#include <bits/stdc++.h>

using namespace std;

int main()
{
	while(true){
		long long n,m,k;
		cin>>n>>m>>k;
		if((2*n*m)%k){
			//cout<<"NO\n";
		}
		else{
			while((n%2==0) && (k%2)==0 && k>4){
				n/=2;
				k/=2;
			}
			while((m%2==0) && (k%2)==0 && k>4){
				m/=2;
				k/=2;
			}
			//cout<<"YES\n";
			long long lob = k-2;
			long long hor = k;
			long long g = __gcd(lob,hor);
			lob/=g;
			hor/=g;
			if(n%hor==0){
				//cout<<"0 0\n";
				//cout<<n<<" "<<m<<"\n";
				//cout<<(n/hor)*lob<<" "<<m<<"\n";
			}
			else if(m%hor==0){
				//cout<<"0 0\n";
				//cout<<n<<" "<<m<<"\n";
				//cout<<n<<" "<<(m/hor)*lob<<"\n";
			}
			else{
				cout<<n<<" "<<m<<" "<<k<<"\n";
				//cout<<"0 0\n";
				/*long long thingy = n*m;
				long long gg = __gcd(thingy,k);
				thingy/=gg;
				thingy = thingy*(k-2);
				k/=gg;
				thingy/=k;
				if(n>m){
					cout<<n<<" "<<m<<"\n";
					cout<<thingy<<" "<<1<<"\n";
				}
				else{
					cout<<n<<" "<<m<<"\n";
					cout<<1<<" "<<thingy<<"\n";
				}*/
			}
		}	
	}
	
	return 0;
}