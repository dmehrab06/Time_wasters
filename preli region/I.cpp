/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())


using namespace std;

LLI mod;

LLI dp[100003];



long long int modpow(long long int b, long long int x,long long int MD)
{
    if(x==0)
    {
        return 1%MD;
    }
    if(x==1)
    {
        return b%MD;
    }
    long long int hf=modpow(b,x/2,MD);
    if(x%2==0)
    {
        return (hf*hf)%MD;
    }
    else
    {
        return (((hf*hf)%MD)*b)%MD;
    }
}




int main()
{
    //init();
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--)
    {
        int n;
        LLI k;
        scanf("%d %lld %lld",&n,&k,&mod);
        dp[0]=1;
        dp[1]=2;
        FREP(i,2,n)
        {
            dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;

        }
        LLI ans=dp[n];
        // cout<<ans<<"\n";
        /*
        FREP(i,0,10000){
         cout<<dp[i][0]<<" "<<dp[i][1]<<endl ;
        }
        */
        LLI ans2=modpow(k,ans,mod);
        // if(ans2<0) ans2+=mod ;
        printf("Case %d: %lld\n",cs++,ans2);
    }
    return 0;
}
