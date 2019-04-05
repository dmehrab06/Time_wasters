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

LLI dp[1003][1003];
LLI allval[1003];



void precalcor(int n){
    FREP(i,1,n){
        allval[i] = allval[i]+allval[i-1];
    }
}

LLI cost(int l, int r){
    return allval[r]-allval[l-1];
}

void div_conq(int seg, int l, int r, int ans1, int ans2){
    //finding dp[g][(l+r)/2] when i know that dp_partition lies between ans1 and ans2
    if(l>r)return;

    int mid = l+(r-l)/2;
    dp[seg][mid] = 100000000000000;
    int parti = -1;
    FREP(k,ans1,min(mid,ans2)){
        LLI val = max(dp[seg-1][k],cost(k+1,mid));
        if(val<dp[seg][mid]){
            dp[seg][mid] = val;
            //dp_partition[seg][mid] = k;
            parti = k;
        }
    }
    div_conq(seg,l,mid-1,ans1,parti);
    div_conq(seg,mid+1,r,parti,ans2);
}

void solve(int gg, int n){
    //MSET(dp_partition,-1);
    FREP(i,0,n)dp[1][i] = cost(1,i);
    FREP(g,2,gg)div_conq(g,1,n,1,n);
}

void printdp(int k, int n){
    //FREP(i,1,k)FREP(j,1,n)printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
}

/*void printfamiliar(int n){
    FREP(i,1,n){
        FREP(j,1,n){
            printf("%d ",familiarval[i][j]);
        }
        printf("\n");
    }
}*/


int main(){
    int t;
    scanf("%d",&t);

    FREP(cs,1,t){
        int K,N;
        scanf("%d%d\n",&N,&K);
        FREP(i,1,N){
            scanf("%lld",&allval[i]);
        }
        precalcor(N);
        solve(K,N);
        printf("%lld\n",dp[K][N]);
    }
    return 0;
}
