#include <iostream>
#include <vector>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define LLI long long
using namespace std;

vector<int>digs;

void solve(LLI p, int base){
    while(p){
        LLI dd = p/base;
        int rem = p%base;
        while(rem<0){
            rem+=(-base);
            dd++;
        }
        digs.push_back(rem);
        p = dd;
    }
}

int main(){
    LLI p; int d;
    cin>>p>>d;
    solve(p,-d);
    cout<<digs.size()<<"\n";
    for(int i = 0;i<digs.size();++i){
        cout<<digs[i]<<" ";
    }
    cout<<"\n";
}
