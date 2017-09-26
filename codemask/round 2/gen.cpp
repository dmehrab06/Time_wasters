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

/*------the template below are used in bitmasking------*/
/*
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
}*/
/*------the template above are used in bitmasking------*/


/*-------the template below is needed for segment tree-----*/
struct node{
    long long int propagation;
    long long int sum;
    node(){
        propagation=0;
        sum=0;
    }
    node(long long int p, long long int s){
        propagation=p;
        sum=s;
    }
};

node segtree[400005];
int arr[100005];

void myinit(int N){
    int l=N<<1;
    l=l+N;
    for(int i=1;i<=l;++i){
        segtree[i].sum=0;
        segtree[i].propagation=0;
    }
}

void init(int b, int e, int node){
    if(b==e){
        segtree[node].sum=arr[b];
        segtree[node].propagation=0;

    }
    else{
  //  printf("in node %d, range %d to %d\n",node,b,e);
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(b,mid,left);
    init(mid+1,e,right);
    segtree[node].sum=segtree[left].sum+segtree[right].sum;
    segtree[node].propagation=0;
    }
}

long long int query(int i, int j, int b, int e, int node, long long  int propagateval){
    if(b>=i && e<=j){
        return segtree[node].sum+(long long int)(e-b+1)*(long long int)propagateval;
    }
    if(e<i || b>j){
        return 0;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    long long int prop=segtree[node].propagation;
    long long int min1=query(i,j,b,mid,left,propagateval+prop);
    long long int min2=query(i,j,mid+1,e,right,propagateval+prop);
    return min1+min2;
}

void update(int i, int j, int b, int e, int node, long long int toadd){
    if(b>=i && e<=j){
        segtree[node].sum+=(long long int)(e-b+1)*toadd;
        segtree[node].propagation+=toadd;
        //the two lines above are not clear yet. ektu dekhte hobe
        return;
    }
    if(e<i || b>j){
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    update(i,j,b,mid,left,toadd);
    update(i,j,mid+1,e,right,toadd);
    segtree[node].sum=segtree[left].sum+segtree[right].sum+segtree[node].propagation*(e-b+1); //eikhane propagation er plus jog hoilo ken bujhi nai
}

/*------the template above is needed for segment tree-----*/

struct date{
    int d;
    int m;
    int y;
    date(){
        d=0;
        m=0;
        y=0;
    }
    date(int day, int mon, int year){
        d=day;
        m=mon;
        y=year;
    }
    bool operator<(const date &dd) const {
        if(y==dd.y && m==dd.m)return d<dd.d;
        if(y==dd.y)return m<dd.m;
        return y<dd.y;
    }
};

string datetostring(date ed){
    string dd="";
    string mm="";
    string yy="";
    int a=ed.d;
    while(a){
        dd+=a%10+'0';
        a/=10;
    }
    reverse(dd.begin(),dd.end());
    a=ed.m;
    while(a){
        mm+=a%10+'0';
        a/=10;
    }
    reverse(mm.begin(),mm.end());
    a=ed.y;
    while(a){
        yy+=a%10+'0';
        a/=10;
    }
    reverse(yy.begin(),yy.end());
    string ans="";
    ans+=dd;
    ans+=mm;
    ans+=yy;
    return ans;
}

bool isleap(int y){
    return (y%400==0) || (y%100 && y%4==0);
}

int main(){
    printf("200000\n");
    for(int i=1;i<=199994;i+=6){
        printf("5 1 2016\n10 2 1972\n31 12 2271\n1 1 1972\n1 1 2016\n1 1 2271\n");
    }


    return 0;
}
