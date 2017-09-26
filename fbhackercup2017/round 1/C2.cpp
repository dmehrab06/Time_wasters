/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define ULLI unsigned long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.00000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

int dis[103][103];

int src[5003];
int des[5003];

LLI dp[5003][4][4];

int nopeflag;

LLI solve2(int curidx, int curload, int curat, int family){
    //cout<<"at "<<curidx<<","<<curload<<","<<curat<<"\n";
    if(curidx>family){
        return 0;
    }
    if(curidx==family && curload==0)return 0;
    if(dp[curidx][curload][curat]!=-1)return dp[curidx][curload][curat];
    if(curat==1){
        if(dp[curidx][curload][curat]!=-1){
            return dp[curidx][curload][curat];
        }
        if(curload==1){
            int curnode=src[curidx];
            LLI ret1=MXX, ret2=MXX;
            ret1=(LLI)dis[curnode][des[curidx]]+solve2(curidx,curload-1,2,family);
            if(dis[curnode][des[curidx]]>=MXX){
                nopeflag=1;
            }
            if(curidx<family){
                ret2=(LLI)dis[curnode][src[curidx+1]]+solve2(curidx+1,curload+1,1,family);
                if(dis[curnode][src[curidx+1]]>=MXX)nopeflag=1;
            }
            return dp[curidx][curload][curat]=min(ret1,ret2);
        }
        else if(curload==2){
            int curnode=src[curidx];
            LLI ret1=MXX;
            ret1=(LLI)dis[curnode][des[curidx-1]]+solve2(curidx-1,curload-1,2,family);
            if(dis[curnode][des[curidx+1]]>=MXX)nopeflag=1;
            return dp[curidx][curload][curat]=ret1;
        }
    }
    else if(curat==2){
        if(dp[curidx][curload][curat]!=-1){
            return dp[curidx][curload][curat];
        }
        if(curload==1){
            int curnode=des[curidx];
            LLI ret1=MXX, ret2=MXX;
            ret1=(LLI)dis[curnode][des[curidx+1]]+solve2(curidx+1,curload-1,2,family);
            if(dis[curnode][des[curidx+1]]>=MXX){
                nopeflag=1;
            }
            if((curidx+2)<=family){
                ret2=(LLI)dis[curnode][src[curidx+2]]+solve2(curidx+2,curload+1,1,family);
                if(dis[curnode][src[curidx+2]]>=MXX)nopeflag=1;
            }
            return dp[curidx][curload][curat]=min(ret1,ret2);
        }
        else if(curload==0){
            if(curidx==family)return 0;
            int curnode=des[curidx];
            LLI ret1=MXX;
            ret1=(LLI)dis[curnode][src[curidx+1]]+solve2(curidx+1,curload+1,1,family);
            if(dis[curnode][src[curidx+1]]>=MXX)nopeflag=1;
            return dp[curidx][curload][curat]=ret1;
        }
    }
}


void takeg(int n, int m, int family){
    nopeflag=0;
    memset(dp,-1,sizeof(dp));
    FREP(i,1,n){
        FREP(j,1,n){
            if(i==j){
                dis[i][j]=0;
            }
            else{
                dis[i][j]=MXX;
            }
        }
    }

    FREP(i,1,m){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        dis[u][v]=min(dis[u][v],w);
        dis[v][u]=min(dis[v][u],w);
    }

    FREP(i,1,family){
        scanf("%d %d",&src[i],&des[i]);
    }
}

void floyd(int n){
    FREP(k,1,n){
        FREP(i,1,n){
            FREP(j,1,n){
                if((dis[i][k]+dis[k][j])<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        takeg(n,m,k);
        floyd(n);
        LLI ans=(LLI)dis[1][src[1]]+solve2(1,1,1,k);
        if(nopeflag==1){
            ans=-1;
        }
        printf("Case #%d: %lld\n",cs++,ans);
    }
    return 0;
}
