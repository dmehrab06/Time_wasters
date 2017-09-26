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
#define ISVALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
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

int vis[31][31];
char grid[31][31];

int hx, hy;

vector<PII>pp(4);

char str[31];

void bfs(int srcx, int srcy, int depth, int n, int m){
    vis[srcx][srcy]=depth;
    queue<PII>bfsq;
    bfsq.push(make_pair(srcx,srcy));
    while(!bfsq.empty()){
        PII oka=bfsq.front();
        bfsq.pop();
        int cx=oka.first;
        int cy=oka.second;
        int dd=vis[cx][cy];
        FREP(dx,-1,1){
            FREP(dy,-1,1){
                if(dx==0 || dy==0){
                    int nxtx=cx+dx;
                    int nxty=cy+dy;
                    if(ISVALID(nxtx,nxty,n,m) && vis[nxtx][nxty]==-1 && !(grid[nxtx][nxty]=='m' || grid[nxtx][nxty]=='#')){
                        bfsq.push(make_pair(nxtx,nxty));
                        vis[nxtx][nxty]=dd+1;
                    }
                }
            }
        }

    }

    return;
}

void takegrid(int n, int m){

    FREP(i,0,(n-1)){
        scanf("%s",grid[i]);
    }
    FREP(i,0,(n-1)){
        FREP(j,0,(m-1)){
            if(grid[i][j]>='a' && grid[i][j]<='c'){
                pp[grid[i][j]-'a']=make_pair(i,j);
            }
            else if(grid[i][j]=='h'){
                hx=i;
                hy=j;
            }
        }
    }
}


int go(int n, int m){
   // int l=pp.size();
    int dd=0;
    FREP(i,0,2){
        memset(vis,-1,sizeof(vis));
        bfs(pp[i].first,pp[i].second,0,n,m);
        int ans=vis[hx][hy];
        cout<<i<<" "<<ans<<"\n";
        dd=max(dd,ans);
    }
    return dd;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        takegrid(n,m);
        int ans=go(n,m);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
