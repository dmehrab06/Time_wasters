#include <bits/stdc++.h>
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=N && (Y)>=1 && (Y)<=(M))
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int even=0;
    for(int i=1;i<=n;++i){
        int a;
        scanf("%d",&a);
        if(a%2==0)even++;
        if(even%2){
            printf("1\n");
        }
        else{
            printf("2\n");
        }
    }
    return 0;
}
