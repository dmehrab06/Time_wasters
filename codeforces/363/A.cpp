#include <bits/stdc++.h>
#define MXX 1000000000000005
using namespace std;

string particle;

int pos[200006];

int main(){
    int n;
    cin>>n;
    cin>>particle;
    for(int i=0;i<n;++i){
        scanf("%d",&pos[i]);
    }
    long long int smallest=1000000000000005;
    for(int i=0;i<(n-1);++i){
        if(particle[i]=='R' && particle[i+1]=='L'){
            long long int ans=(pos[i]/2+pos[i+1]/2);
            long long int t=(ans-pos[i]);
            if(t<smallest){
                smallest=t;
            }
        }
    }
    if(smallest==MXX){
        cout<<"-1\n";
    }
    else{
        cout<<smallest<<"\n";
    }
}
