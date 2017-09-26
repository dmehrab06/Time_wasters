#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;




/*--------finding inverse modulo 10^9+7------*/

long long int fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
long long int findMMI_fermat(long long int n,long long int M)
{
    return fast_pow(n,M-2,M);
}


/*--------finding inverse modulo 10^9+7------*/


vector< vector <int> >edges;
int res[3004][3004];
int maxflow, flow, source, sink;
vector<int>bfsspantree;
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

void resetresid(int n){
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            res[i][j]=0;
            res[j][i]=0;
        }
    }
    for(int i=1;i<=n;++i){
        int deg=edges[i].size();
        for(int j=0;j<deg;++j){
            int cur=edges[i][j];
            res[i][cur]=1;
        }
    }
}
int main(){
    //ios_base::sync_with_stdio(false);
    int n,m;
    while(scanf("%d %d",&n,&m)==2){
    vector<int>line;
    for(int i=0;i<=n+2;++i){
        edges.push_back(line);
        edges[i].push_back(0);
    }
    /*for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            res[i][j]=0;
            res[j][i]=0;
        }
    }*/
    for(int i=0;i<=n+1;++i){
        bfsspantree.push_back(-1);
    }
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d %d",&u,&v);
        //res[u][v]=w;
        edges[u][0]++;
        edges[u].push_back(v);
        edges[v][0]++;
        edges[v].push_back(u);
    }
    //scanf("%d %d",&source,&sink);
    long long int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=(i+1);j<=n;++j){
            source=i;
            sink=j;
            resetresid(n);
            maxflow=0;
            while(1){
                flow=0;
                bool *vis=new bool[n+2];
                for(int i=0;i<=n;++i){
                    vis[i]=false;
                    bfsspantree[i]=-1;
                }
                queue<int>qq;
                qq.push(source);
                vis[source]=true;
                while(!qq.empty()){
                    int u=qq.front();
                    qq.pop();
                    if(u==sink){
                        break;
                    }
                    int l=edges[u][0];
                    for(int i=1;i<=l;++i){
                        int v=edges[u][i];
                        if(res[u][v]>0 && !vis[v]){
                            qq.push(v);
                            bfsspantree[v]=u;
                            vis[v]=true;
                        }
                    }

                }
                augment(sink,1000000009);
                if(flow==0)break;
                maxflow+=flow;
            }
            ans+=maxflow;
        }
    }

    printf("%lld\n",ans);
    edges.clear();
    }
}
