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

int mx1[30005];
int mx2[30005];

vector< vector <PII> >edges;

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

int dfs(int cur, int par){
    mx1[cur]=0;
    mx2[cur]=0;
    int l=edges[cur].size();
    FREP(i,0,(l-1)){
        int nxt=edges[cur][i].first;int w=edges[cur][i].second;
        if(nxt==par)continue;
        int val=w+dfs(nxt,cur);
        if(val>mx1[cur]){
            mx2[cur]=mx1[cur];
            mx1[cur]=val;
        }
        else if(val>mx2[cur]){
            mx2[cur]=val;
        }
    }
    return mx1[cur];
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        edges.clear();
        takeginp(n,(n-1));
        dfs(0,-1);
        int ans=-1;
        FREP(i,0,(n-1)){
            ans=max(ans,mx1[i]+mx2[i]);
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
