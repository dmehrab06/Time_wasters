/*-------property of the half blood prince-----*/

//WA

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

LLI dp[5003][5003];

//dp[curpos][prevval];

int N,D;
int Limit;
LLI solve(int curval, int left){
    //if(curval>left)return 1;
    if(left==0)return 1;
    //if(curval==N)return 1;
    //if(curval>left)return 1;
    if(dp[curval][left]!=-1){
        return dp[curval][left];
    }
    LLI ret1=0;
    //int oka=0;
    for(int cur=curval;cur<=Limit;cur++){
        if(left>=cur)ret1+=solve(cur,left-cur);
       // oka++;
    }
    return dp[curval][left]=ret1;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&N,&D);
        LLI ans=0;
        FREP(i,D,(N+2)){
            if(i%D==0){
                if(i<=N){Limit=i+2;ans=ans+solve(i,(N-i));}
            }
        }
        printf("Case #%d: %lld\n",cs++,ans);
    }
    return 0;
}
