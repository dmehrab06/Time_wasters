#include <bits/stdc++.h>
#define LLI long long int
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)

using namespace std;

LLI mp(LLI b, LLI x,LLI MD)
{
    if(x==0)
        return 1;
    if(x==1)
        return b;

    LLI hf=mp(b,x/2,MD);
    if(x%2==0){
        return (hf*hf)%MD;
    }
    else{
        return (((hf*hf)%MD)*b)%MD;
    }
}
LLI findMMI(LLI n,LLI M)
{
    return mp(n,M-2,M);
}

LLI MOD=1000000007;

int main(){
    LLI n,k;
    scanf("%lld %lld",&n,&k);
    LLI sub=0;
    if(k>=3){
        LLI a=k-2;
        sub=a*(a+1);
        sub/=2;
    }
    LLI nn=n-sub;
    if(nn<=0){
        printf("0\n");
        return 0;
    }
    int go=k;
    LLI s=1,s2=1;
    while(go--){
        s=s*nn;
        s%=MOD;
        nn--;
    }
    FREP(i,1,k){
        s2=s2*i;
        s2%=MOD;
    }
    LLI ok=findMMI(s2,MOD);
    LLI ans=(s*ok)%MOD;
    printf("%lld\n",ans);

    return 0;
}
