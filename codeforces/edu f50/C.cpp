#include <bits/stdc++.h>
using namespace std;

vector<int> num;

long long DP[10][20][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

bool isvalid(int mask){
    int oka = __builtin_popcount(mask); 
	return (oka>=1 && oka<=3);
}

long long call(int cnt, int pos, int f){
    if(cnt>3)return 0;
    //cout<<mask<<" "<<pos<<" "<<f<<"\n";
	//if(!isvalid(mask))return 0; 
    if(pos == num.size()){
        if(cnt>=1 && cnt<=3)return 1;
        else return 0;
    }

    if(DP[cnt][pos][f] != -1) return DP[cnt][pos][f];
    long long res = 0;

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
        if(dgt!=0){
            res+=call(cnt+1,pos+1,nf);
        }
        else{
            res+=call(cnt,pos+1,nf);
        }
        //res += call(nmask, pos+1, nf);
    }

    return DP[cnt][pos][f] = res;
}

long long solve(long long b){
    //cout<<"for "<<b<<"\n";
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
    long long res = call(0, 0, 0);
    return res;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        //long long a,b;
        //scanf("%lld %lld",&a,&b);
        //printf("%lld\n",solve(b)-solve(a-1));
        long long a,b;
        cin>>a>>b;
        cout<<solve(b)-solve(a-1)<<"\n";
    }

    return 0;
}