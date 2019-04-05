#include <bits/stdc++.h>
using namespace std;

vector<int> num;

long long a,b;

int DP[520][20][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

bool isvalid(int mask){
	int one_count = 0;
	for(int i = 0; i<9;++i){
		if(mask&(1<<i))one_count++;
	}
	return (one_count<=3);
}

int call(int mask, int pos, int f){
	if(!isvalid(mask))return 0; 
    if(pos == num.size()){
        return 1;
    }

    if(DP[mask][pos][f] != -1) return DP[pos][cnt][f];
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
        int nmask;
        if(dgt!=0){
        	nmask = mask | (1<<(dgt-1));
        }
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        res += call(nmask, pos+1, nf);
    }

    return DP[mask][pos][f] = res;
}

int solve(int b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0);
    return res;
}

int main () {

    cin >> a >> b;
    int res = solve(b) - solve(a-1);
    cout << res << "\n";

    return 0;
}