#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000
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
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;

int dp[30002][30002];

int solve(int ss, int ee){
    if(ss==ee || ss>ee){
        return 0;
    }
    if(dp[ss][ee]!=-1)return dp[ss][ee];
    int ret;
    FREP(i,ss,ee){
        ret=solve(ss,i)+solve(i+1,ee);
        dp[ss][ee]=max(dp[ss][ee],ret);
    }
    return dp[ss][ee];
}

int main(){
    int n;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    int ss=MXX;
    int ee=MNN;
    FREP(i,1,n){
        int s,e;
        scanf("%d %d",&s,&e);
        dp[s][e]=1;
        if(s<ss)ss=s;
        if(e>ee)ee=e;
    }
    int ans=solve(ss,ee);
    printf("%d\n",ans);
    return 0;
}
