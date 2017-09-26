#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;




int main(){
    //ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    int cs=1;
    long long int bmax;
    long long int d;
    while(t--){
        scanf("%lld %lld",&bmax,&d);
        printf("Case %d: %lld\n",cs++,(bmax-1)/d);
    }
    return 0;
}
