#include <bits/stdc++.h>
#define eps 0.000000001

using namespace std;

long long int n,a,b,c,d,ans,k1=0,k2=0,k3=0;
int main(){

    cin>>n>>a>>b>>c>>d;
    k1=abs(a-d);
    k2=abs(c-b)+1;
    k3=k1+k2;
    cout<<n*(n-k3+1)<<"\n";
}
