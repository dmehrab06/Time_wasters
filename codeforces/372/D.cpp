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

// Number of vertices in the graph
int V;
int EER;
LLI dist[1005];
LLI graph[1005][1005];

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(bool sptSet[])
{
   // Initialize min value
   LLI min = MXX;
   int min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

// A utility function to print the constructed distance array
int SINK;
LLI findis;
void printSolution(int n)
{
   //printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      if(i==SINK){
        findis=dist[i];
        break;
      }
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation

void dijkstra(int src)
{
          // The output array.  dist[i] will hold the shortest
                      // distance from src to i

     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = MXX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)

         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     // print the constructed distance array
     printSolution(V);
}

// driver program to test above function

struct edg{
    int u,v;
    LLI w;
    edg(int _u=0, int _v=0, LLI _w=0){
        u=_u;
        v=_v;
        w=_w;
    }
};

LLI edges[1005][1005];

int visited[1005];

vector<edg>dfsedges;

int possible=1;

vector<VI>adjlist;
int did=0;
void dfs(int cur, int par, LLI ww, int sink, LLI L, int deep){
    if(did>=EER)return;
    if(cur==sink){
        int sz=dfsedges.size();
        LLI cost=0;
        int erased=0;
        for(int i=0;i<sz;++i){
            if(dfsedges[i].w==0){
                erased+=1;
            }
            cost+=dfsedges[i].w;
        }
        if(erased==0 && cost<L){
            possible=0;
        }
        else{
            if(erased>0){
                did+=erased;
                if((cost+erased)>=L){
                    //taile sob gulay 1 1 kore dibo
                    for(int i=0;i<sz;++i){
                        if(dfsedges[i].w==0){
                            dfsedges[i].w=1;
                        }
                    }
                }
                else{
                    LLI ok=cost+erased-1;
                    LLI fin=L-ok;
                    for(int i=(sz-1);i>=0;--i){
                        if(dfsedges[i].w==0){
                            dfsedges[i].w=fin;
                            break;
                        }
                    }
                    for(int i=(sz-1);i>=0;--i){
                        if(dfsedges[i].w==0){
                            dfsedges[i].w=1;
                            break;
                        }
                    }
                }
            }
        }
        return;
    }
    visited[cur]=1;
    int d=adjlist[cur].size();
    for(int k=0;k<d;++k){
        int i=adjlist[cur][k];

            if(!visited[i]){
                dfsedges.PB(edg(cur,i,edges[cur][i]));
                deep++;
                dfs(i,cur,ww+edges[cur][i],sink,L,deep);
                edg last=dfsedges[deep-1];
                deep--;
                dfsedges.pop_back();
                edges[last.u][last.v]=last.w;
                edges[last.v][last.u]=last.w;
            }

    }
    visited[cur]=0;
    return;
}

int inpu[100005];
int inpv[100005];
int main()
{
   /* Let us create the example graph discussed above */
   int M;
   LLI L;
   int src,dest;
   cin>>V>>M>>L>>src>>dest;
   SINK=dest;
   VI line;
   FREP(i,1,V+3)adjlist.PB(line);
   for(int i=0;i<=V+1;++i){
    for(int j=0;j<=V+1;++j){
        edges[i][j]=-1;
    }
   }
   EER=0;
   FREP(i,1,M){
        int u,v;
        LLI w;
        cin>>u>>v>>w;
        if(w==0){
            EER++;
        }
        inpu[i]=u;
        inpv[i]=v;
        edges[u][v]=w;
        edges[v][u]=w;
        adjlist[u].PB(v);
        adjlist[v].PB(u);
   }
   dfs(src,src,0,dest,L,0);
   if(!possible){
    printf("NO\n");
    return 0;
   }
    for(int i=0;i<=V+1;++i){
    for(int j=0;j<=V+1;++j){
        if(edges[i][j]==0)edges[i][j]=1;;
    }
   }
    for(int i=0;i<=V+1;++i){
    for(int j=0;j<=V+1;++j){
        if(edges[i][j]==-1)graph[i][j]=0;
        else{
            graph[i][j]=edges[i][j];
        }
    }
   }
    dijkstra(src);
    if(findis!=L){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        FREP(i,1,M){
            cout<<inpu[i]<<" "<<inpv[i]<<" "<<graph[inpu[i]][inpv[i]]<<"\n";
        }
    }
    return 0;
}
