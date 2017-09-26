/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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




int dp[51][51][2505];
struct point{
    int first,second;
};
point v[55];

bool cmp(point a , point b)
{
    return a.second*b.first>a.first*b.second;
}

int n,m;

int solve(int i, int j, int k){
   // if((n-i+1)<(m-j))return -10000000000;
    if(j==m)return 0;
    if(i>n)return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int ret1=solve(i+1,j+1,k+v[i].second)+((2*k+v[i].second)*v[i].first);
    int ret2=solve(i+1,j,k);
    dp[i][j][k]=max(ret1,ret2);
    return dp[i][j][k];
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        scanf("%d %d",&n,&m);
        FREP(i,1,n){
            scanf("%d %d",&v[i].first,&v[i].second);
        }
        sort(v+1,v+1+n,cmp);
        /*FREP(i,1,n){
            printf("%d %d\n",v[i].first,v[i].second);
        }*/
        memset(dp,-1,sizeof(dp));
        int ans=solve(1,0,0);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}

