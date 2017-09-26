#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long isUsed[SIZE], toPrint[SIZE], idx;
void printPer(long long n, long long r, long long cur)
{
    long long a, b, c, d, e, f, g, h;
    if (cur > r)
    {
        idx++;
        cout << idx << ". " ;
        for (a = 1; a<= r; a++)
        {
            cout << toPrint[a] << " ";
        }
        cout << endl;
        return;
    }
    for (a = 1; a <= n; a++)
    {
        if ( !isUsed[a] )
        {
            isUsed[a] = 1;
            toPrint[cur] = a;

            printPer(n, r, cur+1);

            isUsed[a] = 0;
        }
    }
    return;
}
int main()
{
    printPer(3, 3, 1);
    return 0;
}
