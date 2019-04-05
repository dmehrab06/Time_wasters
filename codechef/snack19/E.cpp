#include <bits/stdc++.h>

using namespace std;

long long mdd = 1000000007;

long long team[100005];

void pre(){
	team[2] = 1;
	for(int i = 4; i<100005; i+=2){
		team[i] = (long long)team[i-2]*(long long)(i-1);
		team[i] %= mdd;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	pre();
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int>skill;
		for(int i = 0;i<n; ++i){
			int a;
			scanf("%d",&a);
			skill.push_back(a);
		}
		sort(skill.begin(),skill.end());
		reverse(skill.begin(),skill.end());
		int s = 0;
		int e = 0;
		long long way = 1;
		while(s<skill.size()){
			while(e<skill.size() && skill[e]==skill[s]){
				e++;
			}
			int lok = (e-s);
			if(s%2==0 && (e-1)%2==1 && lok>1){
				//sobai nijera nijera form korbe
				//lok will be even
				way = way*team[lok];
				way = way%mdd;
			}
			else if(s%2==1 && (e-1)%2==0 && lok>1){
				way = way*team[lok-2];
				way = way%mdd;
				way = way*lok;
				way = way%mdd;
				way = way*(lok-1);
				way = way%mdd;
			}
			else if(lok>1){
				way = way*team[lok-1];
				way = way%mdd;
				way = way*lok;
				way = way%mdd;
			}
			s = e;
		}
		printf("%lld\n",way);
	}
	return 0;
}