#include <bits/stdc++.h>

using namespace std;

int ok[15000003];
int isset[15000003];

int main(){
	int n;
	scanf("%d",&n);
	int g = -1;
	int mxx = -1;
	for(int i = 0;i<n;++i){
		int a;
		scanf("%d",&a);
		ok[a]++;
		if(g==-1)g=a;
		else g = __gcd(g,a);
		mxx = max(mxx,a);
	}
	//5cout<<g<<"\n";
	int mx = 0;
	for(int i = g+1; i<=mxx; ++i){
		int s = 0;
		if(!isset[i]){
			for(int j = i; j<=mxx; j+=i){
				s+=ok[j];
				isset[j] = 1;
			}	
		}
		
		//cout<<i<<" "<<s<<"\n";
		mx = max(mx,s);
	}
	//cout<<mx<<"\n";
	if(mx==0){
		printf("-1\n");
	}
	else{
		printf("%d\n",n-mx);
	}
	return 0;
}