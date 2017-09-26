#define MAXINT 200000009
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
 
int minimum(int a,int b){
    if(a<b){
 
        return a;
    }
    else{
 
        return b;
    }
}
typedef struct xx{
    int src;
    int dest;
    int wt;
    xx(int u,int v, int w){
        src=u;
        dest=v;
        wt=w;
    }
}edge;
int dis[502];
vector<edge>alledge;
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    int cs=1;
    scanf("%d",&t);
    while(t--){
           int n,m;
           scanf("%d %d",&n,&m);
           for(int i=0;i<n;++i){
                   dis[i]=MAXINT;
           }
 
           for(int i=1;i<=m;++i){
                  int u,v,w;
                  scanf("%d %d %d",&u,&v,&w);
                  edge a(u,v,w);
                  edge b(v,u,w);
                  alledge.push_back(a);
                  alledge.push_back(b);
 
           }
           int myhouse;
           scanf("%d",&myhouse);
           dis[myhouse]=0;
            int l=alledge.size();
            for(int i=1;i<=n;++i){
                int changed=0;
                for(int j=0;j<l;++j){
                    edge nowedge=alledge[j];
                    int u=nowedge.src;
                    int v=nowedge.dest;
                    int w=nowedge.wt;
                    int mx=max(dis[u],w);
                    if(mx<dis[v]){
                        dis[v]=mx;
                        changed=1;
                    }
                    mx=max(dis[v],w);
                    if(mx<dis[u]){
                        dis[u]=mx;
                        changed=1;
                    }
                }
                if(changed==0)break;
            }
 
 
 
           printf("Case %d:\n",cs);
           for(int i=0;i<n;++i){
                   if(dis[i]>=MAXINT){
                                               printf("Impossible\n");
                   }
                   else{
                        printf("%d\n",dis[i]);
 
                   }
           }
           cs++;
           alledge.clear();
    }
    return 0;
 
 
}
