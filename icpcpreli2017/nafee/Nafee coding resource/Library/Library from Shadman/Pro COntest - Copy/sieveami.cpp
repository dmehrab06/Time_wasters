#include <bits/stdc++.h>
using namespace std;
bool vis[10000001];
int cal[10000003];
int tot[10000001];
int main()
{
    int a,b,c,d,e,i,j,p,q,sum;
    int x[1000002];
    cin>>a>>b;
    for(i=1;i<=a;i++)
    {
        scanf("%d",&x[i]);
        tot[x[i]]++;
    }
    for(i=2;i<=10000000;i++)
    {
        sum=0;
        if(vis[i]!=1)
        {
            for(j=2*i;j<=10000000;j=j+i)
            {
                sum=sum+tot[j];
                vis[j]=1;

            }
        }
        cal[i]=cal[i-1]+sum;

    }
    for(i=1;i<=b;i++)
    {
        scanf("%d",&c,&d);
        if(c>10000000)c=10000001;
        if(d>10000000)d=100000001;
        printf("%d\n",cal[d]-cal[c]);

    }
    return 0;
}
