#include <bits/stdc++.h>
#define MDD 998244353
using namespace std;

vector< long long int > allfun;

long long getsum(long long int a, long long int d, long long int n){
	//cout<<"getting sum for "<<a<<" "<<d<<" "<<n<<"\n";
	long long int p1 = n*a;
	long long int p2 = n*(n-1);
	p2 = p2/2;
	return (p1+p2*d);
}

void solve(int n){
	int sq = sqrt(n);
	for(int i = 1; i<=sq; ++i){
		if(n%i==0){
			//cout<<i<<"\n";
			int d = i;
			int a = 1;
			int j = n/i;
			long long int ss = getsum(a,d,j);
			allfun.push_back(ss);
			if(j!=i){
				int d2 = j;
				int a2 = 1;
				long long int ss2 = getsum(a2,d2,i);
				allfun.push_back(ss2);
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	solve(n);
	sort(allfun.begin(),allfun.end());
	for(int i = 0; i<(int)allfun.size();++i){
		printf("%lld ",allfun[i]);
	}
	printf("\n");
	return 0;
}