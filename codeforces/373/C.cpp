#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000009
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
using namespace std;

int alldig[200006];
LLI mintimetomake5[200006];
LLI mintimetoinc[200006];
char dig[200006];

void init(){
    FREP(i,0,200005){
        mintimetoinc[i]=MXX;
        mintimetomake5[i]=MXX;
        alldig[i]=0;
    }
}
int main(){
    int N,t;
    scanf("%d %d",&N,&t);
    scanf("%s",dig);
    init();
    alldig[0]=0;
    int decat;
    FREP(i,0,(N-1)){
        if(dig[i]=='.'){
            alldig[i+1]=-1;
            decat=i+1;
        }
        else{
            alldig[i+1]=dig[i]-'0';
        }
    }
    RFREP(i,N,(decat+1)){
        if(alldig[i]>=5){
            mintimetomake5[i]=0;
        }
        else{
            if(alldig[i]==4)mintimetomake5[i]=mintimetomake5[i+1]+1;
        }
    }
    RFREP(i,N,(decat)){
        if(alldig[i+1]>=5){
            mintimetoinc[i]=1;
        }
        else{
            mintimetoinc[i]=min(mintimetomake5[i+1]+1,mintimetoinc[i]);
        }
    }
    int first=-1;
    FREP(i,decat,N){
        if(mintimetoinc[i]<=t){
            first=i;
            break;
        }
    }
    if(first==-1){
        //no change possible
        int printflag=0;
        FREP(i,1,(N)){
            if(alldig[i]==-1){
                if(printflag==0)printf("0");
                printf(".");
                printflag=1;
            }
            else{
                if(alldig[i]!=0)printflag=1;
                if(printflag)printf("%d",alldig[i]);
            }

        }
        if(printflag==0){
            printf("0");
        }
        printf("\n");
    }
    else if(first==decat){
        //round to nearest integer
        alldig[decat-1]++;
        RFREP(i,decat-2,0){
            alldig[i]=alldig[i]+(alldig[i+1]/10);
            alldig[i+1]=alldig[i+1]%10;
        }
        int printflag=0;
        FREP(i,0,(decat-1)){
            if(alldig[i]==-1){
                if(printflag==0)printf("0");
                printf(".");
                printflag=1;
            }
            else{
                if(alldig[i]!=0)printflag=1;
                if(printflag)printf("%d",alldig[i]);
            }

        }
        if(printflag==0){
            printf("0");
        }
        printf("\n");
    }
    else{
        alldig[first]++;
        int printflag=0;
        FREP(i,0,first){
            if(alldig[i]==-1){
                if(printflag==0)printf("0");
                printf(".");
                printflag=1;
            }
            else{
                if(alldig[i]!=0)printflag=1;
                if(printflag)printf("%d",alldig[i]);
            }

        }
        if(printflag==0){
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
