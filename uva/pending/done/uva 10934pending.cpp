#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 2000000005
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
using namespace std;

LLI dp[103][70];

void init(){
    FREP(i,0,100)FREP(j,0,69)dp[i][j]=-1;
}

LLI solve(int b,int left){
    if(left==1)return dp[b][left]=1;
    if(b==1)return dp[b][left]=left;
    if(dp[b][left]!=-1){
       return dp[b][left];
    }
    else{
        dp[b][left]=(1+solve(b-1, left-1))+solve(b,left-1);
    }
    return dp[b][left];
}

int bs(LLI tall, int balloon){

    if(dp[balloon][1]>=tall){
        return 1;
    }
    if(dp[balloon][63]<tall){
        return -1;
    }
    int l=1;
    int h=63;
    while(true){
        int mid=(l+h)/2;
        if(dp[balloon][mid]>=tall){
            if((mid>1) && dp[balloon][mid-1]>=tall){
                h=mid;
            }
            else{
                return mid;
            }
        }
        else{
            l=mid+1;
        }
    }
}

int main()
{
    int b;
    LLI tall;
    while(scanf("%d %lld",&b,&tall)==2){
        if(b==0)break;
        init();
        solve(b,69);

        int ans=bs(tall,b);
        if(b==1){
            if(tall<=63){
                ans=tall;
            }
        }
        if(ans==-1){
            printf("More than 63 trials needed.\n");
        }
        else{
            printf("%d\n",ans);
        }
    }
    return 0;
}


