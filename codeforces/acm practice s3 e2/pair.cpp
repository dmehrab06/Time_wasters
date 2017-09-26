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

int has[600008];
//int cnt[600008];
//vector<VI>pos;
int main(){
    int n,k;
    cin>>n>>k;
    FREP(i,1,k){
        int a;
        scanf("%d",&a);
        has[a]=i;
       // cnt[a]++;
        //pos[a].PB(i);
    }
    int x=0;
    int y=0;
    RFREP(i,600000,1){
        if(has[i]){
            int b=sqrt(i);
            FREP(j,1,b){
                if(i%j==0){
                    int k=i/j;
                    if(has[j]){
                        x=has[i];
                        y=has[j];
                        printf("%d %d\n",x,y);
                        return 0;
                    }
                    else if(has[k] && k!=i){
                        x=has[i];
                        y=has[k];
                        printf("%d %d\n",x,y);
                        return 0;
                    }
                }
            }
        }
    }
    printf("0 0\n");
    return 0;
}
