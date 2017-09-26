#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long a, b, c, d, e, f, g, idx;
long long toPrint[SIZE], isUsed[SIZE];
void genPowSet(long long n, long long upto, long long pos)
{
    long long a, b, c, d, e, f, g, h;
    if ( upto >= n )
    {
        idx++;
        cout << idx << ". ";
        for (a = 1; a < pos; a++)
        {
            cout << toPrint[a] << " ";
        }
        cout << endl;
        return;
    }
    for (a = upto+1; a <= upto+1; a++)
    {
        isUsed[a] = 1;
        toPrint[pos] = a;
        genPowSet(n, a, pos+1);

        isUsed[a] = 0;
        genPowSet(n, a, pos);
    }
    return;
}
int main()
{
    genPowSet(5, 0, 1);
    return 0;
}
