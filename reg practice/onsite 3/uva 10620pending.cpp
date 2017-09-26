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
#define MDD 2000000011
using namespace std;

int MXATTEMPT=50000;

bool valid(LLI x, LLI y, LLI unit){
    LLI vuj=x/unit;
    LLI koti=y/unit;
    if((x%unit)==0 || (y%unit)==0)return false;
    return (vuj+koti)%2;
}

int main(){
    LLI S,x,y,dx,dy;
    while(scanf("%lld %lld %lld %lld %lld",&S,&x,&y,&dx,&dy)==5){
        if(S==0)break;
        int did=0;
        int f=0;
        while(did<=MXATTEMPT){
            if(valid(x,y,S)){
                f=1;
                break;
            }
            did++;
            x+=dx;
            y+=dy;
        }
        if(f){
            printf("After %d jumps the flea lands at (%lld, %lld).",did,x,y);
        }
        else{
            printf("The flea cannot escape from black squares.\n");
        }
    }
    return 0;
}
