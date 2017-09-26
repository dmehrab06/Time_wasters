#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int MD=1000000007;
int dp[1005][1005];
int strength[1005];
int N,M,S;
int way(int dog,int stepno){
    if(stepno==0)return dp[dog][stepno];
    if(dp[dog][stepno]!=-1){
        return dp[dog][stepno];
    }
    int res1=0;
    int res2=0;
    int curstrength=strength[stepno];
    int leftdog=dog-curstrength;
    int rightdog=dog+curstrength;
    if(leftdog>=1){
        res1=way(leftdog,stepno-1);
    }
    if(rightdog<=N){
        res2=way(rightdog,stepno-1);
    }
    dp[dog][stepno]=(res1+res2)%MD;
    return dp[dog][stepno];

}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        //int N,M,S;
        scanf("%d %d %d",&N,&M,&S);
        for(int i=0;i<=N+1;++i){
            for(int j=0;j<=M+1;++j){
                if(j==0){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=-1;
                }
            }
        }
        dp[S][0]=1;
        for(int i=1;i<=M;++i){
            scanf("%d",&strength[i]);
        }
        for(int i=1;i<=N;++i){
            int seq=way(i,M);
            printf("%d ",seq);
        }
        printf("\n");
    }
    return 0;
}
