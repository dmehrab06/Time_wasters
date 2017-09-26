/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

//vector< MII > dp;

int dp[30002][1111];

int diam[30005];


void init(){
	memset(dp,-1,sizeof(dp));
}

int mxx;

int solve(int cur, int jmp){
	if(cur>mxx)return 0;
	if(dp[cur][jmp]!=-1) return dp[cur][jmp];
	//int jmp=(cur-prev);
	int ret1=diam[cur],ret2=diam[cur],ret3=diam[cur];
	if(jmp>1){
		ret1+=solve(cur+jmp-1,jmp-1);
	}
	ret2+=solve(cur+jmp,jmp);
	ret3+=solve(cur+jmp+1,jmp+1);
	dp[cur][jmp]=max(ret1,max(ret2,ret3));
	return dp[cur][jmp];
}

int dfs(int cur, int prev){
	if(cur>mxx)return 0;
	int jmp=(cur-prev);
	int mxx=-1;
	FREP(i,(jmp-1),(jmp+1)){
		if(i==0)continue;
		int ret=diam[cur]+dfs(cur+i,cur);
		mxx=max(ret,mxx);
	}
	return mxx;
}

int main(){
	int n,d;
	scanf("%d %d",&n,&d);
	FREP(i,1,n){
		int a;
		scanf("%d",&a);
		diam[a]++;
		mxx=a;
	}
	int ans;
	if(d<=1000){
		init();
		ans=solve(d,d);
	}
	else{
		ans=dfs(d,0);
	}
	printf("%d\n",ans);
}