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

int sz[204];
int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&sz[i]);
    }
    if(n==1){
        if(sz[1]==15){
            printf("DOWN\n");
        }
        else if(sz[1]==0){
            printf("UP\n");
        }
        else{
            printf("-1\n");
        }
    }
    else{
        if(sz[n]==15){
            printf("DOWN\n");
        }
        else if(sz[1]==0){
            printf("UP\n");
        }
        else if(sz[n-1]>sz[n]){
            printf("DOWN\n");
        }
        else{
            printf("UP\n");
        }
    }
    return 0;
}
