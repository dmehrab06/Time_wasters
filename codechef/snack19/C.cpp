#include <bits/stdc++.h>

using namespace std;

vector<int>semips;
map<int,int>semimap;

vector<int>ps;

int allp[203];

void sieve(){
	for(int i = 2; i<203; ++i){
		if(allp[i]==0){
			ps.push_back(i);
			for(int j = i+i; j<203; j+=i){
				allp[j] = 1;
			}
		}
	}
	for(int i = 0;i<ps.size(); ++i){
		for(int j = (i+1); j<ps.size(); ++j){
			int p1 = ps[i];
			int p2 = ps[j];
			int ppp = p1*p2;
			semimap[ppp] = 1;
			semips.push_back(ppp);
		}
	}
}

int main(){
	sieve();
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int f = 0;
		for(int i = 0;i<semips.size(); ++i){
			int a = semips[i];
			if(semimap.find(n-a)!=semimap.end()){
				f = 1;
				printf("YES\n");
				break;
			}
		}
		if(!f){
			printf("NO\n");
		}
	}
	return 0;
}