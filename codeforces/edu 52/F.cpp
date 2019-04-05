#include <bits/stdc++.h>

int main(){
	int t;
	cin>>t;
	while(t--){
		int s,a,b,c;
		cin>>s>>a>>b>>c;
		int kinbo = s/c;
		int extra_pabo = (kinbo/a)*b;
		int emni_thakbe = (kinbo%a);
		long long s = kinbo+extra_pabo+emni_thakbe;
		cout<<s<<"\n";
	}
	return 0;
}