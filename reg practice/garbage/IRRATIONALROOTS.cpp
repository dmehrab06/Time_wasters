#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000000000005
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


LLI poly[21][21];
int N;

void slopcalc(){
    int prevsize=N;
    //int nxtsize=N-1;
    int nxt=1;
    while(prevsize){
        LLI pw=1;
        FREP(i,1,prevsize){
            poly[nxt][i-1]=pw*poly[nxt-1][i];
            pw=pw+1;
        }
        nxt++;
        prevsize--;
    }
    return;
}

int solve(LLI root){
    int cnt=0;
    LLI sum;
    int dif=0;
    int sz=N;
    do{
        cnt++;
        sum=0;
        LLI x=1;
        FREP(i,0,sz){
            sum=sum+(poly[dif][i]*x);
            x=x*root;
        }
        sz--;
        dif++;
    }while(sum==0);

    return cnt-1;
}

int main(){
    while(scanf("%d",&N)==1){
        int soln=N;
        FREP(i,0,(N-1)){
            scanf("%lld",&poly[0][N-i-1]);
        }
        poly[0][N]=1;
        //int totcn=divisorcn(poly[N-1]);
        int rational=0;
        slopcalc();
        FREP(cur,-10,10){
            rational+=solve((LLI)cur);
           // rational+=solve((LLI)(-cur));
        }
        printf("%d\n",soln-rational);
    }
    return 0;
}
