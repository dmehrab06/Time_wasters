#include <bits/stdc++.h>
using namespace std;
#define SIZE 20
int n, used[SIZE], prin[SIZE];
int i, j, k, m, cnt;
void printPermutation(int pos, int total)
{
    int i, j, k;
    if (pos > total)
    {
        cout << (++cnt) << ".. ";
        for (i = 1; i <= total; i++) cout << prin[i] << " ";
        cout << endl;
        return;
    }
    for (i = 1; i <= total; i++)
    {
        if ( !used[i] )
        {
            used[i] = 1;
            prin[i] = pos;
            printPermutation(pos+1, total);
            used[i] = 0;
        }
    }
}
int main()
{
    while(1)
    {
        cin >> n;
        cnt = 0;
        printPermutation(1, n);
        cout << endl << endl << endl;
    }
    return 0;
}
