#include <iostream>
#include <vector>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
using namespace std;

vector<int>digs;

void solve(LLI p, int base){
    while(p){
        LLI dd = p/base;
        int rem = p%base;
        if(rem<0){
            rem+=base;
            dd++;
        }
        digs.PB(rem);
        p = dd;
    }
}

int main(){
    LLI p; int d;
    cin>>p>>d;
    solve(p,d);
    cout<<digs.size()<<"\n";
    for(int i = digs.size()-1;i>=0;--i){
        cout<<digs[i]<<" ";
    }
    cout<<"\n";
}
