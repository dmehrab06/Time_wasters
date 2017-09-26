#include <iostream>

using namespace std;

int main(){
    cout<<50000<<"\n";
    for(int i=0;i<100000;++i){
        cout<<(char)(i%26+'a');
    }
    cout<<"\n";
}
