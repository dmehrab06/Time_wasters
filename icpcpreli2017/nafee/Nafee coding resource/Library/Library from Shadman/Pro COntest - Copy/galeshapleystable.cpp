/*******   galeshapleystable by Shadman ****/
#include <bits/stdc++.h>
using namespace std;
int man[1001][1001],wom[1001][1001],bor[1001],bou[1001],cnt[1001];
queue<int>Q;
int main()
{
    int a,b,c,d,e,i,j,k,p,q,r,T;
    cin>>T;
    for(i=1;i<=T;i++)
    {  while(!Q.empty())Q.pop();
        memset(cnt,0,sizeof(cnt));
        memset(bor,0,sizeof(bor));
        memset(bou,0,sizeof(bou));

        scanf("%d",&a);
        for(j=1;j<=a;j++)
        {
            for(k=1;k<=a;k++)
            {
                scanf("%d",&wom[j][k]);
            }
            cnt[j]=1;
            Q.push(j);
        }
        for(j=1;j<=a;j++)
        {
            for(k=1;k<=a;k++)
            {
                scanf("%d",&b);
                man[j][b]=k;
            }
        }

    while(!Q.empty())
    {
        c=Q.front();
        Q.pop();
        d=wom[c][cnt[c]];
        cnt[c]++;

        if(!bou[d])
        {
            bou[d]=c;
            bor[c]=d;

        }
        else if(man[d][bou[d]]>man[d][c])
        {
            e=bou[d];
            bor[e]=0;
            bou[d]=c;
            bor[c]=d;
            Q.push(e);
        }
        else
            Q.push(c);
    }
    for(int j = 1; j <= a; ++j)
             printf("%d\n",bor[j]);
        if(i<T) putchar('\n');



}


return 0;



}
