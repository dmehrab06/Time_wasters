#include <bits/stdc++.h>
using namespace std;
#define MOD 7
int a, b;
int bigSum(int a, int b, int M)
{
    int x;
    if (b==1) return 1;
    if (b%2==1) return (1+   ((a%M)*(bigSum(a, b-1, M)%M ))%M )%M;
    else
    {
        x = bigSum( ((a%M)*(a%M))%M, b/2, M);
        return ( (x%M) + ((a%M)*(x%M))%M )%M;
    }
}
int main()
{
    while(1)
    {
        cin >> a >> b;
        cout << bigSum(a, b, MOD) << endl << endl ;
    }
    return 0;
}
