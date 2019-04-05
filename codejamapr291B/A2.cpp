#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;

constexpr int P = 100;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int& x : c) {
        cin >> x;
    }

    priority_queue<pair<int, int>> s;
    int sm = 0;

    for (int i = 0; i < m; ++i) {
        sm += c[i];
        c[i] = (c[i] * P + (n / 2));

        s.emplace(c[i] % n, i);
    }

    for (int i = sm; i < n; ++i) {
        c.emplace_back(n / 2);
        s.emplace(n / 2, i - sm + m);
    }

    while (sm++ < n) {
        int v = s.top().second;
        s.pop();
        c[v] += P;
        s.emplace(c[v] % n, v);
    }

    int ans = 0;
    for (int x : c) {
        ans += x / n;
    }

    cout << ans << "\n";
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
