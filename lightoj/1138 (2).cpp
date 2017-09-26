#define MAX 600000000
#include <stdio.h>
 
int counzero(int n){
    int zero=0;
    while(n>4){
        n=n/5;
        zero+=n;
    }
    return zero;
}
int bin_search(int low,int high, int given){
    int mid;
    while((high-low)>1){
        mid=(high+low)/2;
        int zero;
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
        int n;
        scanf("%d",&n);
        printf("Case %d: ",tt);
        int ans;
        ans=bin_search(1,MAX,n);
        int chk=counzero(ans);
        if(chk==n){
            printf("%d\n",ans);
        }
        else{
            printf("impossible\n");
        }
        tt++;
    }
    return 0;
}
