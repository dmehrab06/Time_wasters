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

int dp[250005][505];
int diag[250005][505];

int coinval[505];

SI fin;

VI ans;
int ansl=0;

void init(){
    memset(dp,0,sizeof(dp));
    memset(diag,0,sizeof(diag));
    ansl=1;
    ans.PB(0);
}

void solve(int mxval, int n){
    dp[0][0]=1;
    FREP(i,1,n){
        FREP(j,0,mxval){
            dp[i][j]=dp[i-1][j];
        }
        FREP(j,0,mxval){
            int nxt=j+coinval[i];
            if(nxt<=mxval && dp[i-1][j]){
                dp[i][nxt]+=dp[i-1][j];
                diag[i][nxt]=coinval[i];
            }
        }
    }
    /*FREP(i,0,n){
        FREP(j,0,)
    }*/
}

void makesoln(int k, int n){
    if(n==0){
        FREP(i,0,(ansl-1)){
            fin.insert(ans[i]);
        }
        ans.clear();
        ansl=1;
        ans.PB(0);
        return;
    }
    //if(dp[n][k]!=0)ans.insert(k);
    if(diag[n][k]!=0 && dp[n][k]!=0){
        int dif=diag[n][k];
        int tmpansl=ansl;
        FREP(i,0,(tmpansl-1)){
            ans.PB(ans[i]+dif);
            ansl++;
        }
        makesoln(k-dif,n-1);
    }
    makesoln(k,n-1);
}


int main(){
    int n,k;
    scanf("%d %d",&n,&k);
   // int mxx=0;
    FREP(i,1,n){
        scanf("%d",&coinval[i]);
        //mxx+=coinval[i];
    }
    init();
    solve(k,n);
    printf("dptable\n");
    FREP(i,0,n){
        FREP(j,0,k){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("diagtable\n");
    FREP(i,0,n){
        FREP(j,0,k){
            printf("%d ",diag[i][j]);
        }
        printf("\n");
    }
    makesoln(k,n);
    SI::iterator it;
    printf("%d\n",(int)fin.size());
    for(it=fin.begin();it!=fin.end();++it){
        printf("%d ",*it);
    }
    printf("\n");

}

