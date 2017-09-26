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

LLI MDD=10000000000007;

LLI npr[10005][10005];

LLI solve(int n, int r){
    if(r>n)return npr[n][r]=0;
    if(r==0)return npr[n][r]=1;
    if(r==1)return npr[n][r]=n;
    if(npr[n][r]!=-1)return npr[n][r];
    LLI ret1=solve(n-1,r);
    LLI ret2=solve(n-1,r-1);
    ret2=ret2*r;
    ret2%=MDD;
    ret1=(ret1+ret2)%MDD;
    return npr[n][r]=ret1;
}

void init(){
    memset(npr,-1,sizeof(npr));
}

int main(){
    init();
    RFREP(i,10000,1){
        RFREP(j,i,0){
            if(npr[i][j]==-1)solve(i,j);
        }
    }
    //solve(10000,10000);
    FREP(i,1,10000){
        FREP(j,1,i){
            npr[i][j]=npr[i][j]+npr[i][j-1];
            npr[i][j]%=MDD;
        }
    }
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int L,Min,Max;
        scanf("%d %d %d",&L,&Min,&Max);
        int N=L*L;
        LLI ans=npr[N][Max]-npr[N][Min-1];
        if(ans<0)ans+=MDD;
        printf("Case %d: %lld\n",cs++,ans);
    }

    return 0;
}
