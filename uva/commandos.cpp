#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;


int edges[105][105];
int visited[105];
int dis[105];
void bfs(int src, int total){
    for(int i=0;i<total;++i){
        visited[i]=0;
        dis[i]=0;
    }
    queue<int>nodes;
    nodes.push(src);
    visited[src]=1;
    dis[src]=0;
    while(!nodes.empty()){
        int cur=nodes.front();
        nodes.pop();
        int l=edges[cur][0];
        for(int i=1;i<=l;++i){
            int nw=edges[cur][i];
            if(!visited[nw]){
                visited[nw]=1;
                dis[nw]=dis[cur]+1;
                nodes.push(nw);
            }
        }
    }
}
int visited2[105];
int dis2[105];
void bfs2(int src, int total){
    for(int i=0;i<total;++i){
        visited2[i]=0;
        dis2[i]=0;
    }
    queue<int>nodes;
    nodes.push(src);
    visited2[src]=1;
    dis2[src]=0;
    while(!nodes.empty()){
        int cur=nodes.front();
        nodes.pop();
        int l=edges[cur][0];
        for(int i=1;i<=l;++i){
            int nw=edges[cur][i];
            if(!visited2[nw]){
                visited2[nw]=1;
                dis2[nw]=dis2[cur]+1;
                nodes.push(nw);
            }
        }
    }
}



int main(){
    //ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,r;
        scanf("%d %d",&n,&r);
        for(int i=0;i<n;++i){
            edges[i][0]=0;
        }
        for(int i=1;i<=r;++i){
            int u,v;
            scanf("%d %d",&u,&v);
            int lu=edges[u][0];
            edges[u][lu+1]=v;
            edges[u][0]++;
            int lv=edges[v][0];
            edges[v][lv+1]=u;
            edges[v][0]++;
        }
        int src,dest;
        scanf("%d %d",&src,&dest);
        bfs(src,n);


        bfs2(dest,n);
        int mxdis=-1;
        for(int i=0;i<n;++i){
            if((dis[i]+dis2[i])>mxdis){
                mxdis=dis[i]+dis2[i];
            }
        }
        printf("Case %d: %d\n",cs++,mxdis);

    }
    return 0;
}
