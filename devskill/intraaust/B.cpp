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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI dp[10][100006];

void solve(){
    memset(dp,0,sizeof(dp));
    FREP(dig,0,4){
        dp[dig][1]=1;
    }
    FREP(num_dig,0,100004){
        FREP(dig,0,4){
            int niche = dig-2;
            int upore = dig+2;
            if(niche>=0){
                dp[niche][num_dig+1]=dp[niche][num_dig+1]+dp[dig][num_dig];
                dp[niche][num_dig+1]%=MDD;
            }
            if(upore<=4){
                dp[upore][num_dig+1]=dp[upore][num_dig+1]+dp[dig][num_dig];
                dp[upore][num_dig+1]%=MDD;
            }
        }
    }
    FREP(num_dig,0,100004){
        LLI s = 0;
        FREP(dig,0,4){
            s+=dp[dig][num_dig];
            s%=MDD;
        }
        dp[6][num_dig]=s;
    }
}

int main(){
    solve();
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        int dig;
        scanf("%d",&dig);
        printf("%lld\n",dp[6][dig]);
    }
    return 0;
}
