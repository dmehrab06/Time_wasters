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

LLI cnt[30000003];

LLI twopow[32];

void init(){
    twopow[0]=1;
    FREP(i,1,31){
        twopow[i]=twopow[i-1]*2;
    }
    LLI curminB=1;
    int curminbidx=0;
    FREP(i,1,30000000){
        LLI A=i;
        if(A==twopow[curminbidx+1]){
            curminbidx++;
            curminB=twopow[curminbidx];
        }
        for(LLI j=curminB;j<=A;j++){
            if((A-j)==(A^j))cnt[A]++;
        }
    }
    FREP(i,2,30000000){
        cnt[i]+=cnt[i-1];
    }
}

int main(){
    init();
    return 0;
}
