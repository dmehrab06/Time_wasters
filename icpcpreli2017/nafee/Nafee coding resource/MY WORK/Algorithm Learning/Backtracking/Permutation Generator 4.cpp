#include <bits/stdc++.h>
using namespace std;
#define SIZE 100
int ifUsed[SIZE];
int prin[SIZE], number;
int n, r;
void printPerm(int pos, int n, int r)
{
    int i, j, k;
    if (pos >= r)
    {
        number++;
        cout << number << ". ";
        for (i = 0; i < r; i++) cout << prin[i] << " ";
        cout << endl;
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if ( !ifUsed[i] )
        {
            ifUsed[i] = 1;
            prin[pos] = i;
            printPerm(pos+1, n, r);
            ifUsed[i] = 0;
        }
    }
    return;
}
int main()
{
    memset(ifUsed, 0, sizeof(ifUsed));
    number = 0;
    cin >> n >> r;
    printPerm(0, n, r);
    cout << endl << endl << endl;
    return main();
}
