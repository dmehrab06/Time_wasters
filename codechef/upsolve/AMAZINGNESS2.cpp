#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MDD 1000000007

using namespace std;
int dp[1000007];

int amazingness(int n){
    int dig[7];
    int t=n;
    int mxdig=0;
    int k=0;
    int l=0;
    int anothernum=0;
    while(t){
        if((t%10)>mxdig)mxdig=t%10;
        dig[k++]=(t%10);
        anothernum=anothernum*10+t%10;
        t/=10;
        l++;
    }
   // if(dp[anothernum]!=-1)return dp[anothernum];
    int mxpos=16;
    /*if(mxdig<8){
        mxpos=8;
    }
    if(mxdig<4)mxpos=4;
    if(mxdig<2)mxpos=2;*/
    int s[16];

    for(int i=0;i<16;++i)s[i]=0;
    s[0]=1;
   // int l=dig.size();
    int ans = 0;
    int found=1;
    for ( int i = 0; i < l && found<mxpos; i++ ) {
         int val = 0;
         for ( int j = i; j < l && found<mxpos; j++ ) {
            val ^= dig[j];
            // a[j] denotes digit at j-th (0-based indexing) position of n counting
            if (s[val]==0){
                 ans += val;
                 ans%=MDD;
                 s[val]=1;
                 found++;
            }
         }
   }
   return ans;
}


int main(){
    for(int i=1;i<=1000000;++i){
        dp[i]=-1;
    }
    dp[0]=0;
    for(int i=1;i<=1000000;++i){
        dp[i]=amazingness(i);
    }
    for(int i=1;i<=1000000;++i){
        dp[i]=dp[i-1]+dp[i];
        dp[i]%=MDD;
    }

    int t;
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d %d",&l,&r);
        long long int s=0;
        s=dp[r]-dp[l-1];
        if(s<0)s+=MDD;
        printf("%lld\n",s);
    }
    return 0;
}
