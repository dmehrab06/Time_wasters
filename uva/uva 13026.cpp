#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int dif(string s1, string s2){
    int l1=s1.size();
    int l2=s2.size();
    if(l1!=l2){
        return 2;
    }
    else{
        int diff=0;
        for(int i=0;i<l1;++i){
            if(s1[i]!=s2[i]){
                diff++;
                if(diff>1){
                    return diff;
                }
            }
        }
        return diff;
    }
}

int main()
{
   int t;
   cin>>t;
   int cs=1;
   while(t--){
        int N;
        cin>>N;
        vector<string>phones;
        int sz=N;
        while(sz--){
            string p;
            cin>>p;
            phones.push_back(p);
        }
        string johny;
        cin>>johny;
        cout<<"Case "<<cs++<<":\n";
        for(int i=0;i<N;++i){
            if(dif(phones[i],johny)<=1){
                cout<<phones[i]<<"\n";
            }
        }

   }
   printf("%d\n",2200000000);
   return 0;
}
