#include <iostream>
using namespace std;

int main(){
    cout<<"1000 1000\n";
    for(int i=1;i<=1000;++i){
        for(int j=1;j<=1000;++j){
            cout<<(i*2-3+j*5)%1000<<" ";
        }
        cout<<"\n";
    }
    cout<<4<<"\n";
    cout<<"1 4\n";
    cout<<"18 44\n";
    cout<<"19 34\n";
    cout<<"21 41\n";
}
