#include <bits/stdc++.h>

using  namespace std;

int type[103];
int status[103];

int getdiff(int n){
	int e = 0;
	int s = 0;
	for(int i  = 1; i<=n; ++i){
		if(status[i]==1){
			if(type[i]==-1){
				e++;
			}
			else{
				s++;
			}
		}
	}
	return abs(e-s);
}

void simulate(int n, int k, int b){
	for(int i = b; i<=n; i+=k){
		status[i] = 0;
	}
	for(int i = b; i>=0; i-=k){
		status[i] = 0;
	}
}

void init(int n){
	for(int i  =1; i<=n; ++i){
		status[i]=1;
	}
}

int main(){
	int n,k;
	cin>>n>>k;
	for(int i = 1; i<=n; ++i){
		cin>>type[i];
	}
	int mxx = 0;
	for(int b = 1; b<=n; ++b){
		init(n);
		simulate(n,k,b);
		mxx = max(mxx,getdiff(n));
	}
	cout<<mxx<<"\n";
	return 0;
}