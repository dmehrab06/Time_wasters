#include <bits/stdc++.h>
#define eps 0.000000001

using namespace std;


int main(){
    long long int a,b,c;
    cin>>a>>b>>c;
    if(c==0){
        if(a==b){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else{
        long long int d=b-a;
        if(d%c==0){
            long long int e=d/c;
            if(e>=0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
