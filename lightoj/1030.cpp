#include<bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define XX first
#define YY second
using namespace std;

int gold[103];

double dp[103];
int n;
void init(int n){
    FREP(i,0,n)dp[i]=-1.0;
}

double solve(int asi){
    if(asi==n){
        return dp[asi]=(double)gold[asi];
    }
    if(dp[asi]>0.0)return dp[asi];
    int baki=n-asi;
    double prob=max(1.0/(double)baki,1.0/6.0);
    double nw=gold[asi];
    for(int i=asi+1;i<=min(asi+6,n);++i){
        nw=nw+prob*solve(i);
    }
    return dp[asi]=nw;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        scanf("%d",&n);
        init(n);
        FREP(i,1,n){
            scanf("%d",&gold[i]);
        }
        double ans=solve(1);
        printf("Case %d: %.8lf\n",cs++,ans);
    }
    return 0;
}
