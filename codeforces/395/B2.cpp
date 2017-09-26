#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=200000+10;
int a[maxn],b[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
        int f=n/2+n%2;
        for(int k=1;k<=f;k++)
        {
            if(k%2==1)
            {
                b[k]=a[n-k+1];
                b[n-k+1]=a[k];
            }
            else
            {
                b[k]=a[k];
                b[n-k+1]=a[n-k+1];
            }
        }

    for(int j=1; j<=n; j++)
    {
        if(j!=1)
            printf(" ");
        printf("%d",b[j]);
    }
    puts("");
}
