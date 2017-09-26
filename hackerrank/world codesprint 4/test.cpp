#include <bits/stdc++.h>

using namespace std;

vector<int>allpos;

int subtreesize[200005];

struct pp{
    int v;
    int w;
    
    pp(){
        v=0;
        w=0;
    }
    pp(int b, int c){
        v=b;
        w=c;
    }
};

vector< vector<pp> >alledges;

void dfs1(int cur, int par){
    int nwsub=1;
    int l=alledges[cur].size();
    for(int i=0;i<l;++i){
        int nxt=alledges[cur][i].v;
        if(nxt!=par){
            dfs1(nxt,cur);
            nwsub+=subtreesize[nxt];
        }
    }
    subtreesize[cur]=nwsub;
}

void dfs2(int cur, int par, int edgew){
    int Y=subtreesize[cur];
    int tot=Y*(subtreesize[1]-Y);
    allpos[edgew]+=tot;
    int l=alledges[cur].size();
    for(int i=0;i<l;++i){
        int nxt=alledges[cur][i].v;
        int ww=alledges[cur][i].w;
        if(nxt!=par){
            dfs2(nxt,cur,ww);
            //nwsub+=subtreesize[nxt];
        }
    }
}

string calc(){
    int l=allpos.size();
    for(int i=0;i<l;++i){
        int nw=allpos[i]/2;
        allpos[i]=allpos[i]%2;
        if((i+1)<l){
            allpos[i+1]+=nw;
        }
    }
    string a="";
    int f=0;
    for(int i=l-1;i>=0;--i){
        if(allpos[i]==0){
            if(f){
                a.push_back('0');
            }
        }
        else{
            a.push_back('1');
            f=1;
        }
    }
    if(a.size()==0){
        a.push_back('0');
    }
    return a;
}
 
// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};
 
// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
 
// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V];  // Tnis will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges
 
    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    // Allocate memory for creating V ssubsets
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );
 
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        struct Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
 
    // print the contents of result[] to display the built MST
    //printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i){
        int uu=result[i].src+1;
        int vv=result[i].dest+1;
        int ww=result[i].weight;
        alledges[uu].push_back(pp(vv,ww));
        alledges[vv].push_back(pp(uu,ww));
    }
    return;
}
 
// Driver program to test above functions
int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    for(int i=0;i<4000000;++i){
        allpos.push_back(0);
    }
    int V;  // Number of vertices in graph
    int E;  // Number of edges in graph
    scanf("%d %d",&V,&E);
    vector<pp>line;
    for(int i=0;i<=(V+2);++i){
        alledges.push_back(line);
        subtreesize[i]=0;
    }
    struct Graph* graph = createGraph(V, E);
     for(int i=1;i<=E;++i){
         int u,v,w;
         scanf("%d %d %d",&u,&v,&w);
         graph->edge[i-1].src = u-1;
        graph->edge[i-1].dest = v-1;
        graph->edge[i-1].weight = w;
     }
 
    KruskalMST(graph);
    dfs1(1,-1);
    
    dfs2(1,-1,0);
    //for(int i=0;i<10;++i){
      //  cout<<allpos[i]<<" ";
    //}
    //cout<<"\n";
    string ans=calc();
    cout<<ans<<"\n";
    return 0;
}
