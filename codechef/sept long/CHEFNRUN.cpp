#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;

// This function returns true if graph G[V][V] is Bipartite, else false
vector < VI > G;
int visited[1003];
int inp[1003][1003];
void init(int V){
    G.clear();
    VI line;
    FREP(i,0,V+2)G.push_back(line);
    FREP(i,0,V+2){
        FREP(j,0,V+2){
            inp[i][j]=0;
        }
    }
    FREP(i,0,V+2){visited[i]=0;inp[i][i]=1;}

}

void makecomgraph(int V){
    FREP(i,1,V){
        FREP(j,(i+1),V){
            if(inp[i][j]==0){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
}

bool isBipartite(int src, int V)
{
    //credit : GFGEEKS
    int color[1003];
    for (int i = 1; i <= V; ++i)
        color[i] = -1;
    color[src] = 1;
    visited[src]=1;

    queue <int> q;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int deg=G[u].size();
        for (int k = 0; k < deg; ++k)
        {
            int v=G[u][k];
            if (color[v] == -1)
            {
                color[v] = 1 - color[u];
                visited[v]=1;
                q.push(v);
            }
            else if (color[v] == color[u])
                return false;
        }
    }
    return true;
}

int main()
{   //prottek component er jonno bipartite call krte hobe
    //so unless everyone visited , keep calling
    int t;
    scanf("%d",&t);
    while(t--){
        int N,M;
        scanf("%d %d",&N,&M);
        init(N);
        FREP(i,1,M){
            int u,v;
            scanf("%d %d",&u,&v);
            inp[u][v]=1;
            inp[v][u]=1;
        }

        makecomgraph(N);
        int can=1;
        for(int i=1;i<=N && can;++i){
            if(!visited[i]){
                if(!isBipartite(i,N)){
                    can=0;
                }
            }
        }
        printf("%s\n",can?"YES":"NO");
    }
    return 0;
}
