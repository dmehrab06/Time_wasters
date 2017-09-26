//algo: binary search
//educational round 702C
#include <bits/stdc++.h>
#define LLI long long int
#define MXX 10000000000
#define MNN -10000000000
using namespace std;
LLI kk[100005];
map<LLI,int>nums;
LLI twopows[35];
void init(){
    twopows[0]=1;
    for(int i=1;i<35;++i){
        twopows[i]=twopows[i-1]*2;
    }
}
int main(){
    init();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        cin>>kk[i];
        nums[kk[i]]++;
    }
    LLI tot=0;
    for(int i=1;i<=n;++i){
        LLI nw=kk[i];
        for(int j=0;j<35;++j){
            LLI sm=twopows[j];
            LLI need=sm-nw;
            if(nums.find(need)!=nums.end()){
                int has=nums[need];
                if(need==nw){
                    has--;
                }
                tot+=has;
            }
        }
    }
    cout<<tot/2<<"\n";
}
