#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int cnt = 0;
	while(n>0){
		n/=2;
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}