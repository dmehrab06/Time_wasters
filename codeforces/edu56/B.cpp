#include <bits/stdc++.h> 
#define MDD 998244353

using namespace std;

int freq[100005];
int lok[100005];

int main(){
	int n;
	scanf("%d",&n);
	vector< pair<int,int> >phat;
	vector<int>assignhat;
	for(int i = 0; i<n; ++i){
		int h;
		scanf("%d",&h);
		freq[h] = freq[h] + 1;
		phat.push_back(make_pair(h,i));
	}
	sort(phat.begin(),phat.end());
	reverse(phat.begin(),phat.end());
	//for(int i = 0; i<phat.size();++i)cout<<phat[i].first<<" "<<phat[i].second<<" ";
	//	cout<<"\n";
	int curhat = 1;
	int f = 1;
	int diff = 0;
	for(int i = 0; i<phat.size();){
		int cur = phat[i].first;
		//cout<<"at "<<cur<<"\n";
		if(diff==0){
			int ase = freq[cur];
			if((ase+cur)!=n){
				f = 0;
				break;
			}
			for(int j = i; phat[j].first==cur;++j){
				assignhat.push_back(curhat);
				i = j+1;
				diff = diff+1;
			}
			//cout<<"next i: "<<i<<"\n";
			curhat = curhat + 1;
		}
		else{
			if(cur>=diff){
				int baki = (n-diff)-(cur-diff);
				for(int j = 0; j<baki; ++j){
					assignhat.push_back(curhat);
				}
				i = i+baki;
				diff = diff+baki;
				curhat = curhat + 1;
			}
			else{
				f = 0;
				break;
			}
		}
	}
	if(!f){
		printf("Impossible\n");
	}
	else{
		printf("Possible\n");
		for(int i = 0; i<n;++i){
			int idx = phat[i].second;
			int ht = assignhat[i];
			lok[idx] = ht;
		}
		for(int i = 0;i<n;++i){
			printf("%d ",lok[i]);
		}
		printf("\n");
	}
	return 0;
}