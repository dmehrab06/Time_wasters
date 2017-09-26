#include <stdio.h>
int main(){
    int t,n,s;
    scanf("%d",&t);
    int i=1;
    while(t--){
        s=0;
        scanf("%d",&n);
        int dust;
        while(n--){
            scanf("%d",&dust);
            if(dust>=0){
                s+=dust;
            }
        }
        printf("Case %d: %d\n",i,s);
        i++;
    }
    return 0;
}
