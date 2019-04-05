#include <bits/stdc++.h>
using namespace std;

long long int gettotal1(int n){
	long long int a = (long long)n*(long long)(n+1);
	return a/2;
}

int main(){
	int n; string s;
	cin>>n; cin>>s;
	int l = 0, r = (int)s.size()-1;

	while( ((l+1)<(int)s.size()) && (s[l+1]==s[0]) ){
		l++;
	}
	while( ((r-1)>=0) && s[r-1]==s[(int)s.size()-1]){
		r--;
	}
	cout<<l<<" "<<r<<"\n";
	if(l>r){
		//purata same character
		cout<<gettotal1(n)<<"\n";
	}
	else{
		if(s[l]==s[r]){
			long long ll = l+2;
			long long rr = (n-r)+1;
			cout<<(ll*rr)<<"\n";
		}
		else{
			long long ll = l+2;
			long long rr = (n-r)+1;
			cout<<(ll+rr-1)<<"\n";
			//cout<<3<<"\n";
		}
	}
	return 0;
}