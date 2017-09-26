#include <bits/stdc++.h>
using namespace std;
bool vis[2201];
long long int sum[110],a,b,c,mf=999999999,ans,ans1,tmp,opt[110][2201],pre[101],cnt[110][110];
vector<pair<long long int, long long int> >v[110];

pair<long long int,long long int>pr;

void djikstra(long long int x)
{
    set<pair<long long int,long long int> >s;
    set<pair<long long int,long long int> > :: iterator it;
    bool vis1[110];
    pair<long long int, long long int> pr1,pr2,pr3;
    long long int dis[110],i,p,q,j,e,f;
    memset(pre,-1,sizeof(pre));
    for(i=0;i<=a;i++){
            {
                dis[i]=mf;
                vis1[i]=false;
            }
    }


    dis[x]=0;
    pr1.first=dis[x];
    pr1.second=x;
    s.insert(pr1);

    while(!s.size()==0)
    {
          it=s.begin();
          pr1= *it;
          s.erase(*it);
          q=pr1.second;
          if(vis1[q])continue;
          vis1[q]=true;
          e=v[q].size();
          for(j=0;j<e;j++)
          {
              pr2=v[q][j];
              //cout<<q<<" "<<pr2.first<<endl;
              if(dis[pr2.first]>dis[pr1.second]+pr2.second)
              {    pr3.first=dis[pr2.first];
                   pr3.second=pr2.first;
                   pre[pr2.first]=cnt[pr1.second][pr2.first];
                   s.erase(pr3);
                  dis[pr2.first]=dis[pr1.second]+pr2.second;
                  pr3.first=dis[pr2.first];
                  s.insert(pr3);



              }
          }

    }
    for(i=1;i<=a;i++)
    {   if(i==x)continue;
        if(dis[i]>=mf)
           dis[i]=c;
        else
           opt[x][pre[i]]=opt[x][pre[i]^1]=1;
        ans=ans+dis[i];
        sum[x]+=dis[i];
    }
    //cout<<x<<" "<<sum[x]<<endl;

}
void djikstra1(long long int x)
{
    set<pair<long long int,long long int> >s;
    set<pair<long long int,long long int> > :: iterator it;
    bool vis1[110];
    pair<long long int, long long int> pr1,pr2,pr3;
    long long int dis[110],i,p,q,j,e,f,cnt1=0;
    for(i=0;i<=a;i++){
            {
                dis[i]=mf;
                vis1[i]=false;
            }
    }


    dis[x]=0;
    pr1.first=dis[x];
    pr1.second=x;
    s.insert(pr1);

    while(!s.size()==0)
    {
          it=s.begin();
          pr1= *it;
          s.erase(*it);
          q=pr1.second;
          if(vis1[q])continue;
          vis1[q]=true;
          e=v[q].size();
          for(j=0;j<e;j++)
          {
              pr2=v[q][j];
              if(vis[cnt[q][pr2.first]]==1)continue;
              //cout<<q<<" "<<pr2.first<<endl;
              if(dis[pr2.first]>dis[pr1.second]+pr2.second)
              {    pr3.first=dis[pr2.first];
                   pr3.second=pr2.first;
                   s.erase(pr3);
                  dis[pr2.first]=dis[pr1.second]+pr2.second;
                  pr3.first=dis[pr2.first];
                  s.insert(pr3);



              }
          }

    }
    for(i=1;i<=a;i++)
    {   if(i==x)continue;
        //if(x==4)
            //cout<<dis[i]<<" ";
        if(dis[i]>=mf)
           dis[i]=c;
        cnt1=cnt1+dis[i];
        //sum[x]+=dis[i];
    }
    //if(x==4)
    //cout<<cnt1<<" ";
    tmp=tmp-sum[x]+cnt1;
    //cout<<x<<" "<<sum[x]<<endl;

}

int main()
{

    long long int d,e,f,i,j,k,p,q,T,r;
    while(scanf("%lld %lld %lld",&a,&b,&c)!=EOF)
    {
      ans=0;
      ans1=0;
      memset(sum,0,sizeof(sum));
      memset(cnt,0,sizeof(cnt));
      memset(opt,0,sizeof(opt));


        for(i=0;i<=110;i++)
          {
              v[i].clear();
          }
          r=0;
          for(i=1;i<=b;i++)
          {
              scanf("%lld %lld %lld",&d,&e,&f);
              pr.first=e;
              pr.second=f;

              cnt[d][e]=r;

              r++;
              v[d].push_back(pr);
              pr.first=d;
              v[e].push_back(pr);

              cnt[e][d]=r;

              r++;
          }
          for(i=1;i<=a;i++)
          {
             djikstra(i);
          }
          printf("%lld ",ans);
          tmp=ans;
          ans1=ans;
          for(i=0;i<r;i=i+2)
          {    memset(vis,false,sizeof(vis));
              vis[i]=vis[i^1]=1;
              tmp=ans;
              for(j=1;j<=a;j++)
              {
                  if(opt[j][i]==1)
                    djikstra1(j);
              }
              vis[i]=vis[i^1]=0;

              ans1=max(ans1,tmp);

          }
          printf("%lld\n",ans1);

    }
    return 0;

}
