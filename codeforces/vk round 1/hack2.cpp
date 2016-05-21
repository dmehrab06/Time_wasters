#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int nmax=100005;
int n,d,h;
int t[nmax];

int main(){
    //using ull=unsigned long long ;
    cin>>n>>d>>h;
    int cur=0;
    int ii=0;
    for(int i=1;i<=h;++i){
        cout<<i<<" "<<i+1<<"\n";
        cur=i+1;
        ii=i;

    }
    int prev=1;
    for(int i=1;i<=(d-h);++i){
        ++cur;
        cout<<prev<<" "<<cur<<"\n";
        prev=cur;
    }
    for(int i=d+2;i<=n;++i){
        ++cur;
        cout<<ii<<" "<<cur<<"\n";
    }
}
