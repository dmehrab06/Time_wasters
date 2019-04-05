#include <bits/stdc++.h>
using namespace std;

vector<int> num;

int DP[92][92][11][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

int call(int mod, int sum, int pos, int f, int K){ 
    if(pos == num.size()){
        if(mod==0 && (sum%K)==0)return 1;
        else return 0;
    }

    if(DP[mod][sum][pos][f] != -1) return DP[mod][sum][pos][f];
    int res = 0;

    int LMT;

    if(f == 0){
        /// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        LMT = num[pos];
    } else {
        /// The number has already become smaller than b. We can place any digit now.
        LMT = 9;
    }

    /// Try to place all the valid digits such that the number doesn't exceed b
    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        //cout<<"putting dgt "<<dgt<<" at "<<pos<<"\n";
        res+=call((mod*10+dgt)%K,sum+dgt,pos+1,nf,K);
        //res += call(nmask, pos+1, nf);
    }

    return DP[mod][sum][pos][f] = res;
}

int solve(int b, int k){
    //cout<<"for "<<b<<"\n";
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0, 0, k);
    return res;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs = 1;
    while(t--){
        //long long a,b;
        //scanf("%lld %lld",&a,&b);
        //printf("%lld\n",solve(b)-solve(a-1));
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);
        if(k>90){
            printf("Case %d: 0\n",cs++);
        }
        else{
            printf("Case %d: %d\n",cs++,solve(b,k)-solve(a-1,k));    
        }
    }

    return 0;
}