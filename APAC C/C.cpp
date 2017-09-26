//data structure--graph
//algo -- connected component, topo
//wrong answer

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
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

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// This function is a variation of DFSUytil() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }

    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

string func;

string parsey(){
    int l=func.size();
    string a="";
    FREP(i,0,(l-1)){
        if(func[i]=='=')break;
        a.PB(func[i]);
    }
    return a;
}

vector<string> parsexs(){
    int l=func.size();
    string a="";
    int from;
    FREP(i,0,(l-1)){
        if(func[i]=='('){
            from=i;
            break;
        }
        //a.PB(func[i]);
    }
    vector<string>all;
    int added=0;
    FREP(i,from+1,(l-1)){
        if(func[i]==',' || func[i]==')'){
            if(added>0){
                all.PB(a);
                a="";
                added=0;
            }
        }
        else{
            a.PB(func[i]);
            added++;
        }
    }
    return all;
}

vector<VI>myedges;
int visited[50003];

void init(){
    FREP(i,0,50002){
        visited[i]=0;
    }
}

int countcompdfs(int cur){
    visited[cur]=1;
    int d=myedges[cur].size();
    int ret=1;
    FREP(i,0,(d-1)){
        int v=myedges[cur][i];
        if(!visited[v]){
            ret+=countcompdfs(v);
        }
    }
    return ret;
}

int main()
{
    // Create a graph given in the above diagram
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        map<string, int>node;
        set<PII>edg;
        myedges.clear();
        VI starts;
        VI line;
        FREP(i,1,50000){
            myedges.PB(line);
        }
        //vector<int>vs;
        int n;
        scanf("%d",&n);
        vector<string>xs;
        int st=0;
        FREP(i,1,n){
            cin>>func;
            string y=parsey();
            if(node.find(y)==node.end()){
                node[y]=st;
                st++;
            }
            int v=node[y];
            xs=parsexs();
            int l=xs.size();
           // cout<<l<<"\n";
            FREP(j,0,(l-1)){
                string curu=xs[j];
                if(node.find(curu)==node.end()){
                    node[curu]=st;
                    st++;
                }
                int u=node[curu];
                edg.insert(make_pair(u,v));
                myedges[u].PB(v);
            }
            if(l==0){
                starts.PB(v);
            }
        }
      //  cout<<"oka\n";
        Graph g(st);
        set<PII>::iterator it;
        //int ll=edg.size();
        for(it=edg.begin();it!=edg.end();++it){
            PII ee=*it;
            g.addEdge(ee.first,ee.second);
           // cout<<"adding "<<us[i]<<" "<<vs[i]<<"\n";
           // g.addEdge(us[i],vs[i]);
        }
        init();
        int total=0;
        int stsize=starts.size();
    //    cout<<"oka2\n";
        FREP(i,0,stsize-1){
            if(!visited[starts[i]]){
                int comp=countcompdfs(starts[i]);
                total+=comp;
            }
        }
        if(total<st){
            printf("Case #%d: BAD\n",cs++);
        }
        else{
            if(g.isCyclic())
                printf("Case #%d: BAD\n",cs++);
            else
                printf("Case #%d: GOOD\n",cs++);;
        }

    }
    return 0;
}
