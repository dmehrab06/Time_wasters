#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

long long int arr[100006];

long long int dp[100006][3];

long long int solve(int idx, int prevtaken){
    if(idx==0){
        return 0;
    }
    if(dp[idx][prevtaken]!=-1){
        return dp[idx][prevtaken];
    }
    long long int ret1=0,ret2=0;
    if(prevtaken==0){
        ret1=arr[idx]+solve(idx-1,1);
    }
    ret2=solve(idx-1,0);
    dp[idx][prevtaken]=max(ret1,ret2);
    return dp[idx][prevtaken];
}

void init(){
    for(int i=0;i<100006;++i){
        for(int j=0;j<3;++j){
            dp[i][j]=-1;
        }
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        init();
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%lld",&arr[i]);
        }
        long long int ans1=solve(n,0);
        //long long int ans2=solve(n,1);
        printf("%lld\n",ans1);
    }
    return 0;
}
