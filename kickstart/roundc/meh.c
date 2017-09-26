#include <stdio.h>
int main(){
    int n;
    int i;
    for(i=1;i<=3;++i){
        scanf("%d",&n);
        if(n%2==0){
            printf("even");
        }
        else{
            printf("odd");
        }
    }

    return 0;
}
