#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;




/*--------finding inverse modulo 10^9+7------*/



int res[104][104];
int maxflow, flow, source, sink;
vector<int>bfsspantree(104,-1);
void augment(int v, int minedge){
    if(v==source){
        flow=minedge;
        return;
    }
    else{
        if(bfsspantree[v]!= -1){
            augment(bfsspantree[v],min(minedge,res[bfsspantree[v]][v]));
            res[bfsspantree[v]][v]-=flow;
            res[v][bfsspantree[v]]+=flow;
        }
    }
}
bool vis[105];
int main(){
    //ios_base::sync_with_stdio(false);
    int cs=1;
    while(1){
    vector< vector <int> >edges;
    int n,m;
    scanf("%d",&n);
    if(n==0)break;
    vector<int>line;
    for(int i=0;i<=n+2;++i){
        edges.push_back(line);
        edges[i].push_back(0);
    }
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            res[i][j]=0;
            res[j][i]=0;
        }
    }
    for(int i=0;i<=n+1;++i){
        bfsspantree[i]=-1;
    }
    scanf("%d %d %d",&source,&sink,&m);
    for(int i=1;i<=m;++i){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        res[u][v]+=w;
        res[v][u]=res[u][v];
        edges[u][0]++;
        edges[u].push_back(v);
        edges[v][0]++;
        edges[v].push_back(u);
    }

    maxflow=0;
    while(1){

        flow=0;

        for(int i=0;i<=105;++i){
            vis[i]=false;
            bfsspantree[i]=-1;
        }
        //queue<int> boka;

        //boka.push(source);

        vis[source]=true;
        queue<int>boka;
        //printf("queue:D\n");
        boka.push(source);
        while(!boka.empty()){
            int u=boka.front();
            boka.pop();
            if(u==sink){
                break;
            }
            int l=edges[u][0];
            for(int i=1;i<=l;++i){
                int v=edges[u][i];
                if(res[u][v]>0 && !vis[v]){
                    boka.push(v);
                    bfsspantree[v]=u;
                    vis[v]=true;
                }
            }

        }
        augment(sink,1000000009);
        if(flow==0)break;
        maxflow+=flow;
        //delete[] vis;
    }
    printf("Network %d\nThe bandwidth is %d.\n\n",cs++,maxflow);
    //edges.clear();
    }
    return 0;
}
