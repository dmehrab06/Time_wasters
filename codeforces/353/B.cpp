#include <bits/stdc++.h>
#define eps 0.000000001

using namespace std;


int main(){
    int n,a,b,c,d;
    vector<int>nums;
    cin>>n>>a>>b>>c>>d;
    nums.push_back(a+b);
    nums.push_back(b+d);
    nums.push_back(c+d);
    nums.push_back(c+a);
    sort(nums.begin(),nums.end());
    int dif=nums[3]-nums[0];
   // cout<<dif<<"\n";
    int startfrom=dif+1;
   // cout<<startfrom<<"\n";
    if(startfrom>n){
        cout<<"0\n";
    }
    else{
        cout<<(n*(n-startfrom+1))<<"\n";
    }
    return 0;
}
