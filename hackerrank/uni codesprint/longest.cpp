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

vector<VI>edges;
vector<PII>sortbydeg;

VI best;
int bestL=0;
VI cur;

int usedassrc1[10004];
int vis[10004];
void takeginput(int n, int m){
    //memset(usedassrc1,0,(n+2));
    VI line;
    FREP(i,1,(n+3)){
        edges.PB(line);
    }
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        edges[u].PB(v);
        edges[v].PB(u);
    }
    FREP(i,1,n){
        sortbydeg.PB(make_pair(edges[i].size(),i));
    }
    SORTV(sortbydeg);
}

void dfs(int src){
    cur.PB(src);
    vis[src]=1;
    int deg=edges[src].size();
    VI possible;
    FREP(i,0,(deg-1)){
        if(!vis[edges[src][i]])possible.PB(edges[src][i]);
    }
    deg=possible.size();
    if(deg==0){
        int ll=cur.size();
        if(ll>bestL){
            bestL=ll;
            best=cur;
        }
        return;
    }
    double portion=(1.0/(double)deg);
    double frac=(rand()/(double)RAND_MAX);
    int div=frac/portion;
    if(div==deg)div--;
    dfs(possible[div]);
}

void choosesrcrandom(int n){
   // cout<<"in random\n";
    int src=-1;
    while(!(src>0)){
        src=(rand()%n+1);
    }
    //usedassrc1[src]++;
    cur.clear();
    memset(vis,0,sizeof(vis));
   // cout<<src<<" dia chalai\n";
    dfs(src);
}

void choosefromsort(int idx){
   // cout<<"in sort\n";
    int src=sortbydeg[idx].second;
    cur.clear();
    memset(vis,0,sizeof(vis));
   // cout<<src<<" dia chalai\n";
    dfs(src);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int totalit=1000000/max(n,m);
    int rndit=totalit/100;
    //int canbeused=(rndit/n)+2;
    int srtit=(totalit/100)*50;
    takeginput(n,m);
    FREP(i,1,rndit){
        choosesrcrandom(n);
    }
    FREP(i,0,srtit){
        choosefromsort(i%n);
    }
    printf("%d\n",bestL);
    FREP(i,0,(bestL-1)){
        printf("%d ",best[i]);
    }
    printf("\n");
    return 0;
}
