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

double dp[64003];
PII houses[16];
char member[23];

void init(){
    MSET(dp,-1);
    FREP(i,0,30000)cout<<dp[i]<<"\n";
}

double sq(double d){
    return d*d;
}

double dis(int i, int j){
    PII ii = houses[i];
    PII jj = houses[j];
    return sqrt(sq(ii.first-jj.first)+sq(ii.second-jj.second));
}

int solve(int mask, int n){
    if(mask == ((1<<n)-1))return 0.0;
    if(dp[mask]>(-1.0))return dp[mask];
    double mnn = 1000000000000000000.00;
    FREP(i,0,(n-1)){
        if(!(mask & (1<<i))){
            FREP(j,0,(n-1)){
                if(!(mask & (1<<j))){
                    int newmask = mask | (1<<i);
                    newmask = newmask | (1<<j);
                    double dis = dis(i,j);
                    mnn = min(mnn,dis+solve(newmask,n));
                }
            }
        }
    }
    return dp[mask] = mnn;
}

int main(){
    int n;
    int cs = 1;
    while(scanf("%d",&n)==1){
        init();
        FREP(i,0,(n-1)){
            scanf("%s %d %d",member,&houses[i].first,&houses[i].second);
        }
        double ans = solve(0,n);
        printf("Case %d: %.2lf\n",cs++,ans);
    }
    return 0;
}
