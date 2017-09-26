#include <iostream>
#include <set>
using namespace std;

int allnum[5000005];
int dp[5000005];
int cum[5000005];
int allprimes[1000005];
int totalprime;

int solve(int idx, int n){
    if(dp[n]!=-1)return dp[n];
    if(allnum[n]==0){
        return dp[n]=1;
    }
    int ii;
    for(ii=idx;ii<=totalprime;++ii){
        if(n%allprimes[ii]==0){
            break;
        }
    }
    return dp[n]=1+solve(ii,n/allprimes[ii]);
}

void sieve(){
    for(int i=0;i<5000005;++i){
        dp[i]=-1;
    }
    dp[1]=0;
    int idx=1;
    for(int i=2;i<5000005;++i){
        if(allnum[i]==0){
            allprimes[idx++]=i;
            for(int j=(i+i);j<5000005;j+=i){
                allnum[j]=1;
            }
        }
    }
    totalprime=idx-1;
    allprimes[0]=1000000007;
    for(int i=5000001;i>=2;--i){
        if(dp[i]==-1){
            solve(0,i);
        }
    }
    cum[0]=0;
    for(int i=1;i<=5000002;++i){
        cum[i]=cum[i-1]+dp[i];
    }
}

int main(){
    int t;
    scanf("%d",&t);
    sieve();
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",cum[a]-cum[b]);
    }
    return 0;
}
