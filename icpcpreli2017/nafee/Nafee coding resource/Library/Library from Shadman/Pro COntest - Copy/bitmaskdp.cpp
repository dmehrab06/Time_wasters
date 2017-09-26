/**   Bitmask DP by Shadman ***/
using namespace std;
#include "cstring"
#include "cstdio"
#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "cctype"
#include "set"
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int dp[20][1<<17];
int biye[20][20],a;
int bit(int i,int mask)
{
    if(dp[i][mask]!=-1)return dp[i][mask];
    if(i==a)return 0;
    int mx=-1;

    for(int j=0;j<a;j++)
    {
        if(check(mask,j)==0)
        {   int pr=biye[i][j];

            mx=max(mx,pr+bit(i+1,Set(mask,j)));

        }
    }
    return dp[i][mask]=mx;
}
int main()
{
    int b,c,p,q,r,x,y,z,i,j,k,d;

    cin>>b;
    for(i=1;i<=b;i++)
    {
        scanf("%d",&a);
        for(j=0;j<20;j++)
            memset(dp[j],-1,sizeof(dp[j]));
        for(j=0;j<a;j++)
        {
            for(k=0;k<a;k++)
                scanf("%d",&biye[j][k]);
        }



      printf("Case %d: %d",i,bit(0,0));
      cout<<endl;
    }
    return 0;
}
