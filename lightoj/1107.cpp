#include <stdio.h>
int main(){
    int x1,y1,x2,y2;
    int x,y;
    int query;
    int t;
    int i=1;
    int a;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&query);
        printf("Case %d:\n",i);
        while(query--){
            scanf("%d %d",&x,&y);
            if(x>=x1 && x<=x2 && y>=y1 && y<=y2){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        i++;
    }
    return 0;
}
