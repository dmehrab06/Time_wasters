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

//int visited[20005];
//int appears[20005];
//vector < vector <int> >edges;

/*------ the below template does BFS inside with some modifications------- */

/*int BFS(vector<int>allnode, int N){
    queue<int>bfsqueue;
    int maxside=0;
    vector<int>depth(20005,-1);
    for(int i=0;i<N;++i){
        int nownode=allnode[i];
        int mx1=0;
        int mx2=0;
        //cout<<"outer for loop "<<i<<"\n";
        if(visited[nownode]==0){
            bfsqueue.push(nownode);
            depth[nownode]=0;
            visited[nownode]=1;
            while(!bfsqueue.empty()){
                int a=bfsqueue.front();
                //cout<<"queue front "<<a<<"\n";
                int da=depth[a];
                if(da%2==0)mx1++;
                else{mx2++;}
                bfsqueue.pop();
                int l=edges[a].size();
                for(int k=0;k<l;++k){
                    int tonode=edges[a][k];
                    if(visited[tonode]==0){
                    bfsqueue.push(tonode);
                    depth[tonode]=1+da;
                    visited[tonode]=1;
                    }
                }
                //cout<<l<<"\n";
            }
        }
        //cout<<nownode<<" "<<mx1<<" "<<mx2<<"\n";
        maxside+=max(mx1,mx2);

    }
    return maxside;
}
*/
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

//int marriage[20][20];
//int dp[20][40000];

/*int N;
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
*/

long long int NC2(long long int n){
    if(n<=1)return 0;
    long long int s=n*(n-1);
    s/=2;
    return s;
}
struct frnd{
    int id;
    int bond;
    frnd(){
        id=0;
        bond=0;
    }
    frnd(int i, int b){
        id=i;
        bond=b;
    }
};

struct compare
{
  bool operator()(const frnd& l, const frnd& r)
  {
      return l.bond < r.bond;
  }
};

int bondship[150003];
frnd check[11];
int dist[100007];
//int dist[100007];
vector<int>toprint1;
vector<int>toprint2;
vector<int>lside;
vector<int>rside;
int main(){
    int n,d,h;
    cin>>n>>d>>h;
    int rh=h;
    int lh=(d-h);
    if(lh>rh){
        printf("-1\n");
    }
    else{
        int edgeadded=0;
        int par=1;
        int rightstart=2;
        int curdis=1;
        for(int i=1;i<=rh;++i){
            //printf("%d %d\n",par,rightstart);
            toprint1.push_back(par);
            toprint2.push_back(rightstart);
            rside.push_back(rightstart);
            dist[rightstart]=curdis;
            par=rightstart;
            rightstart++;
            curdis++;
            edgeadded++;
        }
        par=1;
        curdis=1;
        int leftstart=rightstart;
        for(int i=1;i<=lh;++i){
            //printf("%d %d\n",par,leftstart);
            toprint1.push_back(par);
            toprint2.push_back(leftstart);
            lside.push_back(leftstart);
            dist[leftstart]=curdis;
            par=leftstart;
            leftstart++;
            curdis++;
            edgeadded++;
        }
        if(edgeadded==(n-1)){
            int sz=toprint1.size();
            for(int k=0;k<sz;++k){
                    printf("%d %d\n",toprint1[k],toprint2[k]);
            }
        }
        else{
        int otherrootnewd=1+max(lh,rh);
        int otherrootnewh=1;
        if(otherrootnewd<=d && otherrootnewh<=h){
            for(int i=leftstart;i<=n;++i){
               // printf("1 %d\n",i);
               toprint1.push_back(1);
               toprint2.push_back(i);
            }
            int sz=toprint1.size();
                for(int k=0;k<sz;++k){
                    printf("%d %d\n",toprint1[k],toprint2[k]);
            }
        }
        else{
            int leftsize=lside.size();
            int candid=-1;
            for(int j=0;j<leftsize;++j){
                int curv=lside[j];
                int newd=max(dist[curv]+rh+1,1+lh-dist[curv]);
                int newh=dist[curv]+1;
                if(newd<=d && newh<=h){
                    candid=curv;
                    break;
                }
            }
            if(candid==-1){
                int rightsize=rside.size();

                for(int j=0;j<rightsize;++j){
                    int curv=rside[j];
                    int newd=max(dist[curv]+lh+1,1+rh-dist[curv]);
                    int newh=dist[curv]+1;
                    if(newd<=d && newh<=h){
                        candid=curv;
                        break;
                    }
                }
            }
            if(candid==-1){
                printf("-1\n");
            }
            else{
                for(int k=leftstart;k<=n;++k){
                    toprint1.push_back(candid);
                    toprint2.push_back(k);
                }
                int sz=toprint1.size();
                for(int k=0;k<sz;++k){
                    printf("%d %d\n",toprint1[k],toprint2[k]);
                }
            }
        }
        }

    }
    return 0;
}

