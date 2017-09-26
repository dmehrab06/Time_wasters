#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i){
        int a;
        scanf("%d",&a);
        if(a%6==0){
            printf("Misha\n");
        }
        else{
            printf("Chef\n");
        }
    }
    return 0;
}
