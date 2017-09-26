/*
 She tells him "your life ain't gonna be nothing like my life
 You're gonna grow and have a good life
 I'm gonna do what I've got to do"
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
inline int in(){int32_t x ; scanf("%d",&x) ; return x ;}
inline long long lin(){long long x ; scanf("%lld",&x) ; return x;}
const int maxn = 1e6 + 10;
const int maxm = 5e5 + 10;
const int mod = 1e9 + 7;
const long long infll = 2e18 + 10;
const int inf = 1e9;
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
int best[3],pre[maxn][3];
int dp[maxn][3];
string s;
inline void printSol(int cnt , int i , int md = 0)
{
    if (cnt == 0) return ;
    printSol(cnt-1, pre[i][md] , (md - ((s[i] - '0')%3) + 3) % 3);
    cout << s[i];
}
int Pre[3];
int maxi[3];
int32_t main()
{
    memset(best,-1,sizeof best);
    best[0] = 0;
    cin >> s;
    s = "@" + s;
    bool zero = false;
    for (int i = 1 ; i < s.size() ; i ++)
        if (s[i] == '0') zero = true;
    for (int i = 1 ; i < s.size() ; i ++){
        memset(maxi,-1,sizeof maxi);
        for (int premod = 0 ; premod < 3 ; premod ++)
        {
            if (best[premod] == -1) continue;
            int newmod = (premod + (s[i] - '0')) % 3;
            if (best[premod] == 0 && s[i] == '0') continue;
            int newcnt = dp[best[premod]][premod] + 1;
            if (newcnt > maxi[newmod]) maxi[newmod] = newcnt , Pre[newmod] = best[premod];
        }
        for (int j = 0 ; j < 3 ; j ++){
            if (best[j] == -1 || dp[best[j]][j] < maxi[j])
                best[j] = i , dp[i][j] = maxi[j] , pre[i][j] = Pre[j];
        }
    }
    if (dp[best[0]][0] == 0){
        if (zero == false) return cout << -1 << endl , 0;
        return cout << 0 << endl , 0 ;
    }
    else{
        printSol(dp[best[0]][0], best[0] , 0);
    }
}
