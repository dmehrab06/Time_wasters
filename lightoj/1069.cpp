#include <stdio.h>
int main(){
    int mypos,liftpos;
    int t;
    int i=1;
    int a;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&mypos,&liftpos);
        a=(mypos-liftpos)*4;
        if(a<0){
            a=a*(-1);
        }
        a=a+(mypos)*4;
        a+=19;
        printf("Case %d: %d\n",i,a);
        i++;
    }
    return 0;
}
