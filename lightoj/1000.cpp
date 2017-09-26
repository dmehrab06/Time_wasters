#include <stdio.h>
int main(){
    int t,a,b;;
    scanf("%d",&t);
    int i=1;
    while(t--){
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",i,(a+b));
        i++;
    }
}
