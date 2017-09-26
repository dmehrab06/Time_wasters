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
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

//int g[1004][1004];

//vector<PII>edg;

vector<SI>distvalue;

int par[100005];
int w[100005];

vector< vector <PII> >gg;

void init(){
    //memset(g,0,sizeof(g));
    //edg.clear();
    gg.clear();
    distvalue.clear();
}
SI::iterator it;
void dfs(int src){
    int l=gg[src].size();
    FREP(i,0,(l-1)){
        int v=gg[src][i].first;
        int w=gg[src][i].second;
        dfs(v);
        for(it=distvalue[v].begin();it!=distvalue[v].end();++it){
            int val=*it;
            if((val+w)>=0){
                distvalue[src].insert(val+w);
            }
        }
    }
    return;
}

void takeg(int n){
    vector<PII> line;
    SI line2;
    FREP(i,0,(n+3))gg.PB(line);
    FREP(i,0,(n+3))distvalue.PB(line2);
    FREP(i,1,n){
        int a;
        scanf("%d",&a);
        if(a>=0){
            distvalue[i].insert(a);
        }
    }
    FREP(i,1,n){
        scanf("%d",&par[i]);
    }
    FREP(i,1,n){
        scanf("%d",&w[i]);
    }
    FREP(i,2,n){
        int p=par[i];
        int wt=w[i];
        gg[p].PB(make_pair(i,wt));
    }
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        init();
        takeg(n);
        dfs(1);
        printf("Case %d:\n",cs++);
        FREP(i,1,n){
            printf("%d\n",(int)distvalue[i].size());
        }
    }
    return 0;
}
