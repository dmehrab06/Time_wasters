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

int vis[103][103];

char grid[103][103];

void  init(){
    memset(vis,-1,sizeof(vis));
}

int bfs(int startx, int starty, int edx, int edy, int r, int c){
    queue<pair<int,int>>q;
    pair<int,int>src=make_pair(startx,starty);
    q.push(src);
    vis[startx][starty]=0;
    while(!q.empty()){
        PII cur=q.front();
        q.pop();
        if(cur.first==edx && cur.second==edy){
            return vis[edx][edy];
        }
        FREP(x,-1,1){
            FREP(y,-1,1){
                if((x==0 || y==0) && !(x==0 && y==0)){
                    int nxtx=cur.first+x;
                    int nxty=cur.second+y;
                    if(vis[nxtx][nxty]!=-1){
                        continue;
                    }
                    else if(grid[nxtx][nxty]=='#'){
                        continue;
                    }
                    else if(!ISVALID(nxtx,nxty,r,c)){
                        continue;
                    }
                    else{
                        vis[nxtx][nxty]=vis[cur.first][cur.second]+1;
                        q.push(make_pair(nxtx,nxty));
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(i,1,t){
        int n,k;
        scanf("%d %d",&n,&k);
        int startfrom=(n-k+1);
        printf("Case %d: ",i);
        if(k>n){
            printf("0\n");
            continue;
        }
        LLI s=1;
        FREP(j,startfrom,n){
            s=s*j;
            s%=1000000007;
        }
        printf("%lld\n",s);
    }
    return 0;
}
