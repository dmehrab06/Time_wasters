#include <bits/stdc++.h>
#define MDD 998244353
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int mxx = 0;
	for(int i = 0; i<=a; ++i){
		if((i+1)<=b && (i+2)<=c){
			int s =  i + (i+1) + (i+2);
			mxx = max(s,mxx);
		}
	}
	cout<<mxx<<"\n";
	return 0;
}