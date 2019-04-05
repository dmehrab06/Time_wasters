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
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int taken[33003];
int dp[33003][105];
int totarea;


int need[15];

int  bitcount( int  x) {
    if (x == 0)return  0;
    return  bitcount(x>>1)+(x&1);
}

void printmask(int m,int n){
    for(int i=0;i<n;++i)if(m&(1<<i))printf("%d,",i);
    printf("\n");
}

void pre(int n){
    //MSET(taken,0);
    for(int i = 0; i<(1<<n); ++i){
        taken[i] = 0;
        for(int j = 0; j<n; ++j){
            if(i&(1<<j)){
                taken[i]+=need[j];
            }
        }
    }
}

int solve(int mask, int w, int n){
    //cout<<mask<<"\n";
    int need = taken[mask];
    if(need%w)return 0;
    int h = need/w;
    if(__builtin_popcount(mask)==1)return 1;
    if(dp[mask][w]!=-1)return dp[mask][w];

    int flag = 0;

    for(int spl1 = (mask-1)&mask; spl1>0; spl1 = (spl1-1) & mask){
        //if(spl1==mask)continue;
        int spl2 = mask^spl1;
        //if(spl1>spl2)continue;
        //cout<<part1<<" will satisfy ";
        //printmask(part1,n);
        //cout<<part2<<" will satisfy ";
        //printmask(part2,n);
        if(taken[spl1]%w==0 && taken[spl2]%w==0){
            flag = flag | (solve(spl1,w,n) & solve(spl2,w,n));
        }
        if(taken[spl1]%h==0 && taken[spl2]%h==0){
            flag = flag | (solve(spl1,taken[spl1]/h,n) & solve(spl2,taken[spl2]/h,n));
        }
    }
    return dp[mask][w] = flag;
}

int main(){
    int n;
    int cs = 1;
    while(scanf("%d",&n)==1){
        if(n==0)break;
        int width, height;
        scanf("%d %d",&width,&height);
        totarea = width*height;
        int tt = 0;
        FREP(i,0,(n-1)){
            scanf("%d",&need[i]);
            tt+=need[i];
        }
        if(totarea!=tt){
            printf("Case %d: No\n",cs++);
            continue;
        }
        pre(n);
        MSET(dp,-1);
        int ans = solve((1<<n)-1,height,n);
        printf("Case %d: ",cs++);
        if(ans)printf("Yes\n");
        else printf("No\n");
        //FREP(i,0,(1<<n)-1){
            //printf("dp[%d] =  %d\n",i,)
        //}
    }
    return 0;
}
