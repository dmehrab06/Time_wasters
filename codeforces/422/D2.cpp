
#include <bits/stdc++.h>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
using namespace std;

int prime[5000004];

int smprime[5000004];

long long int fval[5000004];

long long int calc(int n, int MDD){
    long long int ans = 0;
    long long int per = smprime[n]; long long int tot  = (long long int)n/per;
    long long int cm = ((per*(per-1))/2);
    cm%=MDD; cm = cm*tot; cm%=MDD;
    ans+=cm; ans%=MDD;
    ans+=fval[tot]; ans%=MDD;
    return ans;
}

void init(){
    memset(prime,0,sizeof(prime));
    memset(smprime,-1,sizeof(smprime));
}

void sieve(){
    FREP(i,2,5000003){
        if(prime[i]==0){
            smprime[i]=i;
            for(int j = i+i; j<=5000003; j+=i){
                if(smprime[j]==-1)smprime[j]=i;
                prime[j]=1;
            }
        }
    }
}

int main(){
    int MOD = 1000000007;
    init();
    sieve();
    fval[2]=1;
    FREP(i,3,5000003)fval[i]=calc(i,MOD);

    int t,l,r;
    cin>>t>>l>>r;
    long long int s = 0; long long int pw = 1;
    FREP(i,l,r){
        long long int val1 = pw; long long int val2 = fval[i];
        long long int val  = val1*val2;
        val%=MOD;
        s+=val; s%=MOD;
        pw = pw*t; pw%=MOD;
    }
    cout<<s<<"\n";
    return 0;
}
