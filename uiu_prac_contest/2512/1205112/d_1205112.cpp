#include <iostream>
using namespace std;
int N,M,P;
long long int pow(int N, int P){
    if(P==0){
        return 1;
    }
    if(P%2==0){
        long long int ret=pow(N,P/2);
        if(ret>M){
            ret=ret%M;
        }
        return ((ret)*(ret))%M;
    }
    else if(P%2){
        long long int ret=pow(N,P/2);
        if(ret>M){
            ret=ret%M;
        }
        if(N>M){
            N=N%M;
        }
        return ((ret)*(ret)*N)%M;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>N>>P>>M;
        cout<<pow(N,P)<<"\n";
    }
}
