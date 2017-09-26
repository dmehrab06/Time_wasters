#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
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

LLI mat[3003][3003];
LLI dpmat[3003][3003];



void calc(int R, int C){
    FREP(i,0,(R-1)){
        FREP(j,0,(C-1)){
            LLI ret1=VALID(i-1,j,R,C)?dpmat[i-1][j]:0;
            LLI ret2=VALID(i,j-1,R,C)?dpmat[i][j-1]:0;
            LLI ret3=VALID(i-1,j-1,R,C)?dpmat[i-1][j-1]:0;
            dpmat[i][j]=ret1+ret2+mat[i][j]-ret3;
        }
    }
}

LLI getsum(int lx, int ly, int rx, int ry, int R, int C){
    LLI ret1=dpmat[rx][ry];
    LLI ret2=VALID(lx-1,ry,R,C)?dpmat[lx-1][ry]:0;
    LLI ret3=VALID(rx,ly-1,R,C)?dpmat[rx][ly-1]:0;
    LLI ret4=VALID(lx-1,ly-1,R,C)?dpmat[lx-1][ly-1]:0;
    return ret1-ret2-ret3+ret4;
}



int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
    int R,C,K;
    scanf("%d %d %d",&R,&C,&K);
   // FREP(i,0,(R-1))FREP(j,0,(C-1))scanf("%lld",&mat[i][j]);
   FREP(i,1,K){
    int r,c;
    scanf("%d %d",&r,&c);
    mat[r][c]=1;
   }
    calc(R,C);
    LLI total=0;
    int mx=min(R,C);
    FREP(sq,1,mx){
        FREP(i,0,(R-1)){
            FREP(j,0,(C-1)){
                if(VALID(i+sq,j+sq,R,C)){
                    LLI ret=getsum(i,j,i+sq,j+sq,R,C);
                    if(ret==0){
                        total++;
                    }
                }
            }
        }
    }
    printf("Case #%d: %lld\n",cs++,total);
    }
   return 0;
}
