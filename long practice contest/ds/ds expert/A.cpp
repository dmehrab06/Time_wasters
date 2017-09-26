#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <cstdlib>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 20007
using namespace std;
int willbezero[60005][32];

int arr[60005];
int num[20005];
int ans[20005];
void calc(int bit, int N){  //O(8N)
    int until=3*N-2;
    int zpower=MXX;
    int msk=1<<bit;
    for(int i=1;i<=until;++i){  //O(3N)
        if((arr[i])&(msk)){
            willbezero[i][bit]=min(willbezero[i][bit],zpower);
            zpower++;
        }
        else{
            zpower=0;
            willbezero[i][bit]=0;
            zpower++;
        }
    }
    zpower=MXX;
    for(int i=until;i>=1;--i){  //O(3N)
        if((arr[i])&(msk)){
            willbezero[i][bit]=min(willbezero[i][bit],zpower);
            zpower++;
        }
        else{
            zpower=0;
            willbezero[i][bit]=0;
            zpower++;
        }
    }
}

void init(int N){ //O(32*3*N)
    int until=3*N-2;
    for(int i=0;i<=until+2;++i){
        for(int j=0;j<32;++j){
            willbezero[i][j]=MXX;
        }
    }
}

void load(int N){  //O(3N)
    int start=1;
    for(int i=2;i<=N;++i){
        arr[start]=num[i];
        start++;
    }
    for(int i=1;i<=N;++i){
        arr[start]=num[i];
        start++;
    }
    for(int i=1;i<N;++i){
        arr[start]=num[i];
        start++;
    }
}

void loadans(int idx, int K, int N){ //O(32)
    int got=0;
    for(int i=31;i>=0;--i){
        got=got*2+(K>=willbezero[(N-1+idx)][i]?0:1);
    }
    ans[idx]=got;
}
int main(){
    int t;
    while(scanf("%d",&t)==1){
    while(t--){
        int N,K;
        scanf("%d %d",&N,&K);
        K=min(MXX,K);
        init(N); //O(32*3*N)
        for(int i=1;i<=N;++i){
            scanf("%d",&num[i]); //O(N)
        }
        load(N); //O(3N)
        for(int i=0;i<32;++i){
            calc(i,N);    //O(8N)
        }
        for(int i=1;i<=N;++i){
            loadans(i,K,N);  // O(32)
        }
        printf("%d",ans[1]);
        for(int i=2;i<=N;++i){
            printf(" %d",ans[i]);  // O(N)
        }
        printf("\n");//total O((32*3+1+3+8+1)N)+O(32) = O(150N)+O(32) == worst case 150*20000=3*10^6 //shouldnt be a problem :/
    }
    }
    return 0; //test case 50 = 15*10^7=1.5*10^8 :/ this seems fun :/
}
