#include <bits/stdc++.h>

using namespace std;

long long int fib[1007];
int main(){
    fib[0]=0;
    fib[1]=1;
    int sz;
    for(int i=2;i<=100;++i){
        fib[i]=fib[i-1]+fib[i-2];
        if(fib[i]>1000000000000000000){
            sz=i;
            break;
        }
    }
    cout<<sz<<"\n";
    for(int i=1;i<=sz;++i){
        cout<<fib[i]<<"\n";
    }
}
