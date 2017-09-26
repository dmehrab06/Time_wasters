#include <stdio.h>
int main(){
    int low,high,high2,high0,low0,low2,t,tt;
    tt=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&low,&high);
        int temp;
 
        if(low<high){
            temp=high;
            while((temp%3)!=2){
                temp--;
            }
            high2=temp;
            temp=high;
            while((temp%3)!=0){
                temp--;
            }
            high0=temp;
            temp=low;
            while((temp%3)!=2){
                temp++;
            }
            low2=temp;
            temp=low;
            while((temp%3)!=0){
                temp++;
            }
            low0=temp;
            int a;
            a=(high0-low0)/3;
            a=a+(high2-low2)/3;
            a+=2;
            printf("Case %d: %d\n",tt,a);
        }
        else{
            if(low%3==0 || low%3==2){
                printf("Case %d: %d\n",tt,1);
            }
            else{
                printf("Case %d: %d\n",tt,0);
            }
        }
        tt++;
    }
    return 0;
}
