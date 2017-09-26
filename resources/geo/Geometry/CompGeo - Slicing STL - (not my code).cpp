    #include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
typedef vector<int> VI; typedef vector<string> VS; typedef vector<VI> VVI;
template<class A,class B> inline bool contains(const A&a, const B&b) {
    return find(a.begin(), a.end(), b) != a.end();
}
template<class T> string i2s(T x) { ostringstream o; o << x; return o.str(); }
int s2i(string s) { istringstream i(s); int x; i >> x; return x; }
LL s2ll(string s) { istringstream i(s); LL x; i >> x; return x; }

///////////////////////////////////////////////////////////////////

struct Rect {
    int l, b, r, t;
};

int n;
Rect r[100];
int vx[200], nx;
int vy[200], ny;
bool c[200][200];

bool vis[200][200];
int q[200*200][2], qs, qe;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool inbounds(int x, int y) {
    return 0 <= x && x < nx-1 && 0 <= y && y < ny-1;
}

void bfs() {
    memset(vis, 0, sizeof(vis));
    qs = qe = 0;
    
    q[qe][0] = 0; q[qe++][1] = 0; 
    vis[0][0] = 1;

    int i, x1, y1, x2, y2;

    while( qs < qe ) {
        x1 = q[qs][0]; y1 = q[qs][1];
        for( i = 0; i < 4; i++ ) {
            x2 = x1+dx[i]; y2 = y1+dy[i];
            if( inbounds(x2, y2) && !c[x2][y2] && !vis[x2][y2] ) {
                q[qe][0] = x2; q[qe++][1] = y2;
                vis[x2][y2] = 1;
            }
        }
        qs++;
    }
}

class SwampyLands {
public:
    int surroundedArea(vector <string> swampy) {
        int i, j, k, x, y, z;
        int res = 0;

        nx = ny = 0;
        vx[nx++] = -INF; vx[nx++] = INF;
        vy[ny++] = -INF; vy[ny++] = INF;
        n = swampy.size(); 
        for( i = 0; i < n; i++ ) {
            istringstream is(swampy[i]);
            is >> r[i].l >> r[i].b >> r[i].r >> r[i].t;
            vx[nx++] = r[i].l;
            vy[ny++] = r[i].b;
            vx[nx++] = r[i].r;
            vy[ny++] = r[i].t;
        }
        sort(vx, vx+nx); nx = unique(vx, vx+nx)-vx;
        sort(vy, vy+ny); ny = unique(vy, vy+ny)-vy;
        for( i = 0; i < n; i++ ) {
            r[i].l = lower_bound(vx, vx+nx, r[i].l)-vx;
            r[i].b = lower_bound(vy, vy+ny, r[i].b)-vy;
            r[i].r = lower_bound(vx, vx+nx, r[i].r)-vx;
            r[i].t = lower_bound(vy, vy+ny, r[i].t)-vy;
        }
        memset(c, 0, sizeof(c));
        for( i = 0; i < n; i++ )
        for( j = r[i].l; j < r[i].r; j++ )
        for( k = r[i].b; k < r[i].t; k++ )
            c[j][k] = 1;
        bfs();
        for( i = 0; i < nx-1; i++ )
        for( j = 0; j < ny-1; j++ )
            if( !c[i][j] && !vis[i][j] ) res += (vx[i+1]-vx[i])*(vy[j+1]-vy[j]);
        return res;
    }
    
 
};
