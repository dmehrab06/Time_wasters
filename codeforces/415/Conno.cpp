#include<bits/stdc++.h>
using namespace std;
#define maxn 300100
#define mod 1000000007
#define ll long long
int a[maxn];
int n;
ll pw2[maxn],sum2[maxn];
ll pref[maxn];
ll pow_mod(ll a,ll m)
{
    ll ret=1;
    ll tmp=a%mod;
    while(m)
    {
        if(m&1) ret=ret*tmp%mod;
        tmp=tmp*tmp%mod;
        m>>=1;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    pw2[0]=1;
    for(int i=1;i<=n;++i) pw2[i]=pw2[i-1]*2LL%mod;
    sum2[0]=pw2[0];
    for(int i=1;i<=n;++i) sum2[i]=(sum2[i-1]+pw2[i])%mod;
    pref[0]=0;
    for(int i=1;i<=n;++i) pref[i]=(pref[i-1]+a[i]*pw2[i-1])%mod;
    ll ans=0;
    for(int i=1;i<n;++i)
    {
        ll tmp=(pref[n]-pref[i]+mod)%mod;
        tmp=tmp*pow_mod(pw2[i],mod-2)%mod;
        ll tmp2=a[i]*sum2[n-i-1]%mod;
        tmp=(tmp-tmp2+mod)%mod;
        ans=(ans+tmp)%mod;
    }
    cout<<ans<<"\n";
    return 0;
}
