#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a,long long int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
vector<long long int>all;
int main(){
    long long int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        long long int a;
        cin>>a;
        all.push_back(a);
    }
    sort(all.begin(),all.end());
    for(int i=0;i<n;++i){
        if(k==1)break;
        long long int g=gcd(k,all[i]);
        k/=g;
    }
    if(k==1){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}
