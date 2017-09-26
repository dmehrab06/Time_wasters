#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,c,d,e,f,i,j,k,p,q,ans=1000000000;
    char x[20][20];
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {   ans=1000000000;
        if(a==0)break;
        if(b==0)break;
        for(i=1;i<=a;i++)
            scanf("%s",x[i]);

        d=(1<<b)-1;

        e=0;
        for(i=d;i>=0;i--)
        {   p=__builtin_popcount(i);
            f=(i^(i>>1)^(i<<1))&d;
            //cout<<p<<endl;

            e=i;
            for(j=0;j<b;j++)
                if(x[1][j]=='X')f=f^(1<<j);

            for(j=2;j<=a;j++)
            {
                q=f;
                f=(f^(f>>1)^(f<<1)^e)&d;
                e=q;
                p=p+__builtin_popcount(q);
                for(k=0;k<b;k++)
                {
                    if(x[j][k]=='X')f=f^(1<<k);
                }
            }
            //cout<<f<<" ";
            if(f==0)
                ans=min(ans,p);
        }
        if(ans>=1000000000)
           printf("Damaged billboard.\n");
        else
            printf("You have to tap %d tiles.\n",ans);

    }
    return 0;

}
