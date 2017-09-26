/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

//--debugging func---//

void printv(VI oka){
    int l=oka.size();
    FREP(i,0,(l-1)){
        cout<<oka[i]<<" ";
    }
    cout<<"\n";
}

void printvv(vector<VI>oka){
    int l=oka.size();
    FREP(i,0,(l-1))printv(oka[i]);
    cout<<"\n";
}

//--debugging func---//


int vis[200005];

int chain1[200005];
int chain2[200005];
int maxdis[200005];

vector < vector <PII> > edg;


void dfs(int cur){
    vis[cur]=1;
    chain1[cur]=-1;
    chain2[cur]=-1;
    maxdis[cur]=0;
    //if(d>maxdepth)maxdepth=d;
    int l=edg[cur].size();
    FREP(i,0,(l-1)){
        int v=edg[cur][i].first;
        int w=edg[cur][i].second;
        if(!vis[v]){
            dfs(v);
            //chain[cur]=max(chain[cur],1+chain[newedg[cur][i]]);
            if((w+chain1[v])>chain1[cur]){
                chain2[cur]=chain1[cur];
                chain1[cur]=w+chain1[v];
            }
            else if((w+chain1[v])>chain2[cur]){
                chain2[cur]=w+chain1[v];
            }
            maxdis[cur]=max(maxdis[cur],maxdis[v]);
        }
    }
    maxdis[cur]=max(maxdis[cur],chain1[cur]+chain2[cur]);
    //maxdepth=max(maxdis[cur],maxdepth);
    return;
}

void takeg(int n, int m){
    edg.clear();
    vector<PII>line;
    FREP(i,1,(n+2)){
        edg.PB(line);
    }
    FREP(i,1,m){
        int u,v,w;//--debugging func---//
        scanf("%d %d %d",&u,&v,&w);
        edg[u].PB(make_pair(v,w));
        edg[v].PB(make_pair(u,w));
    }
}


int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        takeg(n,(n-1));
    //dfs(1,1,col[1]);
    //printvv(newedg);
        memset(vis,0,sizeof(vis));
        dfs(0);
        printf("Case %d:\n",cs++ );
        FREP(i,0,(n-1)){
            printf("%d\n",maxdis[i]);
        }
    }
    return 0;
}