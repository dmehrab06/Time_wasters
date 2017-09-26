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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int topx=200, topy=200;
int botx=-1, boty=-1;
int lftx=200, lfty=200;
int rgtx=-1, rgty=-1;

char grid[105][105];

void setparams(int n, int m){
    FREP(i,0,n-1){
        FREP(j,0,m-1){
            if(grid[i][j]=='B'){
                if(i>rgtx){
                    rgtx = i; rgty = j;
                }
                if(i<lftx){
                    lftx = i; lfty = j;
                }
                if(j<topy){
                    topx = i; topy = j;
                }
                if(j>boty){
                    botx = i; boty = j;
                }
            }
        }
    }
}

void solve(int n, int m){
    if((topy>boty) && (lftx>rgtx)){
        printf("1\n");
        return;
    }
    else{
        int ht = boty-topy+1; int wd = rgtx-lftx+1;
        if(ht>wd){
      //      cout<<"ekhane1\n";
            int cnt = 0;
            FREP(i,lftx,rgtx){
                FREP(j,topy,boty){
                    if(grid[i][j]=='W'){
                        grid[i][j]='B';
                        cnt++;
                    }
                }
            }
            int needmore = ht-(rgtx-lftx+1);
            int lft = lftx; int rgt = rgtx;
            while(needmore>0){
                if(!INRANGEI(lft-1,0,(n-1)) && !INRANGEI(rgt+1,0,(n-1))){
                    printf("-1\n");
                    return;
                }
                else{
                    if(INRANGEI(lft-1,0,(n-1))){
                        lft--;
                    }
                    else{
                        rgt++;
                    }
                    needmore--;
                    cnt+=(topy-boty+1);
                }
            }
            printf("%d\n",cnt);
        }
        else{
        //    cout<<"ekhane2\n";
            int cnt = 0;
            FREP(i,lftx,rgtx){
                FREP(j,topy,boty){
                    if(grid[i][j]=='W'){
                        grid[i][j]='B';
                        cnt++;
                    }
                }
            }
            int needmore = wd-(boty-topy+1);
            int tp = topy; int bot = boty;
            while(needmore>0){
                if(!INRANGEI(tp-1,0,(m-1)) && !INRANGEI(bot+1,0,(m-1))){
                    printf("-1\n");
                    return;
                }
                else{
                    if(INRANGEI(tp-1,0,(n-1))){
                        tp--;
                    }
                    else{
                        bot++;
                    }
                    needmore--;
                    cnt+=(rgtx-lftx+1);
                }
            }
            printf("%d\n",cnt);
        }
        //printf("%d\n",cnt);
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,0,(n-1)){
        scanf("%s",grid[i]);
    }
    setparams(n,m);
    solve(n,m);
    return 0;
}
