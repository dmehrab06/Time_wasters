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

int ans[400005];

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int P,L;
        scanf("%d %d",&P,&L);
        int ss=P-L;
        int sz=0;
        int b=sqrt(ss);
        FREP(i,1,b){
            if(ss%i==0){
                int j=ss/i;
                if(i>L){
                    ans[sz++]=i;
                }
                if(j!=i && j>L){
                    ans[sz++]=j;
                }
            }
        }
        if(sz==0){
            printf("Case %d: impossible\n",cs++);
        }
        else{
            sort(ans,ans+sz);
            printf("Case %d:",cs++);
            FREP(i,0,(sz-1)){
                printf(" %d",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
