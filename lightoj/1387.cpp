#include <iostream>
using namespace std;
char d[10];
int main(){
    int t;
    cin>>t;
    int i=1;
    while(t--){
        int n;
        cin>>n;
        cout<<"Case "<<i<<":\n";
        int amount=0;
        while(n--){
            int tk;
            cin>>d;
            if(d[0]=='d'){
                cin>>tk;
                amount+=tk;
            }
            else{
                cout<<amount<<"\n";
            }
        }
        i++;
    }
    return 0;
}
