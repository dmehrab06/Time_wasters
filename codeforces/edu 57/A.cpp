#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int cs = 1; cs<=t; ++cs){
		int ang;
		scanf("%d",&ang);
		int mnn = -1;
		for(int j = ang; j>=1; --j){
			if((ang%j)==0){
				int tr = ang/j;
				if((360%(180-tr))==0){
					int n = 360/(180-tr);
					if(mnn==-1 || n<mnn){
						mnn = n;
					}
				}
			}
		}
		printf("%d\n",mnn);
	}
	return 0;
}