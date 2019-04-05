#include <bits/stdc++.h>

using namespace std;


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		vector<int>sc;
		for(int i = 0;i<n;++i){
			int a;
			scanf("%d",&a);
			sc.push_back(a);
		}
		sort(sc.begin(),sc.end());
		reverse(sc.begin(),sc.end());
		int scc = sc[k-1];
		int qual = k;
		for(int ll = k; ll<n; ++ll){
			if(sc[ll]==scc){
				qual++;
			}
			else{
				break;
			}
		}
		printf("%d\n",qual);
	}
	return 0;
}