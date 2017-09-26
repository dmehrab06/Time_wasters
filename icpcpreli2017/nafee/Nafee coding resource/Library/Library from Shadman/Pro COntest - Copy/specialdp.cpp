#include <bits/stdc++.h>
using namespace std;



int dis[1000002];
vector<int>v[1000002];
queue <int>q;
bool vis[1000002];
int x[1000002];


int main()
{
    int a,b,c,d,e,f,i,j;
    cin>>a;
    for(i=1;i<=a;i++)
        {
            scanf("%d",&x[i]);
            v[i].push_back(x[i]);
        }
        for(i=1;i<a;i++)
        {
            v[i].push_back(i+1);
            v[i+1].push_back(i);
        }
    q.push(1);
    while(!q.empty())
    {

        b=q.front();
        vis[b]=true;
        q.pop();
        e=v[b].size();
        for(i=0;i<e;i++)
        {
            f=v[b][i];

            if(!vis[f])
            {   if(dis[f]==0)
                 {
                     dis[f]=dis[b]+1;
                     q.push(f);
                 }
                else
                 dis[f]=min(dis[f],dis[b]+1);



            }
        }
    }
    for(i=1;i<=a;i++)
        printf("%d ",dis[i]);
    return 0;
}
