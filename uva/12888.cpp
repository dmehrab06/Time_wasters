#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        if(n>m){
            swap(n,m);
        }
        long long int s=0;
        for(int i=2;i<=n;++i){
            int a=m/i;
            long long int b=m-a;
            s+=b;
        }
        s+=m;
        printf("%lld\n",s);
    }
    return 0;
}
