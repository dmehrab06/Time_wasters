#include <bits/stdc++.h>

using namespace std;

map<int,int>hcnt;

long long height_view[200005];
int towheight[200005];

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int mxx = 0;
	int mnn = 300000;
	for(int i = 0; i<n; ++i){
		scanf("%d",&towheight[i]);
		hcnt[towheight[i]]++;
		mxx = max(mxx,towheight[i]);
		mnn = min(mnn,towheight[i]);
	}
	int cur = n;
	for(int i = 1;i<=mxx;++i){
		height_view[i] = cur;
		cur = cur-hcnt[i];
 	}
 	int slice = 0;
 	long long ekhon = 0;
 	for(int curh = mxx; curh>mnn; curh--){
 		if((ekhon+height_view[curh])>k){
 			slice++;
 			ekhon = 0;
 		}	
 		ekhon = ekhon+height_view[curh];
 	}
 	if(ekhon!=0){
 		slice++;
 	}
 	cout<<slice<<"\n";
	return 0;
}