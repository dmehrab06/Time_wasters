#include <stdio.h>
#include <string.h>
int main(){
    char palin[30];
    int t;
    int ii=1;
    scanf("%d",&t);
    if(t!=0){
        scanf(" ");
    }
    while(t--){
        gets(palin);
        int i=0;
        int j=strlen(palin)-1;
        while(i<=j){
            if(palin[i]!=palin[j]){
                break;
            }
            i++;
            j--;
        }
        if(i>j){
            printf("Case %d: Yes\n",ii);
        }
        else{
            printf("Case %d: No\n",ii);
        }
        ii++;
    }
    return 0;
}
