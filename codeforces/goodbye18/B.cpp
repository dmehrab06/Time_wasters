#include <bits/stdc++.h>
#define MDD 998244353
using namespace std;

set< pair<int,int> >obelisk;
set< pair<int,int> >clue;

vector< pair<int,int> >ov;
vector< pair<int,int> >cv;  

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; ++i){
		int x,y;
		scanf("%d %d",&x,&y);
		pair<int,int>pp = make_pair(x,y);
		obelisk.insert(pp);
		ov.push_back(pp);
	}
	for(int i = 0; i<n; ++i){
		int x,y;
		scanf("%d %d",&x,&y);
		pair<int,int>pp = make_pair(x,y);
		clue.insert(pp);
		cv.push_back(pp);
	}
	pair<int,int>pivot = ov[0];
	for(int j = 0; j<n; ++j){
		pair<int,int>mapt = cv[j];
		pair<int,int>treasure = make_pair(pivot.first+mapt.first,pivot.second+mapt.second);
		int f = 1;
		for(int i = 0; i<n; ++i){
			pair<int,int>tofind = make_pair(treasure.first-ov[i].first,treasure.second-ov[i].second);
			if(clue.find(tofind)==clue.end()){
				f = 0;
				break;
			}
		}
		if(f){
			printf("%d %d\n",treasure.first,treasure.second);
			return 0;
		}
	}
	printf("janina ki holo\n");
	return 0;
}