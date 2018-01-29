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

int seg

void init(){
    FREP(i,0,102){
        pows[i][0]=1;
        FREP(j,1,31){
            pows[i][j]=pows[i][j-1]*i;
            if(pows[i][j]>10000)break;
            limit[i] = j;
        }
    }
    memset(dp,-1,sizeof(dp));
}

int solve(int n, int pwidx, int m){
    if(pwidx==0){
        if(n>=0)return dp[n][pwidx][m] = 1;
        else return dp[n][pwidx][m] = 0;
    }
    if(dp[n][pwidx][m]!=-1)return dp[n][pwidx][m];
    int ret1 = 0, ret2 = 0;
    if(pows[m][pwidx]<=n)ret1 = solve(n-pows[m][pwidx],pwidx,m);
    ret2 = solve(n,pwidx-1,m);
    return dp[n][pwidx][m]=ret1+ret2;
}

int main(){
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        int cs,m,n;
        scanf("%d %d %d",&cs,&m,&n);
        int ans = solve(n,limit[m],m);
        printf("%d %d\n",cs,ans);
    }
    return 0;
}
