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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI dp[1003];
int vis[1003];

int arr[1003];

void init(){
    memset(vis,0,sizeof(vis));
}

LLI solve(int idx, int n){
    if(idx>n) return 0;
    if(vis[idx])return dp[idx];
    LLI s = 0;
    LLI res = 0;
    LLI mxx = -100000000000000000;
    FREP(i,idx,n){
        s = s+arr[i];
        res = s*(i-idx+1);
        LLI ret = solve(i+1,n);
        mxx = max(mxx,res+ret);
    }
    vis[idx]=1;
    return dp[idx] = mxx;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        int n;
        scanf("%d",&n);
        FREP(i,1,n){
            scanf("%d",&arr[i]);
        }
        LLI ans = solve(1,n);
        printf("%lld\n",ans);
    }
    return 0;
}
