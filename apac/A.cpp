//ds--
//algo--implementation

#include<iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        int n;
        cin>>n;
        scanf(" ");
        vector<string>all;
       // vector<int>all2;
        string name2;
        int a[26];
        int mxi=-1;
        int mx=-1;
        for(int i=0;i<n;++i){
            getline(cin,name2);
            all.push_back(name2);
        }
        sort(all.begin(),all.end());
        for(int i=0;i<n;++i){
            string name=all[i];
            for(int j=0;j<26;++j){
                a[j]=0;
            }
            int l=name.size();
            for(int k=0;k<l;++k){
                if(name[k]>='A' && name[k]<='Z'){
                    a[name[k]-'A']++;
                }
            }
            int tot=0;
            for(int j=0;j<26;++j){
                if(a[j])tot++;
            }
            if(tot>mx){
                mx=tot;
                mxi=i;
            }
        }
        cout<<"Case #"<<cs++<<": "<<all[mxi]<<"\n";
    }
    return 0;
}
