#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int trie[MAXN][2];
int finish[MAXN];

int available = 1;

void add_String(int num){
	int cur = 0; int mask = 1<<31;
	for(int i = 0; i<32; ++i){
		int curbit = (num&mask)?1:0;
		if(trie[cur][curbit]==0){
			trie[cur][curbit] = available;
			available++;
		}
		cur = trie[cur][curbit];
		mask = mask>>1;
	}
	finish[cur] = 1;
}

int getsomething(int comp){
	int cur = 0; int mask = 1<<31;
	int made = 0;
	for(int i = 0; i<32; ++i){
		int curbit = (comp&mask)?1:0;
		if(trie[cur][1-curbit]){
			made = (made<<1)+(1-curbit);
			cur = trie[cur][1-curbit];
		}
		else{
			cur = trie[cur][curbit];
			made = (made<<1)+curbit;
		}
	}
	return made;
}

int arr[100005];
int xors[100005];

int main(){
	int t;
	scanf("%d",&t);
	for(int cs = 1; cs<=t; ++cs){
		int n;
		scanf("%d",&n);
		int mxx = 0;
		for(int i = 0; i<n; ++i){
			int a;
			scanf("%d",&a);
			arr[i] = a;
			xors[i] = xors[i-1]^a;
			mxx = max(mxx,getsomething(xors[i]));
			add_String(xors[i]);
		}
		printf("%d\n",mxx);
	}
	return 0;
}