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

//string poly;

int dp[16][33000];
int coinval[16];
int bills[16];

void init(){
    MSET(dp,-1);
}

int cnt(int mask, int coins){
    int msk = 1; int c = 0;
    FREP(i,0,coins-1){
        if(mask&msk)c++;
        msk<<=1;
    }
    return c;
}

int cntcoinval(int mask, int coins){
    int msk = 1; int c = 0;
    FREP(i,0,coins-1){
        if(mask&msk)c+=coinval[i+1];
        msk<<=1;
    }
    return c;
}

int solve(int idx, int mask, int shop, int coins){

    if(idx>shop)return cnt(mask,coins);

    if(dp[idx][mask]!=-1)return dp[idx][mask];

    int ret = 10000000;

    int tot = 0;
    FREP(i,1,idx)tot+=bills[i];

    int has = cntcoinval(mask,coins);
    int need = tot-has;

    if(need==0)ret = min(ret,solve(idx+1,mask,shop,coins));

    else{
        FREP(i,0,coins-1){
            if(!(mask&(1<<i))){ //coin not used yet
                if(coinval[i+1]<=need){
                    int newmask = (mask | (1<<i));
                    ret = min(ret,solve(idx,newmask,shop,coins));
                }
            }
        }
    }

    return dp[idx][mask] = ret;

}

int main(){
    int t;
    scanf("%d",&t);
    int cs = 1;
    while(t--){
        int coins; scanf("%d",&coins);
        FREP(i,1,coins)scanf("%d",&coinval[i]);
        int shops; scanf("%d",&shops);
        FREP(i,1,shops)scanf("%d",&bills[i]);
        init();
        int ans = solve(1,0,shops,coins);
        if(ans>coins)printf("Case %d: -1\n",cs++);
        else printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
