#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MDD 1000000007

using namespace std;

int amazingness(int n){
    vector<int>dig;
    int t=n;
    while(t){
        dig.push_back(t%10);
        t/=10;
    }
    map<int,int>s;
    int l=dig.size();
    int ans = 0;
    for ( int i = 0; i < l; i++ ) {
         int val = 0;
         for ( int j = i; j < l; j++ ) {
            val ^= dig[j];
            // a[j] denotes digit at j-th (0-based indexing) position of n counting
            if (s.find(val)==s.end()) {
                 ans += val;
                 ans%=MDD;
                 s[val]=1;
            }
         }
   }
   return ans;
}

int maskdp[3009];
int maindp[1000006];

void putindp(int n){
    int a[10];
    for(int i=0;i<10;++i)a[i]=0;
    int t=n;
    while(t){
        a[t%10]=1;
        t/=10;
    }
    int val=0;
    int curpow=1;
    for(int i=0;i<10;++i){
        val=val+curpow*a[i];
        curpow*=2;
    }
    maindp[n]=maskdp[val];
}
int main(){

    int mask=0;
    int mx=1<<10;
    for(int i=mask;i<=mx;++i){
        int cur=i;
        int point=0;
        int num=0;
        while(point<=9){
            if(cur%2){
                num=num*10+point;
            }
            cur/=2;
            point++;
        }
        maskdp[i]=amazingness(num);
    }
    //printf("eddur aschi\n");
    maindp[0]=0;
    for(int i=1;i<=1000003;++i){
        putindp(i);
    }
    for(int i=1;i<=1000003;++i){
        printf("dp[%d]=%d;\n",i,maindp[i]);
    }
    for(int i=1;i<=1000003;++i){
        maindp[i]=maindp[i]+maindp[i-1];
        maindp[i]%=MDD;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d %d",&l,&r);
        long long int s=0;
        s=(long long int)maindp[r]-(long long int)maindp[l-1];
        if(s<0)s+=MDD;
        printf("%lld\n",s);
    }
    return 0;
}
