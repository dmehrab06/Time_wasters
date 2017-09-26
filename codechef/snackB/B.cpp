/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int money[503][503];

int vis[503][503];

int hour[503][503];

vector<PII>mxcells;

void init(){
    memset(vis,0,sizeof(vis));
    memset(hour,0,sizeof(hour));
    mxcells.clear();
}

void findmaxcell(int mx, int n, int m){
    FREP(i,1,n){
        FREP(j,1,m){
            if(money[i][j]==mx){
                mxcells.PB(make_pair(i,j));
            }
        }
    }
}

int bfs(int n, int m){
    queue<PII>bfsq;
    int ll=mxcells.size();
    FREP(i,0,ll-1){
        bfsq.push(mxcells[i]);
        vis[mxcells[i].first][mxcells[i].second]=1;
        hour[mxcells[i].first][mxcells[i].second]=0;
    }
    int mxx=0;
    while(!bfsq.empty()){
        PII ff=bfsq.front();
        bfsq.pop();
        int curx=ff.first; int cury=ff.second;
        FREP(i,-1,1){
            FREP(j,-1,1){
                int nxtx=curx+i;
                int nxty=cury+j;
                if(ISVALID(nxtx,nxty,n,m) && !vis[nxtx][nxty]){
                    vis[nxtx][nxty]=1;
                    bfsq.push(make_pair(nxtx,nxty));
                    hour[nxtx][nxty]=hour[curx][cury]+1;
                }
            }
        }
    }
    FREP(i,1,n){
        FREP(j,1,m){
            mxx=max(mxx,hour[i][j]);
        }
    }
    return mxx;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int mxx=0;
        FREP(i,1,n){
            FREP(j,1,m){
                scanf("%d",&money[i][j]);
                mxx=max(money[i][j],mxx);
            }
        }
        init();
        findmaxcell(mxx,n,m);
        int ans=bfs(n,m);
        printf("%d\n",ans);
    }
    return 0;
}
