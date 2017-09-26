#include <bits/stdc++.h>
using namespace std;
int used[20], prin[20];
int n, k;
void printPermutation(int pos, int n, int k)
{
    int i, j;
    if (pos >= k+1)
    {
        for (i = 1; i <= k; i++) cout << prin[i] << " ";
        cout << endl;
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if ( !used[i] )
        {
            used[i] = 1;
            prin[pos] = i;
            printPermutation(pos+1, n, k);
            used[i] = 0;
        }
    }
}
int main()
{
    while(1)
    {
        cin >> n >> k;
        memset(used, 0, sizeof(used));
        printPermutation(1, n, k);
        cout << endl << endl << endl;
    }
    return 0;
}
