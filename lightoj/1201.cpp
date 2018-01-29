/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
//#include <dirent.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
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
#define PLLI pair<LLI,LLI>
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
//using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

#define si(a) scanf("%d",&a)
#define f first
#define s second
#define mp(a,b) make_pair(a,b)
#define INF 2000000000

const int MAX_E=60003;
const int MAX_V=5003;
int ver[MAX_E],cap[MAX_E],nx[MAX_E],last[MAX_V],ds[MAX_V],st[MAX_V],now[MAX_V],edge_count,S,T;

inline void reset()
{
    memset(nx,-1,sizeof(nx));
    memset(last,-1,sizeof(last));
    edge_count=0;
}
inline void addedge(const int v,const int w,const int capacity,const int reverse_capacity)
{
    ver[edge_count]=w; cap[edge_count]=capacity; nx[edge_count]=last[v]; last[v]=edge_count++;
    ver[edge_count]=v; cap[edge_count]=reverse_capacity; nx[edge_count]=last[w]; last[w]=edge_count++;
}
inline bool bfs()
{
    memset(ds,-1,sizeof(ds));
    int a,b;
    a=b=0;
    st[0]=T;
    ds[T]=0;
    while (a<=b)
    {
        int v=st[a++];
        for (int w=last[v];w>=0;w=nx[w])
        {
            if (cap[w^1]>0 && ds[ver[w]]==-1)
            {
                st[++b]=ver[w];
                ds[ver[w]]=ds[v]+1;
            }
        }
    }
    return ds[S]>=0;
}
int dfs(int v,int cur)
{
    if (v==T) return cur;
    for (int &w=now[v];w>=0;w=nx[w])
    {
        if (cap[w]>0 && ds[ver[w]]==ds[v]-1)
        {
            int d=dfs(ver[w],min(cur,cap[w]));
            if (d)
            {
                cap[w]-=d;
                cap[w^1]+=d;
                return d;
            }
        }
    }
    return 0;
}
inline long long flow()
{
    long long res=0;
    while (bfs())
    {
        for (int i=0;i<MAX_V;i++) now[i]=last[i];
        while (1)
        {
            int tf=dfs(S,INF);
            res+=tf;
            if (!tf) break;
        }
    }
    return res;
}


vector < VI >g;
int color[1003];
vector <int> As;
vector <int> Bs;

void takeinp(int n, int m){
    g.clear();
    reset();
    FREP(i,0,(n+4)){
        VI line;
        g.PB(line);
    }
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        addedge(u,v,1,1);
        g[u].PB(v); g[v].PB(u);
    }
}

void biparti(){
    MSET(color,-1);
    queue<int>bfsq;
    bfsq.push(1);
    color[1] = 0;
    while(!bfsq.empty()){
        int cur = bfsq.front();
        bfsq.pop();
        if(color[cur]==0)As.PB(cur);
        else Bs.PB(cur);
        FREP(i,0,g[cur].size()-1){
            int v = g[cur][i];
            if(color[v]==-1){
                color[v] = 1-color[cur];
                bfsq.push(v);
            }
        }
    }
}

void makeg(){
    S = 0;
    int asz = As.size(); int bsz = Bs.size();
    FREP(i,0,asz-1)cout<<As[i]<<" ";cout<<"\n";
    FREP(i,0,bsz-1)cout<<Bs[i]<<" ";cout<<"\n";
    T = asz+bsz+1;
    FREP(i,0,asz-1)addedge(S,i+1,1,1);
    FREP(i,0,bsz-1)addedge(asz+1+i,T,1,1);
}

int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    //cout<<t<<"\n";
    FREP(cs,1,t){
        As.clear(); Bs.clear();
        int n,m;
        scanf("%d %d",&n,&m);
        takeinp(n,m);
        biparti();
        makeg();
        printf("Case %d: %lld\n",cs,(LLI)n-flow());
    }
    return 0;
}
