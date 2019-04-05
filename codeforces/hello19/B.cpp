#include <bits/stdc++.h>

using  namespace std;

int angg[20];

int getangle(int curmask, int n){
	int msk = 1;
	int ang = 0;
	for(int i = 0; i<n; ++i){
		if(curmask&msk){
			ang = ang+angg[i]; 
		}
		else{
			ang = ang-angg[i];
		}
		msk = msk<<1;
	}
	cout<<ang<<"\n";
	while(ang<0){
		ang = ang+360;
	}
	return (ang%360);
}

int main(){
	int n;
	cin>>n;
	int mxmask = (1<<n);
	for(int i = 0; i<n; ++i){
		cin>>angg[i];
	}
	for(int i = 0; i<mxmask; ++i){
		//int a = getangle(i,n);
		//cout<<i<<" "<<a<<"\n";
		if(getangle(i,n)==0){
			cout<<"YES\n";
			//return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}