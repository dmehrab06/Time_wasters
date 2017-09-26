#include <bits/stdc++.h>

using namespace std;

bool check1(int t, int s, int x){
    return t==x;
}
bool check2(int t, int s, int x){
    return ((x-t)>0) && ((x-t)%s==0);
}
bool check3(int t, int s, int x){
    return ((x-t-1)>0) && ((x-t-1)%s==0);
}

int main(){
    long long int t,s,x;
    cin>>t>>s>>x;
    if(check1(t,s,x) || check2(t,s,x) || check3(t,s,x)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
