#include <stdio.h>
int main(){
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&a);
        b=a/2;
        printf("%d %d\n",b,(a-b));
    }
}
