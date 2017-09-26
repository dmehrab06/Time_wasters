#include <bits/stdc++.h>

using namespace std;
int nums[14]={0,1,8,27,64,125,216,343,512,729,1000,1331,1728,2197};
int main(){
    int c=0;
    int nxt=1;
    int sqrt3=0;
    for(int i=1;i<=2000;++i){
        if(i==nums[nxt]){
            nxt++;
            sqrt3++;
        }
        cout<<i<<" "<<sqrt3<<"\n";
        if(i%sqrt3==0)c++;
    }
    cout<<c<<"\n";
}
