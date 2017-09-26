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
#define MSI map<string,int>
#define PII pair<int,int>
using namespace std;

int main(){
    int t;
    while(scanf("%d",&t)==1 && t!=-1){
        for(int i=1;i<=t;++i){
            int d,ball;
            scanf("%d %d",&d,&ball);
            LLI pos=1;
            int msk=1;
            ball--;
            for(int k=1;k<d;++k){
                pos<<=1;
                if(ball&msk){
                    pos++;
                }
                ball>>=1;
            }
            printf("%lld\n",pos);
        }
    }
    return 0;
}
