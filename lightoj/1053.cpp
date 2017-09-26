    #include <stdio.h>
    int main(){
        double r;
        int t;
        int i=1;
        long long int a,b,c;
        long long int d,e,f;
        scanf("%d",&t);
        while(t--){
            scanf("%lld %lld %lld",&a,&b,&c);
            d=(c*c)-((a*a)+(b*b));
            e=(a*a)-((b*b)+(c*c));
            f=(b*b)-((a*a)+(c*c));
            if(!d || !e || !f){
                printf("Case %d: yes\n",i);
            }
            else{
                printf("Case %d: no\n",i);
            }
            i++;
        }
        return 0;
    }
     

