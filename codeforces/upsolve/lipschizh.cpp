#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;

long long int arr[100006];
long long int diff[100006];
long long int lft[100006];
long long int rght[100006];

int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        long long int a;
        cin>>a;
        arr[i]=a;
    }
    for(int i=1;i<n;++i){
        diff[i]=abs(arr[i]-arr[i+1]);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        stack<int>mystack;
        for(int i=a;i<b;++i){
            while(!mystack.empty() && diff[i]>=diff[mystack.top()]){
                mystack.pop();
            }
            if(mystack.empty()){
                lft[i]=a;
            }
            else{
                lft[i]=mystack.top()+1;
            }
            mystack.push(i);
        }
        while(!mystack.empty()){
            mystack.pop();
        }
        for(int i=b-1;i>=a;--i){
            while(!mystack.empty() && diff[i]>diff[mystack.top()]){
                mystack.pop();
            }
            if(mystack.empty()){
                rght[i]=b-1;
            }
            else{
                rght[i]=mystack.top()-1;
            }
            mystack.push(i);
        }
        long long int ans=0;
        for(int i=a;i<b;++i){
            ans+=diff[i]*(i-lft[i]+1)*(rght[i]-i+1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
