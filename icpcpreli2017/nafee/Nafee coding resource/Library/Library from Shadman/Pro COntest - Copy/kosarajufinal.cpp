/*******    kosaraju final by Shadman ****/
#include <bits/stdc++.h>
using namespace std;
vector<int>v[50001],v1[50001],v2;
stack<int>s;
map<int,int>m,m1;
bool vis[50001];
int mf[50001],maf[50001];
void dfs2(int a)
{
    vis[a]=true;
    int b=v1[a].size();
    for(int i=0;i<b;i++)
    {
        int d=v1[a][i];
        if(!vis[d])
        {
           dfs2(d);
        }
    }
    v2.push_back(a);
}
void dfs(int a)
{
    vis[a]=true;
    int b=v[a].size();
    for(int i=0;i<b;i++)
    {
        int d=v[a][i];
        if(!vis[d])
        {
           dfs(d);
        }
    }
    s.push(a);
}
int dfs1(int a)
{
    vis[a]=true;
      int c=maf[a];
    int b=v[a].size();
    for(int i=0;i<b;i++)
    {
        int d=v[a][i];
        if(!vis[d])
        {
            c=c+dfs1(d);
        }
    }
    return c;
}
int dfs3(int a)
{
    vis[a]=true;
      int c=maf[a];
    int b=v1[a].size();
    for(int i=0;i<b;i++)
    {
        int d=v1[a][i];
        if(!vis[d])
        {
            c=c+dfs3(d);
        }
    }
    return c;
}
void dfs_reverse(int a,int p)
{
    mf[a]=p;
    maf[p]++;
    vis[a]=true;
    int b=v1[a].size();
    for(int i=0;i<b;i++)
    {
        int d=v1[a][i];
        if(!vis[d])
        {
            dfs_reverse(d,p);
        }
    }
}
int main()
{
    int a,b,c,d,e,i,j,k,p,q,x,y,T;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {   v2.clear();
        p=0;
        q=0;
      scanf("%d",&a);
      for(j=0;j<=50000;j++)
      {
          v[j].clear();
          v1[j].clear();
          mf[j]=-1;
          maf[j]=0;
      }
      memset(vis,false,sizeof(vis));
      m.clear();
      m1.clear();
    for(j=1;j<=a;j++)
    {
       scanf("%d %d",&c,&d);
        v[c].push_back(d);

    }
    for(j=1;j<=a;j++)
    {
        if(!vis[j])
            dfs(j);
    }
     memset(vis,false,sizeof(vis));
    for(j=1;j<=a;j++)
    {
        c=v[j].size();
        for(k=0;k<c;k++)
        {
            d=v[j][k];

            v1[d].push_back(j);
        }
    }
    while(!s.empty())
    {
        c=s.top();
        s.pop();
        if(!vis[c])
        {
            dfs_reverse(c,p);
            p++;
        }
    }
    x=-1;
    q=-1;
    for(j=0;j<=50000;j++)
        v1[j].clear();
    for(j=1;j<=a;j++)
    {
        c=v[j].size();
        for(k=0;k<c;k++)
        {   e=mf[j];

            d=v[j][k];
            d=mf[d];
            if(d!=e)
              v1[e].push_back(d);
        }
    }
    d=0;
    e=0;
    if(p==1)
    {
        cout<<"Case "<<i<<": "<<1<<endl;
    }
else
{
   memset(vis,false,sizeof(vis));
    for(j=0;j<p;j++)
    {
        if(!vis[j])
            dfs2(j);
    }
    memset(vis,false,sizeof(vis));
    for(j=0;j<=50000;j++)
        v[j].clear();
    for(j=1;j<=a;j++)
     {
         if(v[mf[j]].size()==0)
         {
             v[mf[j]].push_back(j);
         }
     }
    for(j=p-1;j>=0;j--)
    {   memset(vis,false,sizeof(vis));
        if(!vis[v2[j]])
        {c=dfs3(v2[j]);
        if(c>x)
        {
            x=c;
            q=v[v2[j]].front();

        }
        else if(c==x && v[v2[j]].front()<q)
        {
            x=c;
            q=v[v2[j]].front();
        }
    }
    }
    cout<<"Case "<<i<<": "<<q<<endl;
    }
}
    return 0;

}


