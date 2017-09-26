#include <stdio.h>
long long int sum(long long int a,long long int n,long long int d){
    long long int p=2*a;
    long long int q=(n-1)*d;
    long long int r=p+q;
    long long int s=(p+q)*n;
    return s/2;
}
int main(){
    int t;
    int i=1;
    long long int n,m;
    long long int minsum,totalminsum,maxsum,totalmaxsum;
    long long int nn,d;
    long long int baka,result;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&n,&m);
        nn=n/(2*m);
        d=(2*m);
       // printf("%lld %lld\n",nn,d);
        minsum=sum(1,nn,d);
        baka=nn*((m*(m-1))/2);
        totalminsum=(m*minsum)+baka;
        maxsum=sum((1+m),nn,d);
      //  printf("%lld %lld\n",maxsum,minsum);
        totalmaxsum=(m*maxsum)+baka;
        result=totalmaxsum-totalminsum;
        //printf("%lld %lld\n",totalmaxsum,totalminsum);
        printf("Case %d: %lld\n",i,result);
        i++;
    }
    return 0;
}
