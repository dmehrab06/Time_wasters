#include <bits/stdc++.h>

using namespace std;

int calc(int n, int m, int x, int y){
	long long tot = 0;
	for(int i = 1; i<=n; ++i){
		for(int j = 1; j<=m; ++j){
			if(i==x && j==y)continue;
			int available = (n*m)-1;
			//check if king is in same row;
			if(x==i){
				int dis = abs(j-y);
				available  = available-(dis-1);
				if(y>j){
					//king is right of queen
					//then discard all left places
					available = available - (j-1);
				}
				else{
					//discard all right places
					available = available - (m-j);
				}
			}
			else{
				available = available - (m-1);
			}
			//check if king is in same col
			if(y==j){
				int dis = abs(i-x);
				available = available - (dis-1);
				if(x>i){
					//king is down of queen
					//then discard all up places
					available = available - (i-1);
				}
				else{
					//discard all down places
					available = available - (n-i);
				}
			}
			else{
				available = available - (n-1);
			}
			//check if king is in same pos diag
			if((x-y)==(i-j)){
				int dis = abs(i-x);
				available = available - (dis-1);
				int upore = min(i-1,j-1);
				int niche = min(n-i,m-j);
				if(x>i){
					available = available - upore;
				}
				else{
					available = available - niche;
				}
			}
			else{
				int upore = min(i-1,j-1);
				int niche = min(n-i,m-j);
				available = available - (upore+niche);
			}
			//check if king is in same neg diag
			if((x+y) == (i+j)){
				int dis = abs(i-x);
				available = available - (dis-1);
				int upore = min(i-1,m-j);
				int niche = min(n-i,j-1);
				if(x>i){
					available = available - upore;
				}
				else{
					available = available - niche;
				}
			}
			else{
				int upore = min(i-1,m-j);
				int niche = min(n-i,j-1);
				available = available - (upore+niche);
			}
			tot = tot + (available-1);
			//cout<<"for "<<i<<" "<<j<<" "<<available-1<<" places free\n";
		}
		
	}
	return tot;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,x,y;
		scanf("%d %d %d %d",&n,&m,&x,&y);
		long long ans = calc(n,m,x,y);
		printf("%lld\n",ans );
	}
	return 0;
}