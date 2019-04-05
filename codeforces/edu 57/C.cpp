#include <bits/stdc++.h>
#define MDD 998244353
using namespace std;

int ang[401];

int main(){
	for(int i = 1; i<=400; ++i){
		ang[i] = MDD;
	}
	for(int i = 3; i<=360; ++i){
		int lob = 360;
		int hor = (2*i);
		for(int j = 0; j<=(i-3); ++j){
			int curlob = lob*(j+1);
			if((curlob%hor)==0){
				int curang = curlob/hor;
				ang[curang] = min(i,ang[curang]);
			}
		}	
	}

	int t;
	scanf("%d",&t);
	for(int cs = 1; cs<=t; ++cs){
		int a;
		scanf("%d",&a);
		if(ang[a]==MDD){
			printf("-1\n");
		}
		else{
			printf("%d\n",ang[a]);
		}
	}
	return 0;
}