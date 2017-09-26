#include <bits/stdc++.h>
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=N && (Y)>=1 && (Y)<=(M))
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=(n-1);++i){
        printf("I ");
        if(i%2){
            printf("hate that ");
        }
        else{
            printf("love that ");
        }
    }
    if(n%2){
        printf("I hate it\n");
    }
    else{
        printf("I love it\n");
    }
    return 0;
}
