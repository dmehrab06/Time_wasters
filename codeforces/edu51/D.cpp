#include <bits/stdc++.h>
#define MDD 998244353
using namespace std;

//0 = empty
//1 = WW
//2 = WB
//3 = BW
//4 = BB

int getcomp(int prev, int next){
	if(prev==0){
		if(next==1 || next==4)return 1;
		else return 2;
		
	}
	else if(prev==1 || prev==4){
		if(next==prev)	return 0;
		
		else return 1;
		
	}
	else{
		if((next+prev)==5)return 2;
		else return 0;
	}
}

int dp[6][1003][2003];

int solve(int state, int col, int comp, int n, int k){
	if(comp>k)return 0;
	if(col>n){
		if(comp==k)return 1;
		else return 0;
	}
	if(dp[state][col][comp]!=-1)return dp[state][col][comp];

	int ret = 0;
	for(int i = 1; i<=4; ++i){
		int inc = getcomp(state,i);
		ret = ret+solve(i,col+1,comp+inc,n,k);
		if(ret>=MDD){
			ret-=MDD;
		}
	}
	return dp[state][col][comp] = ret;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n,k;
	scanf("%d %d",&n,&k);
	printf("%d\n",solve(0,1,0,n,k));
	return 0;
}