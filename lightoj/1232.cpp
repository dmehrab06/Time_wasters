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

int dp[10003][103];
int arr[103];

void init(){MSET(dp,-1);}

int solve(int val, int idx, int n, int k){
    if(idx>n && val==0)return 1;
    if(idx>n)return 0;
    if(dp[val][idx]!=-1)return dp[val][idx];
    int curval = 0;
    int used = 0;
    int ret = 0;
    while(curval<=val && used<=k){
        ret+=solve(val-curval,idx+1,n,k);
        ret%=1000000007;
        used++;
        curval+=arr[idx];
    }
    return dp[val][idx] = ret;
}


int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int n,k;
        scanf("%d %d",&n,&k);
        FREP(i,1,n)scanf("%d",&arr[i]);
        init();
        int ans = solve(k,1,n,k);
        printf("Case %d: %d\n",cs,ans);
    }
}
