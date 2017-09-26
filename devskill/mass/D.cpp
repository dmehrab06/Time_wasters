
#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

ull mulmod(ull a,ull b,ull c){
    if(a<=1000000000ULL && b<=1000000000ULL){
        ull ret = ((a%c)*(b%c))%c;
        return ret;
    }
    ull ret = 0ULL;
    a=a%c;
    while(b > 0ULL){
        if(b&1ULL) {
            ret = (ret+a)%c;
        }
        a = (a<<1ULL)%c;
        b>>=1ULL;
    }
    return ret%c;
}

int main(){
    ull N,M,K;
    int cs=1;
    while(cin>>N>>M>>K){
        ull ans1=N;
        ull ans2=N-1;
        if(N%2==0){
            ans1/=2;
        }
        else{
            ans2/=2;
        }
        ull ans=mulmod(ans1,ans2,K);
        ans=mulmod(ans,M,K);
        cout<<"Case "<<cs++<<": "<<ans<<"\n";
    }
    return 0;
}
