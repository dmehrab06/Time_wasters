#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxL (10000>>5)+1
#define GET(x) (mark[(x)>>5]>>((x)&31)&1)
#define SET(x) (mark[(x)>>5] |= 1<<((x)&31))
//int mark[maxL];
//int phi[10005];

int phi(int n)
{
    float result = n;   // Initialize result as n

    // Consider all prime factors of n and for every prime
    // factor p, multiply result with (1 - 1/p)
    for (int p=2; p*p<=n; ++p)
    {
        // Check if p is a prime factor.
        if (n % p == 0)
        {
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (float) p));
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result *= (1.0 - (1.0 / (float) n));

    return (int)result;
}

/*int mpow(int x, int y, int mod) {
	int ret = 1;
	while (y) {
		if (y&1)
			ret = (ret * x)%mod;
		x = (x * x)%mod, y >>= 1;
	}
	return ret;
}
int mmpow(int idx, int A[], int m, int n)  {
	if (idx == n - 1)
		return A[idx]%m;
	int p = mmpow(idx+1, A, phi[m], n) + phi[m];
	return mpow(A[idx], p, m);
}
int main() {
	sieve();
	int val;
	scanf("%d",&val);
	int n = 3 , m = 1000000007 , A[32], cases = 0;
	A[0]=3; A[1]=3;
		printf("Case #%d: %d\n", ++cases, mmpow(0, A, m, n));
	}
	return 0;
}*/
int main(){
    cout<<phi(1000000007)<<"\n";
}
