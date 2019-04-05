/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

bool siever[2000007];

vector<int>primes;

bool ispal(int v){
    string pp = "";
    while(v){
        pp.PB(v%10+'0');
        v/=10;
    }
    FREP(i,0,pp.size()-1){
        if(pp[i]!=pp[pp.size()-1-i])return false;
    }
    return true;
}

long long findDigits(int n)
{
    // factorial of -ve number
    // doesn't exists
    if (n < 0)
        return 0;

    // base case
    if (n <= 1)
        return 1;

    // Use Kamenetsky formula to calculate
    // the number of digits
    double x = ((n * log10(n / M_E) +
                 log10(2 * M_PI * n) /
                 2.0));

    return floor(x) + 1;
}

void sieve(){
    //int totprime = 0;
    for(int i = 2;i<=2000006; ++i){
        if(!siever[i]){
            if(ispal(i)){
                primes.PB(i);
            }
            for(int j = (i+i); j<=2000006; j+=i){
                siever[j] = true;
            }
        }
    }
    //return totprime;
}

int main(){
    sieve();
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int n;
        scanf("%d",&n);
        vector<int>::iterator it;
        it = lower_bound(primes.begin(),primes.end(),n+1);
        int p = *it;
        printf("%lld\n",findDigits(p));
    }
    return 0;
}
