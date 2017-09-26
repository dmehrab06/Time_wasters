#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define MAXXX 1000000007
using namespace std;
int nums[304];
int signs[304];
int dp[304][180006];
int N;
int solve(int idx,int curval){
    if(idx>N){
        if(curval==0){
            return 0;
        }
        else{
            return MAXXX;
        }
    }
    if(dp[idx][curval+90000]!=-1){
        return dp[idx][curval+90000];
    }
    int given=nums[idx];
    if(signs[idx]==1){
        given*=-1;
    }
    int ret1,ret2;
    ret1=1+solve(idx+1,curval-given);
    ret2=solve(idx+1,curval+given);
    int ans=min(ret1,ret2);
    dp[idx][curval+90000]=ans;
    return dp[idx][curval+90000];
}
void init(){
    for(int i=0;i<304;++i){
        for(int j=0;j<180006;++j){
            dp[i][j]=-1;
        }
    }
}

int poi(string d){
    int s=0;
    int l=d.size();
    for(int i=0;i<l;++i){
        s=s*10+d[i]-'0';
    }
    return s;
}
int main(){
    //int n;
    init();
    cin>>N;
    signs[1]=0;
    string a;
    cin>>a;
    if(a[0]=='-'){
        signs[1]=1;
        int aa;
        cin>>aa;
        nums[1]=aa;
    }
    else{
        int pp=poi(a);
        nums[1]=pp;
    }
    //nums[1]=a;
    for(int i=2;i<=N;++i){
        string c;
        int n;
        cin>>c>>n;
        if(c[0]=='+'){
            signs[i]=0;
        }
        else{
            signs[i]=1;
        }
        nums[i]=n;
    }
    int ans=solve(1,0);
    if(ans>N){
        cout<<"-1\n";
    }
    else{
        cout<<ans<<"\n";
    }
    return 0;
}
