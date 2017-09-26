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

int n,k;

vector<VI>edges;
vector<int>ans;

void printv(){
    FREP(i,0,(n-1))printf("%c",ans[i]+'A');
    printf("\n");
}
int visited[40];

int did;

void dfs(int cur, int deep){
    if(did==k){
        return;
    }
    if(deep==n){
        printv();
        did++;
        return;
    }
    int l=edges[cur].size();
    FREP(i,0,(l-1)){
        if(did==k)break;
        int nxt=edges[cur][i];
        if(!visited[nxt] && did<k){
            visited[nxt]=1;
            ans.PB(nxt);
            dfs(nxt,deep+1);
            ans.pop_back();
            visited[nxt]=0;
        }
    }
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        scanf("%d %d",&n,&k);
        VI line;
        edges.clear();
        ans.clear();
        did=0;
        FREP(i,0,(n+2)){
            edges.PB(line);
        }
        FREP(i,0,n)visited[i]=0;
        FREP(i,0,(n-1)){
            FREP(j,0,(n-1)){
                if(i==j)continue;
                edges[i].PB(j);
            }
        }
        FREP(i,0,(n-1))edges[n].PB(i);
        printf("Case %d:\n",cs++);
        dfs(n,0);
    }
    return 0;
}
