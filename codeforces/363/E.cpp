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

double dp[(1<<20)+10];
double prob[25];
double ans[25];

int cntbits(int n){
    int msk=1;
    int cnt=0;
    while(n){
        if(n&msk)cnt++;
        n>>=1;
    }
    return cnt;
}

int setbit(int n, int i){return (n|(1<<i));}
bool isset(int n, int i){return (n&(1<<i));}
void init(){
    FREP(i,0,24)ans[i]=0.0;
    dp[0]=1.0; //this is the random states before the last k distinct states
    //we of course will reach this state, hence 1
    FREP(i,1,(1<<20))dp[i]=0.0;
}
void solve(int n, int k){
    FREP(i,0,((1<<n)-1)){
        if(cntbits(i)==k){ //if k bits set, found the k distinct elements, no need to look further
            FREP(j,0,(n-1)){ //contribute to result for all the element present in the cache
                if(isset(i,j)){
                    ans[j+1]+=dp[i];
                }
            }
        }
        else if(cntbits(i)<k){ //else we havent found the last k elements yet
            double cancome=0.0; //je element gula nai seigular je konota aste pare
            FREP(j,0,(n-1)){ //cancome 0 hobe na seita main funct e ensure kore asbo
                if(!isset(i,j)){
                    cancome+=prob[j+1];
                }
            }
            FREP(j,0,(n-1)){
                if(!isset(i,j)){
                    int nxt=setbit(i,j);
                    dp[nxt]+=dp[i]*(prob[j+1]/cancome); //jeita asbe seitar prob nitesi
                }
            }
        }
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int hasprob=0;
    FREP(i,1,n){
        scanf("%lf",&prob[i]);
        if(prob[i]>eps)hasprob++;
    }
    if(hasprob<=k){
        FREP(i,1,n){
            if(prob[i]>eps)printf("1.0 ");
            else{
                printf("0.0 ");
            }
        }
        printf("\n");
        return 0;
    }
    init();
    solve(n,k);
    FREP(i,1,n){
        printf("%.8lf ",ans[i]);
    }
    printf("\n");
    return 0;
}
