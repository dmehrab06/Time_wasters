#include <bits/stdc++.h>

using namespace std;

int all[200005][2];

vector<int>hello;

void findfirst3(){
	int a = all[1][0];
	int b = all[1][1];

	hello.push_back(1);

	if(all[b][0]==a || all[b][1]==a){
		hello.push_back(b);
		hello.push_back(a);
	}

	else if(all[a][0]==b || all[a][1]==b){
		hello.push_back(a);
		hello.push_back(b);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i<=n; ++i){
		scanf("%d %d",&all[i][0],&all[i][1]);
	}
	findfirst3();
	for(int i = 1;i<=(n-3); ++i){
		int cur = hello[i];
		int b1 = all[cur][0];
		int b2 = all[cur][1];
		if(b1==hello[i+1]){
			hello.push_back(b2);
		}
		else{
			hello.push_back(b1);
		}
	}
	for(int i = 0; i<(int)hello.size(); ++i){
		cout<<hello[i]<<" ";
	}
	cout<<"\n";
	return 0;
}