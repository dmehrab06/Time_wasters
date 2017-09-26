#include <iostream>
using namespace std;

int main(){
    string s="";
    for(int i=0;i<300000;++i){
        s.push_back('a');
    }
    cout<<s<<"\n";
}
