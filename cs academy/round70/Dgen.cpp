#include <bits/stdc++.h>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
using namespace std;

int main(){
    int n = 30;
    int k = 30;
    FREP(i,1,n){
        FREP(j,1,k){
            cout<<i<<" "<<j<<"\n";
        }
    }
    return 0;
}
