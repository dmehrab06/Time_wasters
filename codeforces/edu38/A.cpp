/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define LLI long long int
#define VI vector<int>
#define PB push_back
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
using namespace std;

set<char>vowels;

int main(){
    vowels.insert('a'); vowels.insert('e'); vowels.insert('i'); vowels.insert('o'); vowels.insert('u');
    //vowels.insert('y');

    string s;

    int n;
    cin>>n; cin>>s;
    int l = s.size();
    int cons = 1;
    int vw = 0;
    FREP(i,0,(l-1)){
        if(vowels.find(s[i])!=vowels.end()){
            if(cons==1){
                vw= 1;
                cons = 0;
            }
            else{
                s[i] = '#';
            }
        }
        else{
            if(vw==1){
                cons = 1;
                vw = 0;
            }
        }
    }
    string res = "";
    FREP(i,0,(l-1)){
        if(s[i]!='#'){
            res.PB(s[i]);
        }
    }
    cout<<res<<"\n";

}
