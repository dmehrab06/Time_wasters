#include <bits/stdc++.h>

using namespace std;

vector<int>a;
vector<int>b;

void printv(vector<int>a){
    cout<<(int)a.size()<<" ";
        for(int i = 0;i<a.size();++i){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
}

int main(){
    int n;
    cin>>n;
    if(n<=2){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
        int temp = n;
        if(temp%2)temp--;
        for(int i = 1;i<=temp/2;++i){
            if(i%2){
                a.push_back(i);
                a.push_back(temp-i+1);
            }
            else{
                b.push_back(i);
                b.push_back(temp-i+1);
            }
        }
        if(n%2){
            b.push_back(n);
        }
        printv(a);
        printv(b);
    }
}
