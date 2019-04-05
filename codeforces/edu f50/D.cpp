#include <bits/stdc++.h>

using namespace std;

int A[300005];
int B[300005];

int getseg(int na, int nb){
	int ia = 0;
	int ib = 0;
	long long sa = 0, sb = 0;
	long long seg = 0;
	while(ia<na || ib<nb){
		if(sa<=sb){
			if(ia<na){
				sa+=A[ia+1];
				ia++;
			}
			else{
				sb+=B[ib+1];
				ib++;
			}
		}
		else{
			if(ib<nb){
				sb+=B[ib+1];
				ib++;
			}
			else{
				sa+=A[ia+1];
				ia++;
			}	
		}
		if(sa==sb){
			seg++;
			sa = 0;
			sb = 0;
		}
	}
	if(sa==0 && sb==0){
		return seg;
	}
	else
		return -1;
}

int main(){
	int na;
	scanf("%d",&na);
	for(int i = 1;i<=na;++i){
		scanf("%d",&A[i]);
	}
	int nb;
	scanf("%d",&nb);
	for(int i = 1;i<=nb;++i){
		scanf("%d",&B[i]);
	}
	printf("%d\n", getseg(na,nb));
}