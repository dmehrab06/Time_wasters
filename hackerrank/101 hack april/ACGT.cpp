#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string a;
    cin>>a;
    string preva="";
    string ans="";
    while(preva!=a){
    ans="";
    int l=a.size();
    for(int i=0;i<l;){
        //char nw=a[i];
        int coun=0;
        int j;
        for(j=i;a[j]==a[i];++j){
            coun++;
        }
        if(coun%2){
            ans+=a[i];
        }
        i=j;
    }
        preva=a;
        a=ans;
    }
    if(ans==""){
        cout<<"Empty String\n";
    }
    else{
        cout<<ans<<"\n";
    }
    return 0;
}
