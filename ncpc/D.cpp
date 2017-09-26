/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("input.txt","r",stdin);
#define PI acos(-1.0)
#define MAX 100005
#define MOD 1000000007
#define EPS 1e-9

bool sieve[10000015]={0,};
int prime[671000]={0,},primo=0;

long long int ggcd(long long int a, long long int b);

long long int ggcd(long long int a, long long int b)
{
    if(a==0){
        return b;
    }
    return ggcd(b%a,a);
}

int main ()
{
    long long int T,tp=1,gcd,a,b,i,j,gum=3200,tempA,factor,product,ans;

    for(i=2;i<gum;i++)
    {
        if(sieve[j]==0)
        {
            for(j=i*i;j<10000003;j+=i)
            {
                sieve[j]=1;
            }
        }
    }

    for(i=2;i<10000003;i++)
    {
        if(sieve[i]==0)
            prime[primo++]=i;
    }

    //for(i=0;i<10;i++)
        //printf("%d\n",prime[i]);

    scanf("%lld",&T);

    while(T--)
    {
        scanf("%lld%lld",&a,&b);

        gcd=0;

        tempA=a;

        for(i=0;i<primo;i++)
        {
            factor=0;

            if(prime[i]>tempA)
                break;

            while(tempA % prime[i] ==0)
            {
                tempA/=prime[i];
                factor++;
            }

            if(factor>0)
            {
                if(gcd==0)
                    gcd=factor;
                else
                    gcd=ggcd(gcd,factor);
            }
        }


        if(tempA!=1)
        {
            factor=1;

            if(gcd==0)
                gcd=factor;
            else
                gcd=ggcd(gcd,factor);
        }

        //printf("%lld\n",gcd);


        product=gcd*b;

        tempA=product;
        ans=1;

        for(i=0;i<primo;i++)
        {
            factor=0;

            if(prime[i]>tempA)
                break;

            while(tempA % prime[i] ==0)
            {
                tempA/=prime[i];
                factor++;
            }

            if(factor>0)
            {
                ans *= (factor+1);
            }
        }

        if(tempA!=1)
        {
            factor=1;

            ans *= (factor+1);
        }

        printf("Case %lld: %lld\n",tp,ans-1);
        tp++;


    }

}




/*a = prime factorization

a = p1^k1 ....

k1,k2 = gcd
gcd*b = number of factor - 1

(2^2 * 3^4)^3
=(2*3)^6
=(2*3)^6

(a+1)*(b+1)*(c+1)*/


/*(2^2 * 3^2 )^3 = 3
(2^2 * 3^2 * 5^2 )^3 = 1 */
