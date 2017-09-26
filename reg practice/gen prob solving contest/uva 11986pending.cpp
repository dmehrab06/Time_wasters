#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 2000000005
#define MNN -MXX
#define DBL double
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
using namespace std;

LLI twopow[67];

void init(){
    twopow[0]=1;
    FREP(i,1,66){
        twopow[i]=twopow[i-1]*2;
    }
}

int bs(LLI x){
    if(x==1)return 0;
    int l=0;
    int h=66;
    while(true){
        int m=(l+h)/2;
        if(twopow[m]>=x){
            if(twopow[m-1]<x){
                return m;
            }
            else{
                h=m;
            }
        }
        else{
            l=m+1;
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    init();
    while(t--){
        LLI a;
        scanf("%lld",&a);
        int ans=bs(a+1);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
