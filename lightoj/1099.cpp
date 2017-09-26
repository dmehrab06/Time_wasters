#include<bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000
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
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define XX first
#define YY second
using namespace std;

vector< vector <PII> >edges;

int dist[4][5006];
int vis[4][5006];

set< pair<int,PII> >pq;

void dijkstra(int src, int n){
    FREP(i,0,n){
        dist[1][i]=MXX;
        dist[2][i]=MXX;
        vis[1][i]=0;
        vis[2][i]=0;
    }
    pq.insert(make_pair(1,make_pair(0,src)));
    //vis[1][1]=1;
    dist[1][1]=0;
    set< pair<int,PII> >::iterator it;
    while(!pq.empty()){
        it=pq.begin();
        pair<int,PII>pp=*it;
        pq.erase(pp);
        int k=pp.first;
        int u=pp.second.second;
        //cout<<k<<" "<<u<<"\n";
        if(vis[k][u])continue;
        vis[k][u]=1;
        int l=edges[u].size();
        FREP(i,0,(l-1)){
            PII cur=edges[u][i];
            int v=cur.first; int w=cur.second;
            int alt=dist[k][u]+w;
         //   cout<<v<<" "<<w<<" "<<alt<<"\n";
            if(alt<dist[1][v]){
                dist[2][v]=dist[1][v];
                pq.insert(make_pair(2,make_pair(dist[2][v],v)));
                dist[1][v]=alt;
                pq.insert(make_pair(1,make_pair(alt,v)));
            }
            else if(alt>dist[1][v] && alt<dist[2][v]){
                dist[2][v]=alt;
                pq.insert(make_pair(2,make_pair(dist[2][v],v)));
            }
        }
    }
    return;
}

void takeginp(int n, int m){
    vector<PII>line;
    FREP(i,0,(n+2))edges.PB(line);
    FREP(i,1,m){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        PII p1=make_pair(v,w);PII p2=make_pair(u,w);
        edges[u].PB(p1);edges[v].PB(p2);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,m;
        edges.clear();
        scanf("%d %d",&n,&m);
        takeginp(n,m);
        dijkstra(1,n);
        int ans1=MXX;
        int ans2=dist[2][n];
        printf("Case %d: %d\n",cs++,min(ans1,ans2));
    }
    return 0;
}

