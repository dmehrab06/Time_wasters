#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxL (10000>>5)+1
#define GET(x) (mark[(x)>>5]>>((x)&31)&1)
#define SET(x) (mark[(x)>>5] |= 1<<((x)&31))

int phi(int n)
{
    int result = n;
    for (int p=2; p*p<=n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
int main()
{
    int n;

    while(cin>>n){
        cout<<phi(n)<<"\n";
    }
    return 0;
}
