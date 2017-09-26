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

char cc[4]={'D','I','M','A'};

int depth[1003][1003];
int vis[1003][1003];

char grid[1003][1003];
int changedgrid[1003][1003];

void init(int n, int m){
    memset(depth,-1,sizeof(depth));
    memset(vis,-1,sizeof(vis));
    FREP(i,0,(n-1)){
        FREP(j,0,(m-1)){
            FREP(k,0,3){
                if(grid[i][j]==cc[k]){
                    changedgrid[i][j]=k;
                }
            }
        }
    }
}

int dfs(int component, int curx, int cury, int cidx, int n, int m){
    //cout<<"at x: "<<curx<<" y: "<<cury<<"\n";
    vis[curx][cury]=component;
    if(depth[curx][cury]!=-1){
        //cout<<"from x: "<<curx<<" y: "<<cury<<"\n";cout<<"returning "<<depth[curx][cury]<<"\n";
        return depth[curx][cury];
    }
    int mxx=0;
    int need = (cidx+1)%4;
    for(int dx=-1;dx<=1;++dx){
        for(int dy=-1;dy<=1;++dy){
            if((dx && !dy) || (!dx && dy)){
                int nxtx = curx+dx; int nxty = cury+dy;
                if(ISVALID(nxtx,nxty,n,m) && changedgrid[nxtx][nxty]==need){
                    if(vis[nxtx][nxty]==component && depth[nxtx][nxty]==-1){
                       // cout<<"from x: "<<curx<<" y: "<<cury<<"\n";
                       // cout<<"returning inf\n";
                        return depth[curx][cury]=100000000;
                    }
                    else{
                        mxx = max(mxx,dfs(component,nxtx,nxty,need,n,m));
                    }
                }
            }
        }
    }
    depth[curx][cury]=mxx+1;
    //cout<<"from x: "<<curx<<" y: "<<cury<<"\n";
    //cout<<"returning "<<depth[curx][cury]<<"\n";
    return depth[curx][cury];
}

int solve(int n, int m){
    int comp = 1;
    FREP(i,0,(n-1)){
        FREP(j,0,(m-1)){
            if(changedgrid[i][j]==0 && vis[i][j]==-1){
                dfs(comp,i,j,0,n,m);
                comp++;
            }
        }
    }
    int mxx=-1;
    FREP(i,0,(n-1)){
        FREP(j,0,(m-1)){
            mxx = max(mxx,depth[i][j]/4);
        }
    }
    return mxx;
}

void print(int n, int m){
    FREP(i,0,(n-1)){FREP(j,0,(m-1))printf("%d ",changedgrid[i][j]);printf("\n");}
    FREP(i,0,(n-1)){FREP(j,0,(m-1))printf("%d ",depth[i][j]);printf("\n");}
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,0,(n-1))scanf("%s",grid[i]);
    init(n,m);
    int ans = solve(n,m);
    //print(n,m);
    if(ans==0)printf("Poor Dima!\n");
    else if(ans>(10000000))printf("Poor Inna!\n");
    else printf("%d\n",ans);
    return 0;
}
