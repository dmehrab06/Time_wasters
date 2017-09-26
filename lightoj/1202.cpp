#include <stdio.h>
int main(){
    int x1,y1,x2,y2;
    int t;
    int tt=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int a=(x1+y1)%2;
        int b=(x2+y2)%2;
        if(a!=b){
            printf("Case %d: impossible\n",tt);
        }
        else{
            int inc=(x2-x1);
            int minc=inc*(-1);
            int try1=y1+inc;
            int try2=y1+minc;
            if(try1==y2 || try2==y2){
                printf("Case %d: 1\n",tt);
            }
            else{
                printf("Case %d: 2\n",tt);
            }
        }
        tt++;
 
    }
    return 0;
}
