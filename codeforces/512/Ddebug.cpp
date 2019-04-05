#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,k;
		
	while(cin>>n>>m>>k){
		if((2*n*m)%k){
			//cout<<"NO\n";
		}
		else{
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
				cout<<"processing "<<n<<" "<<m<<" "<<k<<"\n";
		
				cout<<"could not\n";
				//should never reach here
				//for(long long i = 1;i<=10000000000000; ++i){
					//cout<<"TLE\n";
				//}
			}
		}
	}
}