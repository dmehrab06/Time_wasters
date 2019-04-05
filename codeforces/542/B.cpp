#include <bits/stdc++.h>

using namespace std;

int pos[100005][2];

long long simulate(int n){
	int mnn = 100000000;
	int x = 1, y = 1;
	long long tot = 0;
	for(int i = 1; i<=n; ++i){
		int pos1 = pos[i][0]; int pos2 = pos[i][1];
		int x2pos1 = min(abs(pos1-x),2*mnn-abs(pos1-x));
		int x2pos2 = min(abs(pos2-x),2*mnn-abs(pos2-x));
		int y2pos1 = min(abs(pos1-y),2*mnn-abs(pos1-y));
		int y2pos2 = min(abs(pos2-y),2*mnn-abs(pos2-y));
		int dis1 = x2pos1+y2pos2;
		int dis2 = x2pos2+y2pos1;
		int mnn = min(dis1,dis2);
		//cout<<i<<" "<<mnn<<"\n";
		tot = tot+mnn;
		x = pos1; y = pos2;
	}
	return tot;
}

int main(){
	memset(pos,-1,sizeof(pos));
	int n;
	cin>>n;
	for(int i = 1; i<=(n*2); ++i){
		int a;
		cin>>a;
		if(pos[a][0]==-1){
			pos[a][0] = i;
		}
		else{
			pos[a][1] = i;
		}
	}
	printf("%lld\n",simulate(n));
	return 0;
}