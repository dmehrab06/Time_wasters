/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000000000000
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector< vector <PII>  >g;
set< pair<LLI,int> >dijkstraset;
LLI dis[100005];

void init(int N){
    g.clear();
    dijkstraset.clear();
    FREP(i,1,N) dis[i]=MXX;
}

void takeg(int N, int M){
    vector<PII>line;
    FREP(i,1,(N+3))g.PB(line);
    FREP(i,1,M){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        PII edge1=make_pair(v,w); g[u].PB(edge1);
        PII edge2=make_pair(u,w); g[v].PB(edge2);
    }
}

void create1(int K,  int X, int src){
    FREP(i,1,K){
        if(i==src){
            continue;
        }
        PII edge1=make_pair(i,X);
        PII edge2=make_pair(src,X);
        g[src].PB(edge1);
        g[i].PB(edge2);
    }
}

void create2(int K,  int X){
    FREP(i,1,(K-1)){
        PII edge1=make_pair(i+1,X);
        PII edge2=make_pair(i,X);
        g[i].PB(edge1);
        g[i+1].PB(edge2);
    }
}

void rundijkstra(int src){
    dis[src]=0;
    set< pair<LLI,int> >::iterator it;
    dijkstraset.insert(make_pair(0,src));
    while(!dijkstraset.empty()){
        it=dijkstraset.begin();
        pair<LLI,int>curnode=*it;
        dijkstraset.erase(curnode);
        LLI dd=curnode.first; int nd=curnode.second; int deg=g[nd].size();
        FREP(i,0,(deg-1)){
            PII myedg=g[nd][i];
            int v=myedg.first; int w=myedg.second;
            if((dd+w)<dis[v]){
                dis[v]=dd+w;
                pair<LLI,int> nxtpair=make_pair(dis[v],v);
                dijkstraset.insert(nxtpair);
            }
        }
    }
}

void rundijkstra2(int src){
    set< pair<LLI,int> >::iterator it;
    while(!dijkstraset.empty()){
        it=dijkstraset.begin();
        pair<LLI,int>curnode=*it;
        dijkstraset.erase(curnode);
        LLI dd=curnode.first; int nd=curnode.second; int deg=g[nd].size();
        FREP(i,0,(deg-1)){
            PII myedg=g[nd][i];
            int v=myedg.first; int w=myedg.second;
            if((dd+w)<dis[v]){
                dis[v]=dd+w;
                pair<LLI,int> nxtpair=make_pair(dis[v],v);
                dijkstraset.insert(nxtpair);
            }
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int N,K,X,M,src;
        scanf("%d %d %d %d",&N,&K,&X,&M);
        scanf("%d",&src);
        init(N);
        takeg(N,M);
        if(src<=K){
            //cout<<"here\n";
            create1(K,X,src);
            rundijkstra(src);
            FREP(i,1,N){
                printf("%lld ",dis[i]);
            }
            printf("\n");
        }
        else{
            create2(K,X);
            rundijkstra(src);
            LLI mindis=MXX;
            int minnode=-1;
            FREP(i,1,K){
                if(dis[i]<mindis){
                    mindis=dis[i];
                    minnode=i;
                }
            }
            FREP(i,1,K){
                if((dis[minnode]+X)<dis[i]){
                    dis[i]=dis[minnode]+X;
                    pair<LLI,int> nxtpair=make_pair(dis[i],i);
                    dijkstraset.insert(nxtpair);
                }
            }
            rundijkstra2(src);
            FREP(i,1,N){
                printf("%lld ",dis[i]);
            }
            printf("\n");
            //printf("parina ekhoono\n");
        }
    }
    return 0;
}
