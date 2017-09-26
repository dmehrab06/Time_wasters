#include <bits/stdc++.h>
using namespace std;
vector<int>v[100001],v1;
stack<int>s;
map<int,int>m,m1;
bool vis[100001];
void dfs1(int a)
{
    vis[a]=true;
    int b=v[a].size();


    for(int i=0;i<b;i++)
    {
        int d=v[a][i];
        if(!vis[d])
            dfs1(d);

    }
    v1.push_back(a);
}
void dfs(int a)
{
    vis[a]=true;


    int b=v[a].size();

    for(int i=0;i<b;i++)
    {
        int d=v[a][i];
        if(!vis[d])
            {   m[a]--;
                m1[d]--;
                dfs(d);
            }
    }
}
int main()
{
    int a,b,c,d,e,i,j,k,p=1000002,q;
    scanf("%d %d",&a,&b);
    for(i=1;i<=b;i++)
    {
        scanf("%d %d",&c,&d);
        v[c].push_back(d);
        v[d].push_back(c);
        m[c]++;
        m[d]++;
        m1[c]++;
        m1[d]++;


    }
    for(i=1;i<=a;i++)
    {
        if(!vis[i])
            dfs1(i);



    }
    e=v1.size();
    memset(vis,false,sizeof(vis));
    for(i=e-1;i>=0;i--)
        {
            if(!vis[v1[i]])
            {
                dfs(v1[i]);
            }

        }
        q=0;

    for(i=1;i<=a;i++)
    {
        if(m[i]==0)
        {

            e=v[i].size();
            for(j=0;j<e;j++)
            {
                d=v[i][j];
                if(m[d]==1 && d>i)
                {
                    m[i]++;
                    m[d]--;
                    k=0;
                    break;
                }
                else if(m[d]>1)
                {
                    m[i]++;
                    m[d]--;
                    k=0;
                    break;
                }
            }
        }

    }
    for(i=1;i<=a;i++)
       if(m[i]==0)q++;
    cout<<q<<endl;
    return 0;
}




