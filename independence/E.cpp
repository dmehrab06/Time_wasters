#include <iostream>
using namespace std;

int main(){
    long long int n,m,a;
    cin>>n>>m>>a;
    long long int x,y;
    x=(n/a);
    if((n%a)){
        x++;
    }
    y=(m/a);
    if((m%a)){
        y++;
    }
    cout<<x*y;
}
