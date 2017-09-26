#include <bits/stdc++.h>
#define MXX 1000000007
using namespace std;

// REST 0
// CONTEST 1
// GYM 2

int state[105];

int dp[105][4];

int N;

int solve(int i, int did){
        if(i==N)return 0;
        if(dp[i][did]!=-1)return dp[i][did];
        if(state[i]==0){
            return dp[i][did]=1+solve(i+1,0);
        }
        if(state[i]==1){
            int ret1=MXX,ret2=MXX;
            if(did!=1){
                ret1=solve(i+1,1);
            }
            ret2=1+solve(i+1,0);
            //ret3=solve(i+1,1);
            return dp[i][did]=min(ret1,ret2);
        }
        if(state[i]==2){
            int ret1=MXX,ret2=MXX;
            if(did!=2){
                ret1=solve(i+1,2);
            }
            ret2=1+solve(i+1,0);
            //ret3=solve(i+1,1);
            return dp[i][did]=min(ret1,ret2);
        }
        if(state[i]==3){
            int ret1=MXX,ret2=MXX,ret3=MXX;
            if(did!=1){
                ret1=solve(i+1,1);
            }
            if(did!=2){
                ret2=solve(i+1,2);
            }
            ret3=1+solve(i+1,0);
            return dp[i][did]=min(ret1,min(ret2,ret3));
        }
}

void init(){
    for(int i=0;i<105;++i){
        for(int j=0;j<4;++j){
            dp[i][j]=-1;
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&state[i]);
    }
    init();
    int ans=solve(0,0);
    cout<<ans<<"\n";
    return 0;
}
