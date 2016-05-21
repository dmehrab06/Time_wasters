#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int nmax=100005;
int n,d,h;
int t[nmax];

int main(){
    cin>>n>>d>>h;
    int curnode=1;
    for(int i=2;i<=h+1;++i){
        t[i]=i-1;
    }
    curnode=h+2;
    int ramas=d-h;
    if(ramas){
        t[curnode]=1;
        ramas--;
        for(++curnode;ramas>0;++curnode,--ramas){
            t[curnode]=curnode-1;
        }
        --curnode;
    }
    else{
        curnode=h+1;
    }
    if(curnode>n){
        cout<<"-1\n";
        return 0;
    }
    curnode++;
    for(;curnode<=n;++curnode){
        t[curnode]=2;
    }
    for(int i=2;i<=n;++i){
        cout<<t[i]<<" "<<i<<"\n";
    }
}
