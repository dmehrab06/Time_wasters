#include <bits/stdc++.h>
#define MAXIT 2000
#define MAXN 50
using namespace std;

int arr[100005];

long long anger(int n, int chef_pos){
    long long a = 0;
    for(int i = chef_pos, j = 1; i<=n; ++i, ++j){
        a = a+(arr[i]/j);
    }
    return a;
}

int main(){
    /*int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; ++cs){
        int n; long long k;
        scanf("%d %lld",&n,&k);
        for(int i = 1; i<=n; ++i){
            scanf("%d",&arr[i]);
        }
        int mxpos = n+1;
        for(int i = 1; i<=min(MAXIT,n); ++i){
            if(anger(n,i)<=k){
                mxpos = i;
                break;
            }
        }
        printf("%d\n",mxpos);
    }*/
    for(int i = 1; i<=MAXN; ++i){
        cout<<i<<": ";
        for(int j = 1; j<=i; ++j){
            printf("%4d",i/j);
        }
        cout<<"\n";
    }
    return 0;
}