//data structure--
//algo -- bigmod

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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;
//char s[1003];

LLI bigmod(LLI base, LLI raise, LLI md){
    if(raise==0)return 1;
    if(raise==1)return base;
    LLI div=raise/2;
    LLI ret=bigmod(base,div,md);
    if(raise%2){
        return (((ret*base)%md)*ret)%md;
    }
    else{
        return (ret*ret)%md;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        LLI N,A,B,K;
        scanf("%lld %lld  %lld %lld",&A,&B,&N,&K);
        int tot=0;
        FREP(i,1,N){
            FREP(j,1,N){
                if(i==j)continue;
                LLI reta=bigmod(i,A,K);
                LLI retb=bigmod(j,B,K);
                if((reta+retb)%K==0)tot++;
            }
        }
        tot=tot%1000000007;
        printf("Case #%d: %d\n",cs++,tot);
    }
    return 0;
}
