#include <bits/stdc++.h>
using namespace std;

struct edge{
    int v;
    long long int w;
    edge(){
        v=0;
        w=0;
    }
    edge(int a, long long int b){
        v=a;
        w=b;
    }
};

vector<long long int>nodevals;

vector<long long int>subtreesize;

vector< vector <edge> >graph;

int n;

int vis1[100005];
int vis2[100005];

void dfs1(int cur){
    int nwsubtree=1;
    vis1[cur]=1;
    int l=graph[cur].size();
    for(int i=0;i<l;++i){
        int nxt=graph[cur][i].v;
        if(vis1[nxt]==0){
            dfs1(nxt);
            nwsubtree+=subtreesize[nxt];
        }
    }
    subtreesize[cur]=nwsubtree;
}

long long int ans=0;

void dfs2(int cur, long long  int dis, int startflag){
    vis2[cur]=1;
    if(startflag==1){
        int l=graph[cur].size();
        for(int j=0;j<l;++j){
            int nxt=graph[cur][j].v;
            long long int nxtw=graph[cur][j].w;
            if(vis2[nxt]==0){
                if((dis+nxtw)<0)
                    dfs2(nxt,0,1);
                else{
                    dfs2(nxt,dis+nxtw,0);
                }
            }
        }
    }
    else{
        if(dis>nodevals[cur]){
            //cout<<dis<<" "<<cur<<" "<<nodevals[cur]<<"\n";
            ans+=(subtreesize[cur]);
            return;
        }
        else{
            int l=graph[cur].size();
            for(int j=0;j<l;++j){
                int nxt=graph[cur][j].v;
                long long int nxtw=graph[cur][j].w;
                if(vis2[nxt]==0){
                    if((dis+nxtw)<0)
                        dfs2(nxt,0,1);
                    else{
                        dfs2(nxt,dis+nxtw,0);
                    }
                }
            }
        }
    }
}

void addmnval(long long int mn){
    for(int i=1;i<=n;++i){
        nodevals[i]=nodevals[i]+mn;
    }
    for(int i=1;i<=n;++i){
        int curdegree=graph[i].size();
        for(int j=0;j<curdegree;++j){
            edge nw=graph[i][j];
            nw.w+=mn;
            graph[i][j]=nw;
        }
    }
}

int main(){
    cin>>n;
    vector<edge>line;
    for(int i=1;i<=n+2;++i){
        graph.push_back(line);
    }
    nodevals.push_back(0);
    subtreesize.push_back(0);
    for(int i=1;i<=n;++i){
        long long int a;
        cin>>a;
        nodevals.push_back(a);
        subtreesize.push_back(0);
        vis1[i]=0;
        vis2[i]=0;
    }
    long long int mn=1000000007;
    for(int i=1;i<=(n-1);++i){
        int v; long long int w;
        cin>>v>>w;
        edge a(v,w);
        edge b(i+1,w);
        graph[i+1].push_back(a);
        graph[v].push_back(b);
        if(w<mn){
            mn=w;
        }
    }
    //if(mn<0){
      //  addmnval(mn);
    //}
    //cout<<mn<<"\n";
    dfs1(1);
   /* for(int i=1;i<=n;++i){
        cout<<subtreesize[i]<<"\n";
    }*/
    dfs2(1,0,1);
    cout<<ans<<"\n";
}
