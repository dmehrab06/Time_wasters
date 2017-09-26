#include <stdio.h>
int main(){
    long long int x;
    int t;
    int i=1;
    int ones;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&x);
        ones=0;
        while(x){
            ones+=(x%2);
            x=x/2;
        }
        if(ones%2){
            printf("Case %d: odd\n",i);
        }
        else{
            printf("Case %d: even\n",i);
        }
    i++;
    }
    return 0;
}
