#include <stdio.h>
long long int fact[21];
void factorial(){
    fact[0]=1;
    fact[1]=1;
    long long int s=1;
    long long int i=2;
    while(i<=20){
        s=s*i;
        fact[i]=s;
        i++;
    }
}
int take[21];
 
int main(){
    factorial();
    int t;
    scanf("%d",&t);
    int tt=1;
    while(t--){
        long long int n;
        scanf("%lld",&n);
        int i=0;
        while(i<=20){
            take[i]=0;
            i++;
        }
        //int p=make(n,0);
        i=20;
        while(i>=0 && n){
            if(fact[i]<=n){
                take[i]=1;
                n-=fact[i];
            }
            i--;
        }
        if(n==0){
            printf("Case %d: ",tt);
            i=0;
            int coun=0;
            while(i<=20){
 
                if(take[i]==1){
                    if(coun>0){
                        printf("+");
                    }
                    printf("%d!",i);
                    coun++;
                }
                i++;
            }
            printf("\n");
        }
        else{
            printf("Case %d: impossible\n",tt);
        }
        tt++;
    }
    return 0;
}
