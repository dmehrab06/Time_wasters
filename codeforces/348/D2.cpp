#include <bits/stdc++.h>


using namespace std;
int ans[1000007];
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int evenshift=0;
    int oddshift=0;
    int onepos=1;
    int twopos=2;
    for(int i=1;i<=q;++i){
        int type;
        scanf("%d",&type);
        if(type==1){
            int shift;
            scanf("%d",&shift);
            evenshift+=shift;
            oddshift+=shift;
            onepos+=shift;
            twopos+=shift;
            if(evenshift<=0){
                evenshift+=n;
            }
            else if(evenshift>n){
                evenshift-=n;
            }
            if(oddshift<=0){
                oddshift+=n;
            }
            else if(oddshift>n){
                oddshift-=n;
            }
            if(onepos<=0){
                onepos+=n;
            }
            else if(onepos>n){
                onepos-=n;
            }
            if(twopos<=0){
                twopos+=n;
            }
            else if(twopos>n){
                twopos-=n;
            }

        }
        else{
            if(evenshift%2){
                evenshift++;
                oddshift--;
            }
            else{
                evenshift--;
                oddshift++;
            }
            if(twopos%2){
                twopos++;
            }
            else{
                twopos--;
            }
            if(onepos%2){
                onepos++;
            }
            else{
                onepos--;
            }
        }
    }
    int onestart=onepos;
    int todo=1;
    for(int i=onepos;i<=n;i+=2){
        ans[i]=todo;
        todo+=2;
    }
    if(onepos%2){
        onestart=1;
    }
    else{
        onestart=2;
    }
    for(int i=onestart;i<onepos;i+=2){
        ans[i]=todo;
        todo+=2;
    }
    int twostart=twopos;
    todo=2;
    for(int i=twopos;i<=n;i+=2){
        ans[i]=todo;
        todo+=2;
    }
    if(twopos%2){
        twostart=1;
    }
    else{
        twostart=2;
    }
    for(int i=twostart;i<twopos;i+=2){
        ans[i]=todo;
        todo+=2;
    }
    for(int i=1;i<=n;++i){
        printf("%d ",ans[i]);
    }
    printf("\n");
}
