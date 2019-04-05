#include <bits/stdc++.h>

using namespace std;

int main(){
	long long al, ar, ta;
	long long bl, br, tb;
	scanf("%lld %lld %lld",&al,&ar,&ta);
	scanf("%lld %lld %lld",&bl,&br,&tb);
	if(al<bl){
		al = 0;
		ar = ar - al;
		bl = bl - al;
		br = br - al;
	}
	else{
		al = al - bl;
		ar = ar - bl;
		bl = 0;
		br = br - bl;
		swap(al,bl);
		swap(ar,br);
		swap(ta,tb);	
	}
	//al starts from 0
	//bl starts from elsewhere
	long long gg = __gcd(ta,tb);
	if(gg==1){
		long long ans = min((ar-al+1),(br-bl+1));
		printf("%lld\n",ans);
	}
	else{
		long long prev = 0;
		for(long long st = (bl%ta); st < ta ; st = st + gg){
			long long ed = st + (br-bl);
			long long mined = min(ed,ar);
			long long maxst = max(st,al);
			long long dis;
			if(maxst>mined){
				dis = 0;
			}
			else{
				dis = (mined - maxst + 1);
			}
			if(dis>=prev){
				prev = dis;
			}
		}
		for(int i = 1; i<=4; ++i){
			long long anotherst = (bl%ta) - gg;
			long long anothered = (anotherst) + (br-bl);
			long long mined = min(anothered,ar);
			long long maxst = max(anotherst,al);
			long long dis;
			if(maxst>mined){
				dis = 0;
			}
			else{
				dis = (mined - maxst + 1);
			}
			if(dis>=prev){
				prev = dis;
			}	
		}
		
		printf("%lld\n", prev);
	}
	return 0;
}