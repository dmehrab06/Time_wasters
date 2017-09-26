#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000000000
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
#define PIII pair<PII,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000001

using namespace std;

//0 0
//1 khub besi
//1 khub kom


vector< vector <PIII> >edges;

vector<int>path;
LLI bestcost=MXX;
int ticketused=-1;
vector<int>curpath;
int visited[1005];

int S,E;

void dfs(int cur, LLI cost, int used, int lastused){
    if(cur==E){
        if(used<=1 && cost<bestcost){
            bestcost=cost;
            path=curpath;
            ticketused=lastused;
        }
        return;
    }
    visited[cur]=1;
    int d=edges[cur].size();
    FREP(i,0,(d-1)){
        int nxt=edges[cur][i].first.first;
        LLI w=edges[cur][i].first.second;
        int comm=edges[cur][i].second;
        if(!visited[nxt]){
            curpath.PB(nxt);
            if(comm){
                dfs(nxt,cost+w,used+1,cur);
            }
            else{
                dfs(nxt,cost+w,used,lastused);
            }
            curpath.pop_back();
        }
    }
    visited[cur]=0;
}

int main(){
    int n;
    while(scanf("%d %d %d",&n,&S,&E)==3){
        edges.clear();
        vector<PIII>line;
        FREP(i,1,(n+3)){
            edges.PB(line);
        }
        int eco,com;
        scanf("%d",&eco);
        FREP(i,1,eco){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edges[u].PB(make_pair ( make_pair(v,w),0));
        }
        scanf("%d",&com);
        FREP(i,1,com){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edges[u].PB(make_pair ( make_pair(v,w),1));
        }
        dfs(S,0,0,-2);
        int d=path.size();
        printf("%d",S);
        FREP(i,0,(d-1))printf(" %d",path[i]);
        printf("\n");
        if(ticketused<0){
            printf("Ticket Not Used\n");
        }
        else{
            printf("%d\n",ticketused);
        }
        printf("%lld\n",bestcost);
    }
    return 0;
}
