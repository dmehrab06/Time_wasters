#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int>ss;
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; ++i){
		int a;
		cin>>a;
		ss.push_back(a);
	}
	sort(ss.begin(),ss.end());
	int oka1 = ss[ss.size()-1]-ss[1];
	int oka2 = ss[ss.size()-2]-ss[0];
	cout<<min(oka1,oka2)<<"\n";
	return 0;
}