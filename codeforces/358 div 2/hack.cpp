#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define cnd tree[idx]
#define lnd tree[idx*2]
#define rnd tree[(idx*2)+1]
#define lndp (idx*2),(b),((b+e)/2)
#define rndp (idx*2+1),((b+e)/2+1),(e)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005

int main()
{
    //READ("input.txt");
    //WRITE("out.txt");
    std::ios_base::sync_with_stdio(0);
    LL m, n, i, j, k, sum;

    cin >> n >> m;

    LL cnt = 0;

    FOR(i,1,n)
    {
        cnt += (((i+m)/5) - (i/5));
    }

    cout << cnt << NL;

    return 0;
}
