#include <stdio.h>
 
int bin[35];
void refresh(){
    int i=0;
    for(i=0;i<35;++i){
        bin[i]=0;
    }
}
 
void trans(long long int n){
    int i=0;
    long long int a;
    while(n){
        a=n%2;
        n/=2;
        bin[i]=a;
        i++;
    }
}
long long int pow2(int a){
    long long int s=1;
    int i=1;
    while(i<=a){
        s*=2;
        i++;
    }
    return s;
}
int main(){
    int t;
    scanf("%d",&t);
    int tt=1;
    while(t--){
        long long int n;
        scanf("%lld",&n);
        refresh();
        trans(n);
        long long int start;
        start=pow2(33);
        int unused1=0;
        int i=0;
        while(1){
            if(bin[i]==1){
                if(bin[i+1]==0){
                    bin[i+1]=1;
                    bin[i]=0;
                    break;
                }
                else{
                    unused1++;
                }
            }
            i++;
        }
        long long int number=0;
        int pos=33;
        while(pos>=(i+1)){
            if(bin[pos]==1){
                number+=start;
            }
            start/=2;
            pos--;
        }
        long long int toadd;
        toadd=(pow2(unused1))-1;
        number+=toadd;
        printf("Case %d: %lld\n",tt,number);
        tt++;
    }
    return 0;
}
