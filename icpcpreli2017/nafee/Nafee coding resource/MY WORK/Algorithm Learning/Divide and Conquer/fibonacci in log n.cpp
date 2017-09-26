#include <bits/stdc++.h>
using namespace std;
struct mat
{
    ar[2][2];
    mat()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                ar[i][j] = 0;
            }
        }
    }
};
mat I, ans;
int n;
mul(mat A, mat B)
{
    int i, j, k;
    mat ret;
    for (i = 0; i<2; i++)
    {
        for (j=0; j<2; j++)
        {
            for (k=0; k<2; k++)
            {
                ret.ar[i][j] += (A.ar[i][k] * B.ar[k][j]);
            }
        }
    }
    return ret;
}
int main()
{
    int i, j, k;
    cin >> n;
    ans = I;
    for (i = 2; i <= n; i++)
    {
        ans = mul(ans, I);
    }
    cout <<
    return main();
}
