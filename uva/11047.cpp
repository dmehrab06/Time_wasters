#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int GCD(int a,int b){
    return a==0?b:GCD(b%a,a);
}

string ntoa(int b){
    string a="";
    while(b){
        a+=(b%10+'0');
        b/=10;
    }
    reverse(a.begin(),a.end());
    return a;

}

struct myitem{
    int h;
    int w;
    myitem(int a, int b){
        h=a;
        w=b;
        if(h>w){
            int t=h;
            h=w;
            w=t;
        }
    }
};

bool mycompare (myitem a, myitem b){
    if(a.h==b.h)return a.w<b.w;
    return a.h<b.h;
}

//int representative[20005];
int findrep(int a, int * representative){
    if(representative[a]!=a){
        return representative[a]=findrep(representative[a], representative);
    }
    else{
        return a;
    }
}

void unionfind(int x, int y, int * representative){
    int xp,yp;
    xp=findrep(x,representative);
    yp=findrep(y, representative);
    representative[yp]=xp;
}

/*---------credit for the graph class and methods below: geeksforgeeks---------*/
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

/*---------credit for the graph class and methods above: geeksforgeeks---------*/

/*------the template below calculates phi for 1 to N, and stores them in phi credit: codeforces grandmaster savinov----- */

/*const int N = 5000000;
int lp[N + 1];
unsigned long long phi[N + 1];
//int cumulativescore[N+1];
vector<int> pr;

void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] =  (i - 1);
            pr.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}*/

/*------the template above calculates phi for 1 to N, and stores them in phi credit: codeforces grandmaster savinov----- */

bool visited[2000005];
int parent[2000005];
//vector < vector <int> >edges;

/*------ the below template does BFS inside with some modifications------- */

int edges[6009][6009];
int BFS(int src, int des, int total){
    for(int i=1;i<=total;++i){
        visited[i]=false;
        parent[i]=0;
    }
    queue<int>bfsqueue;
    bfsqueue.push(src);
    parent[src]=src;
    visited[src]=true;
    while(!bfsqueue.empty()){
        int a=bfsqueue.front();
        //cout<<"queue front "<<a<<"\n";
        if(a==des)return 1;
        bfsqueue.pop();
        int l=edges[a][0];
        for(int k=1;k<=l;++k){
            int tonode=edges[a][k];
            if(!visited[tonode]){
               bfsqueue.push(tonode);
               parent[tonode]=a;
               visited[tonode]=true;
            }
        }
                //cout<<l<<"\n";
    }
    return -1;

}

/*------ the above template does BFS inside with some modifications------- */

/*------the template below are used in bitmasking------*/

int setbit(int N,int pos){
    return N=N|(1<<pos);
}
int resetbit(int N,int pos){
    return N=N&(~(1<<pos));
}
int checkbit(int N,int pos){
    return N&(1<<pos);
}
int countsets(int N){
int a=0;
    for(int i=1;i<=N;i<<=1){
        if(N&i)a++;
    }
    return a;
}

/*------the template above are used in bitmasking------*/

int marriage[20][20];
int dp[20][70000];

int N;
int getmaxindex(int man, int mask){
    if(man==N)return 0;
    if(dp[man][mask]!=-1)return dp[man][mask];
    int mx=0;
    for(int i=0;i<N;++i){
        if(checkbit(mask,i)==0){
            int newmask=setbit(mask,i);
            mx=max(mx,marriage[man][i]+getmaxindex(man+1,newmask));
            //mask=resetbit(mask,i);
        }
    }
    return dp[man][mask]=mx;
}


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


int adj[103][103];
int par[103][103];
string namesarr[103];
void printpath(int s,int d){
    cout<<namesarr[s];
    while(1){
        s=par[s][d];
        cout<<" "<<namesarr[s];
        if(s==d){
            break;
        }
    }
    cout<<"\n";
}
int main(){
    //ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int node;
        cin>>node;
        map<string,int>names;
        for(int i=1;i<=node;++i){
            string a;
            cin>>a;
            names[a]=i;
            namesarr[i]=a;
        }
        for(int i=1;i<=node;++i){
            for(int j=1;j<=node;++j){
                par[i][j]=i;
            }
        }
        for(int i=1;i<=node;++i){
            for(int j=1;j<=node;++j){
                scanf("%d",&adj[i][j]);
                if(adj[i][j]==-1){
                    adj[i][j]=100000000;
                }
            }
        }
        for(int i=1;i<=node;++i){
            for(int j=1;j<=node;++j){
                par[i][j]=j;
            }
        }
        /*for(int i=1;i<=node;++i){
            for(int j=i+1;j<=node;++j){
                int a=min(adj[i][j],adj[j][i]);
                adj[i][j]=a;
                adj[j][i]=a;
            }
        }*/
        for(int k=1;k<=node;++k){
            for(int i=1;i<=node;++i){
                for(int j=1;j<=node;++j){
                    if(adj[i][k]+adj[k][j]<adj[i][j]){
                        adj[i][j]=adj[i][k]+adj[k][j];
                        par[i][j]=par[i][k];
                    }
                }
            }
        }
        int q;
        cin>>q;
        for(int i=1;i<=q;++i){
            string emp,src,dest;
            cin>>emp>>src>>dest;
            int s,d;
            if(names.find(src)==names.end())s=-1;
            else{
            s=names[src];}
            if(names.find(dest)==names.end())d=-1;
            else{d=names[dest];}
            if(s==-1 || d==-1){
                cout<<"Sorry Mr "<<emp<<" you can not go from "<<namesarr[s]<<" to "<<namesarr[d]<<"\n";
            }
            else{
                if(adj[s][d]>9999999){
                    cout<<"Sorry Mr "<<emp<<" you can not go from "<<namesarr[s]<<" to "<<namesarr[d]<<"\n";
                }
                else{
                    cout<<"Mr "<<emp<<" to go from "<<namesarr[s]<<" to "<<namesarr[d]<<", you will receive "<<adj[s][d]<<" euros\n";
                    printf("Path:");
                    printpath(s,d);
                    //cout<<namesarr[d]<<"\n";
                }
            }
        }
    }
    return 0;
}
