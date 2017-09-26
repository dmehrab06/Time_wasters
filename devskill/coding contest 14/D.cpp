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
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

unsigned LLI dp[45];
int vis[45];

LLI arr[45];

int n;
LLI maxs;

void init(){
    memset(vis,-1,sizeof(vis));
}

unsigned LLI solve(int cur){
    if(cur>n)return 0;
    if(vis[cur]!=-1)return dp[cur];
    unsigned LLI ret1,ret2;
    ret1=arr[cur]+solve(cur+1);
    ret2=solve(cur+1);
    if(ret1>(unsigned LLI)maxs)ret1=0;
    if(ret2>(unsigned LLI)maxs)ret2=0;
    vis[cur]=1;
    return dp[cur]=max(ret1,ret2);
}

int main(){
    int t;
    int cs=1;
    scanf("%d",&t);
    while(t--){
        LLI D;
        cin>>n>>maxs>>D;
        init();
        FREP(i,1,n){
            cin>>arr[i];
        }
        LLI ans=solve(n);
        cout<<ans<<"\n";
        if(ans==D){
            printf("oka\n");
        }
        else{
            printf("not oka\n");
        }
    }
    return 0;
}
