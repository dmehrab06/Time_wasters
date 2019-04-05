/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#define MDD 1000000007
using namespace std;

int sieve[1000005];

vector<int>twopw;

void sv(){
    for(int i = 2; i<=1000000; ++i){
        if(sieve[i]==0){
            sieve[i] = i;
            for(int j = (i+i); j<=1000000; j+=i){
                if(sieve[j]==0){
                    sieve[j] = i; 
                }
            }    
        }
        
    }
    int t = 1;
    for(int i = 0; i<32; ++i){
        twopw.push_back(t);
        t = t<<1;
    }
}

pair<int,int> finddiv(int n){
    if(n==1)return make_pair(1,0);
    int pp = 1;
    int t = n;
    int mxx = 0;
    int prev = -1;
    int flag = 1;
    while(t>1){
        int small = sieve[t];
        int cnt = 0;
        while((t%small)==0){
            t/=small;
            cnt++;
        }
        if(prev==-1){
            prev = cnt;
        }
        else if(cnt!=prev){
            flag = 0;
        }
        pp = pp*small;
        mxx = max(mxx,cnt);
    }
    vector<int>::iterator it;
    it = lower_bound(twopw.begin(),twopw.end(),mxx);
    int val = twopw[(int)(it-twopw.begin())];
    //cout<<val<<"\n";
    if(!flag){
        int cnt = 0;
        while(val>0){
            val = val/2;
            cnt++;
        }
        return make_pair(pp,cnt);
    }
    else{
        int ttt = val;
        int cnt = 0;
        while(val>0){
            val = val/2;
            cnt++;
        }
        if(ttt!=mxx){
            return make_pair(pp,cnt);
        }
        else{
            return make_pair(pp,cnt-1);
        }
    }
}

int main(){
    sv();
    int n;
    scanf("%d",&n);
    pair<int,int>ans = finddiv(n);
    printf("%d %d\n",ans.first,ans.second);
    return 0;
}