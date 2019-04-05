#include <bits/stdc++.h>

using namespace std;

char vola[503][503];
int dx[] = {-1,-1,1,1};
int dy[] = {-1,1,-1,1};

int cnt(int n){
	int tot = 0;
	for(int i = 0; i<n; ++i){
		for(int j = 0; j<n; ++j){
			int cc = 0;
			if(vola[i][j]=='X'){
				for(int k = 0; k<4; ++k){
					int ii = i+dx[k];
					int jj = j+dy[k];
					if(ii>=0 && ii<n && jj>=0 && jj<n){
						if(vola[ii][jj]=='X'){
							cc++;
						}
					}
				}
				if(cc==4)tot++;
			}
		}
	}
	return tot;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; ++i){
		scanf("%s",vola[i]);
	}
	printf("%d\n",cnt(n));
	return 0;
}