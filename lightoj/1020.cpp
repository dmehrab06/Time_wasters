#include <stdio.h>
#include <math.h>

char play[10];
int main(){
  //  double r;
    int t;
    scanf("%d",&t);
    int cs=1;
    int n;
    while(t--){
        scanf("%d %s",&n,play);
        printf("Case %d: ",cs++);
        if(play[0]=='A'){
            if((n-1)%3==0){
                printf("Bob\n");
            }
            else{
                printf("Alice\n");
            }
        }
        else{
            if(n%3==0){
                printf("Alice\n");
            }
            else{
                printf("Bob\n");
            }
        }
    }
    return 0;
}
