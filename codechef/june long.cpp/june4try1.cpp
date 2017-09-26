#include <bits/stdc++.h>

using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        long long int k;
        cin>>k;
        string s="";
        if(k==1){
            cout<<"0\n";
        }
        else{
            long long int t=k-1;
            while(t){
                s.push_back(t%5+'0');
                t/=5;
            }
            reverse(s.begin(),s.end());
            int l=s.size();
            for(int i=0;i<l;++i){
                s[i]=(s[i]-'0')*2+'0';
            }
            cout<<s<<"\n";
        }
    }
    return 0;
}
