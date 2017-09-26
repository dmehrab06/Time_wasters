#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
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
#define pi acos(-1.0)
#define float double
using namespace std;

LLI parr[103];
LLI prize[18];
LLI bought[18];
int main(){
    int N;
    scanf("%d",&N);
    FREP(i,1,N)cin>>parr[i];
    FREP(i,1,5)cin>>prize[i];
    LLI now=0;
    FREP(i,1,N){
        now+=parr[i];
        RFREP(j,5,1){
            LLI canbuy=now/prize[j];
            bought[j]+=canbuy;
            now=now%prize[j];
        }
    }
    FREP(i,1,5){
        cout<<bought[i]<<" ";
    }
    cout<<"\n"<<now<<"\n";
    return 0;
}
