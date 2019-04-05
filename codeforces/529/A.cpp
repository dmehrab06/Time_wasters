#include <bits/stdc++.h>

using namespace std;

int getlen(int l){
	int s = 0;
	for(int i = 1; ;++i){
		s = s+i;
		if(s==l){
			return i;
		}
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int l = getlen(n);
	int cur = 0;
	for(int i=0;i<l;++i){
		cout<<s[cur];
		cur = cur+(i+1);
	}
	cout<<"\n";
	return 0;
}