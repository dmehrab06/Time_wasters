#include <stdio.h>
int main(){
    long long int x;
    int t;
    int i=1;
    long long int odd,even;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&x);
        if(x%2){
            printf("Case %d: Impossible\n",i);
        }
        else{
 
            even=2;
            odd=x/2;
            while(!(odd%2)){
                even*=2;
                odd=odd/2;
            }
            printf("Case %d: %lld %lld\n",i,odd,even);
 
 
    }
    i++;
    }
    return 0;
}
