#include <bits/stdc++.h>
#define MDD 1000000007

using namespace std;

long long int modpow(long long int b, long long int x,long long int MD)
{
    if(x==0){
        return 1;
    }
    if(x==1){
        return b;
    }
    long long int hf=modpow(b,x/2,MD);
    if(x%2==0){
        return (hf*hf)%MD;
    }
    else{
        return (((hf*hf)%MD)*b)%MD;
    }
}
long long int findMMI(long long int n,long long int M)
{
    return modpow(n,M-2,M);
}

long long int fact[100007];

int main(){
    fact[0]=1;
    for(int i=1;i<=100005;++i){
        fact[i]=fact[i-1]*i;
        fact[i]=fact[i]%MDD;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        long long int N,K;
        scanf("%lld %lld",&N,&K);
        int a;
        long long int zeroc=0;
        int n=(int)N;
        for(int i=1;i<=n;++i){
            scanf("%d",&a);
            if(a==0){
                zeroc++;
            }
            //N=N-zeroc;

        }
        if(zeroc>0)N=N-zeroc+1;
        long long int realans=0;
        for(long long int p=0;p<=N && p<=K;++p){
            if(p%2==K%2){
                long long int lob=fact[N];
                long long int hor1=fact[p];
                long long int hor2=fact[N-p];
                long long int hor=(hor1*hor2)%MDD;
                long long int ans=(lob*(findMMI(hor,MDD)))%MDD;
                realans=realans+ans;
                if(realans>=MDD){
                    realans-=MDD;
                }
            }
        }
        printf("%lld\n",realans);

    }
    return 0;
}
