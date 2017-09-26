#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define PLLII pair< pair<LLI,LLI> , int >
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define pi acos(-1.0)
#define float double
#define MAXMOD 100000000

using namespace std;

vector<VI>edges;

LLI c[200005];
LLI sc[200005];

void dfs(int cur){
    sc[cur]=c[cur];
    int d=edges[cur].size();
    FREP(i,0,(d-1)){
        int nxt=edges[cur][i];
        dfs(nxt);
        sc[cur]+=sc[nxt];
    }
    return;
}

void bfs(){

}

vector<PLLII>myp;
int main() {
    int n;
    cin>>n;
    VI line;
    FREP(i,1,(n+3))edges.PB(line);
    FREP(i,1,n)scanf("%lld",&c[i]);
    FREP(i,2,n){
        int a;
        scanf("%d",&a);
        edges[a].PB(i);

    }
    dfs(1);
    FREP(i,1,n){
        PLLII meh=make_pair(make_pair(c[i],sc[i]),i);
        myp.PB(meh);
    }
    priority_queue<PLLII, vector<PLLII> > qq;
    qq.push(myp[0]);
    LLI total=0;
    LLI ase=myp[0].second;
    while(!qq.empty()){
        //int cur=qq.second;
        PLLII oka=qq.top();
        qq.pop();
        int cur=oka.second;
        total+=(oka.first.second-oka.first.first)+(ase-oka.first.first);
        ase-=oka.first.second;
        int d=edges[cur].size();
        FREP(i,0,(d-1)){
            int nxt=edges[cur][i];
            qq.push(myp[nxt-1]);
        }
    }
    cout<<total<<"\n";
    return 0;
}
