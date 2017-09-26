#include <bits/stdc++.h>
#define MDD 1000000007
#define eps 0.0000000001
using namespace std;

int divv[100003][135];

void foo(int N){
    for(int i=1;i<=N;++i){
        divv[i][0]=0;
    }
    for(int i=1;i<=N;++i){
        int b=sqrt(i);
        for(int j=1;j<=b;++j){
            if(i%j==0){
                divv[i][divv[i][0]+1]=j;
                divv[i][0]++;
                int c=i/j;
                if(c!=j){
                    divv[i][divv[i][0]+1]=c;
                    divv[i][0]++;
                }
            }
        }
    }
}
int main(){
    foo(100000);
}

