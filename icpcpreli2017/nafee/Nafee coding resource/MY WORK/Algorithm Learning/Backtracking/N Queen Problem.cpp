#include <bits/stdc++.h>
using namespace std;
int rowFilled[20], colFilled[20], n, i, j, k, ans, cas, diag1Filled[100], diag2Filled[100];
string grid[20];
int ifOk(int row, int col)
{
    int i, j, k, dx, dy;
    if ( grid[row-1][col-1] == '*' ) return false;
    if ( rowFilled[row]  )
    {
        return false;
    }
    if ( colFilled[col] ) return false;
    if ( diag1Filled[50+row+col] | diag2Filled[50 + row-col] ) return false;
    return true;
}
int countSol(int pos, int tot)
{
    int i, j, k, ret = 0, row = pos, col;
    if ( pos == tot )
    {
        for (i = 1; i <= tot; i++)
        {
            if(ifOk(pos, i) )
            {
                ret++;
            }
        }
        return ret;
    }
    for ( i = 1; i <= tot; i++ )
    {
        if  ( ifOk(pos, i) )
        {
            row = pos;
            col = i;
            rowFilled[pos] = colFilled[i] = diag1Filled[50+row+col] = diag2Filled[50+row-col] = 1;
            ret += countSol(pos+1, tot);
            rowFilled[pos] = colFilled[i] = diag1Filled[50+row+col] = diag2Filled[50+row-col] = 0;
        }
    }
    return ret;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cas = 0;
    while(++cas)
    {
        memset(rowFilled, 0, sizeof(rowFilled));
        memset(colFilled, 0, sizeof(colFilled));
        memset(diag1Filled, 0, sizeof(diag1Filled));
        memset(diag2Filled, 0, sizeof(diag2Filled));

        cin >> n;
        for (i = 0; i < n; i++) cin >> grid[i];
        if (n == 0) return 0;
        ans = countSol(1, n);
        cout << "Case " << cas << ": " << ans << endl;
    }
    return 0;
}
