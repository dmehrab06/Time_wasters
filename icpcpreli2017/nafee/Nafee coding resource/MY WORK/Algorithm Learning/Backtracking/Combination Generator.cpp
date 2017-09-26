#include <bits/stdc++.h>
using namespace std;
int prin[20];
int n, k;
void combination(int pos, int rem)
{
    int a, b, c;
    if ( rem > n-pos+1 ) return;
    if (pos >= n+1)
    {
        for (a = 1; a <= k; a++) cout << prin[a] << " ";
        cout << endl;
        return;
    }
    if (rem)
    {
        prin[k-rem+1] = pos;
        combination(pos+1, rem-1);
    }
    combination(pos+1, rem);
}
int main()
{
    while(1)
    {
        cin >> n >> k;
        combination(1, k);
        cout << endl << endl << endl;
    }
    return 0;
}
