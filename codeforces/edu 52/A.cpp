#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int s,a,b,c;
		cin>>s>>a>>b>>c;
		int kinbo = s/c;
		long long extra_pabo = (long long)(kinbo/a)*b;
		//cout<<kinbo<<" "<<extra_pabo<<"\n";
		long long ss = (long long)kinbo+extra_pabo;
		cout<<ss<<"\n";
	}
	return 0;
}