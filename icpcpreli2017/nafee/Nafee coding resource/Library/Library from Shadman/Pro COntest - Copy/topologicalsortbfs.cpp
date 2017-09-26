// topological sort bfs by Shadman


#include <bits/stdc++.h>
using namespace std;
queue <int>Q;
vector<int>v[22];
int indeg[20],arr[20];
void bfs()
{
    int x,y,z,i,j,k,cnt=0;
    while(!Q.empty())
    {
        x=Q.front();

        Q.pop();
        cnt++;
        k=v[x].size();
        for(i=0;i<k;i++)
        {
            y=v[x][i];

            indeg[y]--;
            if(indeg[y]==0)
            {
              Q.push(y);
              arr[y]=cnt;

            }
        }
    }
}
int main()
{
    int a,b,c,d,e,i,j,k,T,p,q;
    char s[110];
    cin>>T;

    for(i=1;i<=T;i++)
        {   scanf("%d",&a);
            scanf("%s",s);

        memset(indeg,0,sizeof(indeg));
        memset(arr,0,sizeof(arr));
        while(!Q.empty())
        {
            Q.pop();
        }
        p=0;
        for(j=0;j<=20;j++)
            v[j].clear();
        for(j=1;j<=a;j++)
        {
            for(k=j;k<=a;k++)
            {
                if(s[p]=='+')
                {
                    v[j-1].push_back(k);
                    indeg[k]++;
                }
                else if(s[p]=='-')
                {
                    v[k].push_back(j-1);
                     indeg[j-1]++;
                }
                p++;
            }
        }
        for(j=0;j<=a;j++)
        {
            if(indeg[j]==0)
            {
                Q.push(j);
            }
        }
        bfs();

        for(j=1;j<=a;j++)
        {
            printf("%d ",arr[j]-arr[j-1]);
        }
        printf("\n");

    }
    return 0;


}
