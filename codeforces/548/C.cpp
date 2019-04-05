/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define eps 1e-9

using namespace std;

int main(){
    int n; string s;
    cin>>n>>s;
    long long tot = 0;
    for(int i = 0; i<n; ++i){
        if((s[i]-'0')%2==0){
            tot = tot + (i+1);
        }
    }
    cout<<tot<<"\n";
    return 0;
}