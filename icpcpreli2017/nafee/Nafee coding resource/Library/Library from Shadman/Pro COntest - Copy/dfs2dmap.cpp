#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include<algorithm>
#include<math.h>
#include<utility>
#include<map>
#include<set>
#include <string.h>
#include <iomanip>

using namespace std;
#define ll long long int
#define inf 10000000

#define mod 1000000007

ll val[1000000];
map <ll, ll> m[1000000];
vector < ll > v[1000000];
ll len[1000000];
ll vis[1000000];

ll ans;

void dfs(ll a,ll lenn)
{
    ll p,i,j,sum,pl;

     vis[a]=1;

     for(i=0;i<len[a];i++)
     {
         p=v[a][i];

         if(vis[p]==1)
            continue;

         sum=lenn+ m[a][p];
         pl=m[a][p];
         sum=max(pl,sum);
         if(sum>val[p])
         {
             //dfs(p,lenn);

         }
         else
            3
            {
                ans++;
                //cout<<p<<endl;
             dfs(p,sum);

         }



     }





}

int main()
{
   ll n,i,j,x,y,sum,p,r,q;
   cin>>n;
   for(i=1;i<=n;i++)
    scanf("%I64d",&val[i]);
   ans=0;

   for(i=1;i<=n-1;i++)
   {
       scanf("%I64d%I64d",&x,&sum);
       y=i+1;

       v[y].push_back(x);
       v[x].push_back(y);
       len[x]++;
       len[y]++;
       m[x][y]=sum;
       m[y][x]=sum;
    }
    ans++;
   dfs(1,0);


cout<<n-ans;

}
