#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

long long int modpow(long long int b, long long int x,long long int MD)
{
    if(x==0){
        return 1;
    }
    if(x==1){
        return b;
    }
    long long int hf=modpow(b,x/2,MD);
    if(x%2==0){
        return (hf*hf)%MD;
    }
    else{
        return (((hf*hf)%MD)*b)%MD;
    }
}

int main(){
    long long int n;
    while(scanf("%lld",&n)==1){
        printf("%lld\n",modpow(2,n,10));
    }
    return 0;
}
