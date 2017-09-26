#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a < b) return gcd(b, a);
    if (a%b==0) return b;
    return gcd(b, a%b);
}
int main()
{
    int a, b;
    while(1)
    {
        cin >> a >> b;
        cout << gcd(a, b) << endl << endl;
    }
    return 0;
}
