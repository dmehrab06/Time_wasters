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
using namespace std;

int main(){
    int A,B;
    while(scanf("%d %d",&A,&B)==2){
        map<int,int>parade;
        map<int,int>::iterator it;
        FREP(i,1,A){
            int a;
            scanf("%d",&a);
            parade[a]++;
        }
        int ans;
        for(it=parade.begin();it!=parade.end();++it){
            if((it->second)%B){
                ans=it->first;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
