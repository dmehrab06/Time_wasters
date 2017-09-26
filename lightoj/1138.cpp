#define MAX 600000000
#include <stdio.h>
 
long long int counzero(long long int n){
    long long int zero=0;
    while(n){
        n=n/5;
        zero+=n;
    }
    return zero;
}
long long int bin_search(long long int low,long long int high, long long int given){
    long long int mid;
    while((high-low)>1){
        mid=(high+low)/2;
        long long int zero;
        zero=counzero(mid);
        if(zero<given){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return high;
 
}
int main(){
    int t;
    int tt=1;
    scanf("%d",&t);
    while(t--){
        long long int n;
        scanf("%lld",&n);
        printf("Case %d: ",tt);
        long long int ans;
        ans=bin_search(1,MAX,n);
        long long int chk=counzero(ans);
        if(chk==n){
            printf("%lld\n",ans);
        }
        else{
            printf("impossible\n");
        }
        tt++;
    }
    return 0;
}
