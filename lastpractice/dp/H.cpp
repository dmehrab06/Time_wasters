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
#define PI acos(-1.0)
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI rowcumsum[55][55];
LLI colcumsum[55][55];

int grid[55][55];

LLI bob_dp[55][55][55][55];

void takeinp(int n, int m){
    FREP(i,1,n)FREP(j,1,m)scanf("%d",&grid[i][j]);
}

void calcrowcumsum(int rw, int n, int m){
    rowcumsum[rw][0]=0;
    FREP(i,1,m){
        rowcumsum[rw][i]=rowcumsum[rw][i-1]+grid[rw][i];
    }
}

void calccolcumsum(int col, int n, int m){
    colcumsum[0][col]=0;
    FREP(i,1,n){
        colcumsum[i][col]=colcumsum[i-1][col]+grid[i][col];
    }
}

void calccum(int n, int m){
    FREP(i,1,n)calcrowcumsum(i,n,m);
    FREP(i,1,m)calccolcumsum(i,n,m);

    /*FREP(i,1,n){
        FREP(j,1,m){
            cout<<rowcumsum[i][j]<<" ";
        }
        cout<<"\n";
    }

    FREP(i,1,n){
        FREP(j,1,m){
            cout<<colcumsum[i][j]<<" ";
        }
        cout<<"\n";
    }*/
}

LLI getrowrange(int rw, int l, int r){
    return rowcumsum[rw][r]-rowcumsum[rw][l-1];
}

LLI getcolrange(int col, int l, int r){
    return colcumsum[r][col]-colcumsum[l-1][col];
}

//int alice_solve(int lx, int rx, int ty, int by);

//int bob_solve(int lx, int rx, int ty, int by);

LLI bob_solve(int lx, int rx, int ty, int by, int n, int m){

    int tmplx = lx; int tmprx = rx;
    int tmpty = ty; int tmpby = by;

    if(lx>rx || ty>by)return (LLI)0;

    if(!ISVALID(lx,ty,n,m) || !ISVALID(rx,by,n,m))return (LLI)0;

    if(bob_dp[lx][rx][ty][by]!=-1)return bob_dp[lx][rx][ty][by];

    //alice's move
    //LLI oka = 1000000009;
    //cout<<lx<<" "<<rx<<" "<<ty<<" "<<by<<"\n";
    LLI a = getrowrange(lx,ty,by); LLI b = getrowrange(rx,ty,by);
    LLI c = getcolrange(ty,lx,rx); LLI d = getcolrange(by,lx,rx);

    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";

    LLI minalice = min(a,min(b,min(c,d)));

    //cout<<"alice takes "<<minalice<<"\n";

    //fixing bob

    if(minalice==a)lx++;
    else if(minalice==b)rx--;
    else if(minalice==c)ty++;
    else if(minalice==d)by--;

    //bob move start

    if(lx>rx || ty>by)return (LLI)0;

    if(!ISVALID(lx,ty,n,m) || !ISVALID(rx,by,n,m))return (LLI)0;

    LLI boba = getrowrange(lx,ty,by)+bob_solve(lx+1,rx,ty,by,n,m);
    LLI bobb = getrowrange(rx,ty,by)+bob_solve(lx,rx-1,ty,by,n,m);
    LLI bobc = getcolrange(ty,lx,rx)+bob_solve(lx,rx,ty+1,by,n,m);
    LLI bobd = getcolrange(by,lx,rx)+bob_solve(lx,rx,ty,by-1,n,m);

    LLI bobtakes = max(boba,max(bobb,max(bobc,bobd)));

    //cout<<"bob takes "<<bobtakes<<"\n";

    return bob_dp[tmplx][tmprx][tmpty][tmpby]=bobtakes;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        memset(bob_dp,-1,sizeof(bob_dp));
        LLI ss = 0;
        scanf("%d %d",&n,&m);
        FREP(i,1,n){
            FREP(j,1,m){
                scanf("%d",&grid[i][j]);
                ss+=grid[i][j];
            }
        }
        calccum(n,m);
        LLI ans1 = bob_solve(1,n,1,m,n,m);
        LLI ans2 = ss-ans1;
        if(ans1==ans2){
            printf("%lld\n",ss);
        }
        else{
            printf("%lld\n",max(ans2,ans1));
        }
        //printf("%lld\n",ans2);
    }
    return 0;
}
