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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI arr[300005];
int b[203];
int M;
LLI cumsum[300005];


LLI dp[300005][203];
bool vis[300005][203];

void init(int n){
    cumsum[0]=0;
    b[0]=n;
    FREP(i,1,n){
        cumsum[i]=cumsum[i-1]+arr[i];
    }
    FREP(i,0,300004)FREP(j,0,202)vis[i][j]=false;
}

LLI solve(int l, int turn){
    if(turn>M){
        return 0;
    }
    if(vis[l][turn]){
        return dp[l][turn];
    }
    int r=l+b[turn-1]-1;
    int lastl=r-b[turn]+1;
    if(turn%2){
        LLI ret=0;
        FREP(i,l,lastl){
            int rr=i+b[turn]-1;
            LLI sm=cumsum[rr]-cumsum[i-1];
            cout<<"cumsum from "<<i<<" to "<<rr<<" is "<<sm<<"\n";
            ret=max(ret,sm+solve(i,turn+1));
            cout<<"at turn "<<turn<<" choosing from "<<i<<" to "<<rr<<" got "<<ret<<"\n";
        }
        vis[l][turn]=true;
        return dp[l][turn]=ret;
    }
    else{
        LLI ret=1000000000000000000;
        FREP(i,l,lastl){
            int rr=i+b[turn]-1;
            LLI sm=cumsum[rr]-cumsum[i-1];
            cout<<"cumsum from "<<i<<" to "<<rr<<" is "<<sm<<"\n";
            ret=min(ret,solve(i,turn+1)-sm);
            cout<<"at turn "<<turn<<" choosing from "<<i<<" to "<<rr<<" got "<<ret<<"\n";
        }
        vis[l][turn]=true;
        return dp[l][turn]=ret;
    }
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d %d",&n,&M);
        FREP(i,1,n){
            scanf("%lld",&arr[i]);
        }
        FREP(i,1,M){
            scanf("%d",&b[i]);
        }
        init(n);
        LLI ans=solve(1,1);
        printf("%lld\n",ans);
    }
    return 0;
}
