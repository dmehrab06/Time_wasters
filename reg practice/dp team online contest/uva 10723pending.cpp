#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 2000000005
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
using namespace std;

int dp[41][41];
int num[41][41];

char a[41];
char b[41];

int alen,blen;

void init(){
    FREP(i,0,40)FREP(j,0,40)dp[i][j]=-1;
    FREP(i,0,40)FREP(j,0,40)num[i][j]=0;
}

int solve(int aidx,int bidx){
    if(aidx==0){
        num[aidx][bidx]=1;
        return dp[aidx][bidx]=bidx;
    }
    if(bidx==0){
        num[aidx][bidx]=1;
        return dp[aidx][bidx]=aidx;
    }
    if(dp[aidx][bidx]!=-1){
        return dp[aidx][bidx];
    }
    int ret1,ret2,ret3;
    if(a[aidx-1]==b[bidx-1]){
        ret1=1+solve(aidx-1,bidx-1);
        dp[aidx][bidx]=ret1;
        num[aidx][bidx]=num[aidx-1][bidx-1];
        return dp[aidx][bidx];
    }

    ret2=1+solve(aidx-1,bidx);
    ret3=1+solve(aidx,bidx-1);
    dp[aidx][bidx]=min(ret2,ret3);
    num[aidx][bidx]=0;
    if(dp[aidx][bidx]==ret2)num[aidx][bidx]+=num[aidx-1][bidx];
    if(dp[aidx][bidx]==ret3)num[aidx][bidx]+=num[aidx][bidx-1];
    return dp[aidx][bidx];
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        scanf("%s %s",a,b);
        alen=strlen(a);
        blen=strlen(b);
        init();
        int ans=solve(alen,blen);
        printf("Case %d: %d %d\n",cs++,ans,num[alen][blen]);
    }
    return 0;
}
