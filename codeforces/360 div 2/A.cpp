#include <bits/stdc++.h>

using namespace std;

//int xpointsexist[200005];



int main(){
    int n,d;
    string ss;
    cin>>ss;
    int ll=ss.size();
    int pp=ll*2;
    string ans="";
    for(int i=0;i<pp;++i){
        ans.push_back('0');
    }
    int go=ll;
    for(int i=0;i<go;++i){
        ans[i]=ss[i];
        ans[pp-i-1]=ss[i];
    }
    cout<<ans<<"\n";
    return 0;
}
