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

//dp[n][weight]

int dp[1003][1003];

int vis1[1003];

int beauty[1003];
int weighttt[1003];

vector <VI> g;

vector < VI > allcmp;

vector < int >  elem;

void takeg(int n, int m){
    VI line;
    FREP(i,0,(n+3)){
        g.PB(line);
    }
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
}

void dfs1(int cur){
    vis1[cur]=1;
    elem.PB(cur);
    //mxcmp=max(cmp,mxcmp);
    int deg=g[cur].size();
    FREP(i,0,(deg-1)){
        int nxt=g[cur][i];
        if(!vis1[nxt]){
            dfs1(nxt);
        }
    }
    return;
}


int solve(int cur, int weight){
    if(weight<=0)return 0;
    if(cur<0)return 0;
    if(dp[cur][weight]!=-1){
        return dp[cur][weight];
    }
    int totbeauty=0;
    int totweight=0;
    int ll=allcmp[cur].size();
    FREP(i,0,(ll-1)){
        int mokha=allcmp[cur][i];
        int ww=weighttt[mokha];
        int bb=beauty[mokha];
        totbeauty+=bb;
        totweight+=ww;
        if(ww<=weight){
            dp[cur][weight]=max(dp[cur][weight],bb+solve(cur-1,weight-ww));
        }
    }
    if(totweight<=weight)dp[cur][weight]=max(dp[cur][weight],totbeauty+solve(cur-1,weight-totweight));
    dp[cur][weight]=max(dp[cur][weight],solve(cur-1,weight));
    return dp[cur][weight];
}

// Driver Code
int main()
{
    int n,m,w;
    scanf("%d %d %d",&n,&m,&w);
    FREP(i,1,n){
        scanf("%d",&weighttt[i]);
    }
    FREP(i,1,n){
        scanf("%d",&beauty[i]);
    }
    takeg(n,m);
    FREP(i,1,n){
        if(!vis1[i]){
            //mxcmp=0;
            elem.clear();
            dfs1(i);
            allcmp.PB(elem);
        }
    }
   // printf("hoise\n");
   memset(dp,-1,sizeof(dp));
    int group=allcmp.size();
    int ans=solve(group-1,w);
    cout<<ans<<"\n";
}
