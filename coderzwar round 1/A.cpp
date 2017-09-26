#include <bits/stdc++.h>


using namespace std;
int dp[91][91];
int func(int a,int b){
   if( a == 0 && b == 0)
      return dp[a][b]=0;
    if(dp[a][b]!=-1)return dp[a][b];
   if (a == 0)
      return dp[a][b]=1 + func(a,b-1);
   if (b == 0)
      return dp[a][b]=1 + func(a-1,b);
    if (a > b)
        return dp[a][b]=1 + func(func(a-b,b),b-1);
    else
        return dp[a][b]=1 + func(a-1,func(b-a,a));
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long int a,b;
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",a+b);
    }
    return 0;
}
