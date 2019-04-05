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

double dp[503][503]; //dp[j][i] = prob of having <=j streak in i games

double pwpr[503];
double revpwpr[503];

void dopow(double p){
    pwpr[0] = 1.0;
    revpwpr[0] = 1.0;
    FREP(i,1,501){
        pwpr[i] = pwpr[i-1]*p;
        revpwpr[i] = revpwpr[i-1]*(1.0-p);
    }
}

double solve(int winstreak, int game,double p){
    if(winstreak>=game)return dp[winstreak][game] = 1.0;
    if(winstreak==(game-1))return dp[winstreak][game] = (1.0-pwpr[game]);
    if(winstreak==0)return dp[winstreak][game] = revpwpr[game];
    if(dp[winstreak][game]>(-1.0)){
        return dp[winstreak][game];
    }
    double extra = solve(winstreak,game-winstreak-2,p)*(1.0-p)*pwpr[winstreak+1];
    return dp[winstreak][game] = solve(winstreak,game-1,p)-extra;
}

int main(){
    int n; double p;
    while(scanf("%d %lf",&n,&p)==2){
        if(n==0)break;
        FREP(i,1,(n+1))FREP(j,1,(n+1))dp[i][j] = -1.0;
        dopow(p);
        FREP(i,0,n){
            solve(i,n,p);
        }
        /*FREP(i,1,n){
            FREP(j,1,n){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        double ans = 0.0;
        FREP(win,1,n){
            ans = ans+win*(dp[win][n]-dp[win-1][n]);
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}
