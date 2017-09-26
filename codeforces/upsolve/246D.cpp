#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
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
#define pi acos(-1.0)
#define float double
using namespace std;

vector<SI>colcnt;
vector<VI>adj;
int col[200005];
//int came[3005];

void sg(int m){
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].PB(v);
        adj[v].PB(u);
        //adj[v][++adj[v][0]]=u;
    }
}

void init(int n){
    SI line;
    FREP(i,1,(n+3)){
        col[i]=0;
        //colcnt.PB(line);
    }
    FREP(i,1,100002){
        colcnt.PB(line);
    }
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    VI line;
    init(n);
    FREP(i,1,(n+3))adj.PB(line);
    FREP(i,1,n)scanf("%d",&col[i]);
    sg(m);
    FREP(i,1,n){
        int curcol=col[i];
        colcnt[curcol].insert(curcol);
        int d=adj[i].size();
        FREP(j,0,(d-1)){
            int v=adj[i][j];
            colcnt[curcol].insert(col[v]);
        }
    }
    int mxsz=0;
    int ans=0;
    FREP(i,1,100002){
        int cur=colcnt[i].size();
        if(cur>mxsz){
            ans=i;
            mxsz=cur;
        }
    }
    cout<<ans<<"\n";
}
