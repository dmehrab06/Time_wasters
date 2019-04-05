#include <bits/stdc++.h>

using namespace std;

long long hair[100005];

int main(){
	int n,m,l;
	scanf("%d %d %d",&n,&m,&l);
	for(int i = 1; i<=n; ++i)scanf("%lld",&hair[i]);
	int seg = 0;
	int cholche = 0;
	for(int i = 1; i<=n; ++i){
		if(hair[i]>l){
			cholche = 1;
		}
		else{
			if(cholche){
				cholche = 0;
				seg++;
			}
		}
	}
	if(cholche){
		seg++;
	}
	for(int i = 1; i<=m; ++i){
		int type;
		scanf("%d",&type);
		if(type==0){
			printf("%d\n",seg);
		}
		else{
			int p, grow;
			scanf("%d %d",&p,&grow);
			if(hair[p]>l){
				//nothing will happen;
				hair[p] = hair[p] + grow;
			}
			else{
				hair[p] = hair[p] + grow;
				if(hair[p]>l){
					seg = seg + 1;
					if(p>1 && hair[p-1]>l){
						seg = seg - 1;
					}
					if(p<n && hair[p+1]>l){
						seg = seg - 1;
					}	
				}
				
			}
		}
	}
	return 0;
}