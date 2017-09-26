#include <cstdio>
#include <algorithm>
using namespace std;
#define ls(i) (i << 1)
#define rs(i) (i << 1 | 1)

const int N = 100010;

int n, m, a[N];

template <int N>
struct segtree {
    //g[log(N)][N]: store elements in each level
    int g[20][N], lx[N << 2], rx[N << 2], minn, maxn;

    //get the minimal/maximal value in a[]
    void init(int a[], int n) {
        minn = maxn = a[1];
        for (int i = 2; i <= n; ++i) {
            minn = min(minn, a[i]);
            maxn = max(maxn, a[i]);
        }
    }

    //build the segtree; in each node the elements are sorted; d means depth
    void build(int a[], int l, int r, int d, int i) {
        lx[i] = l, rx[i] = r;
        if (l == r) {
            g[d][l] = a[l];
            return;
        }
        int h = (l + r) >> 1;
        build(a, l, h, d + 1, ls(i));
        build(a, h + 1, r, d + 1, rs(i));

        int tmpL = l, tmpR = h + 1;
        for (int j = l; j <= r; ++j) {
            if (tmpL > h) g[d][j] = g[d + 1][tmpR++];
            else if (tmpR > r) g[d][j] = g[d + 1][tmpL++];
            else g[d][j] = g[d + 1][tmpL] < g[d + 1][tmpR] ? g[d + 1][tmpL++] : g[d + 1][tmpR++];
        }
    }

    //return the last position which value is smaller or equal to val in a[]
    int half(int l, int r, int a[], int val) {
        int ret = l - 1;
        while (l <= r) {
            int h = (l + r) >> 1;
            if (a[h] <= val) {
                ret = h;
                l = h + 1;
            }
            else r = h - 1;
        }
        return ret;
    }

    //return the number of elements between interval [l, r] which value is smaller or equal to val
    int get(int l, int r, int val, int d, int i) {
        int ret = 0;
        if (l <= lx[i] && rx[i] <= r) return half(lx[i], rx[i], g[d], val) + 1 - lx[i];
        int h = (lx[i] + rx[i]) >> 1;
        if (l <= h) ret += get(l, r, val, d + 1, ls(i));
        if (r > h) ret += get(l, r, val, d + 1, rs(i));
        return ret;
    }

    //return the k-th smallest element in interval [l, r]
    int query(int l, int r, int k) {
        int L = minn, R = maxn, ans(0);
        while (L <= R) {
            int M = (L + R) >> 1;
            if (get(l, r, M, 0, 1) >= k) {
                ans = M;
                R = M - 1;
            } else L = M + 1;
        }
        return ans;
    }
};

segtree <N> sg;

int main() {
    freopen("in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sg.init(a, n);
    sg.build(a, 1, n, 0, 1);
    int l, r, k;
    while (m--) {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", sg.query(l, r, k));
    }
    return 0;
}