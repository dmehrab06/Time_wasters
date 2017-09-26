#include <bits/stdc++.h>
#define LLI long long int
using namespace std;

LLI ncr[205][205];

void init(){
    for(int i=0;i<205;++i){
        for(int j=0;j<205;++j){
            ncr[i][j]=0;
        }
    }
    for(int i=0;i<205;++i){
        ncr[i][0]=1;
        ncr[i][i]=1;
    }
    for(int n=0;n<205;++n){
        for(int r=1;r<n;++r){
            ncr[n][r]=ncr[n-1][r-1]+ncr[n-1][r];
            ncr[n][r]%=1000000007;
        }
    }
}

int main(){
    init();
    /*for(int i=0;i<25;++i){
        for(int j=0;j<25;++j){
            cout<<ncr[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    int n,m;
    scanf("%d %d",&n,&m);
    cout<<ncr[m][n]<<"\n";
    return 0;
}
