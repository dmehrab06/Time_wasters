#include <bits/stdc++.h>

using  namespace std;

int diffreq[100005];

int prob[100005];

int curhave = 0;

void holdround(int n){
	for(int i = 1; i<=n; ++i){
		diffreq[i] = diffreq[i]-1;
		if(diffreq[i]==0)curhave--;
	}
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1; i<=m; ++i){
		scanf("%d",&prob[i]);
	}
	//int round = 0;
	for(int i = 1; i<=m; ++i){
		int cur = prob[i];
		if(diffreq[cur]==0){
			curhave++;
		}
		diffreq[cur]++;
		if(curhave==n){
			holdround(n);
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");
	return 0;
}