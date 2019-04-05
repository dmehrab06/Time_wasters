#include <bits/stdc++.h>

using namespace std;

pair<int,int> get(int n){
	for(int i = 1; i<=n; ++i){
		int j = n-i;
		if(i%3 && j%3){
			return make_pair(i,j);
		}
	}
	return make_pair(-1,-1);
}

int main(){
	int n;
	cin>>n;
	pair<int,int>ok = get(n-1);
	cout<<1<<" "<<ok.first<<" "<<ok.second<<"\n";
	return 0;
}