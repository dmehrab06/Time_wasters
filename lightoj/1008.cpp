#include <stdio.h>
#include <math.h>
int main(){
    int t;
    int tt=1;
    long long int n;
    scanf("%d",&t);
    long long int row,col;
    while(t--){
        scanf("%lld",&n);
        long long int low=sqrt(n);
        long long int high=low+1;
        //printf("%lld %lld\n",low,high);
        if(low%2){
            long long int startval=(low)*(low);
            long long int endval=(high*high);
            long long int mid=(startval+endval)/2;
            mid++;
            long long int startrow=1;
            long long int startcol=low;
            long long int endrow=high;
            long long int endcol=1;
            if(startval==n){
                row=startrow;
                col=startcol;
            }
            else{
                startcol++;
                startval++;
                if(n<=mid){
                    long long int a=n-startval;
                    row=startrow+a;
                    col=startcol;
                }
                else{
                    long long int a=endval-n;
                    row=endrow;
                    col=endcol+a;
                }
            }
        }
        else{
            long long int startval=(low)*(low);
            long long int endval=(high*high);
          //  printf("%lld %lld\n",startval,endval);
            long long int mid=(startval+endval)/2;
            mid++;
            //printf("%lld %lld %lld %lld\n",low,high,startval,endval);
            long long int startrow=low;
            long long int startcol=1;
            long long int endrow=1;
            long long int endcol=high;
            if(startval==n){
                row=startrow;
                col=startcol;
            }
            else{
                startrow++;
                startval++;
                if(n<=mid){
                    long long int a=n-startval;
                    row=startrow;
                    col=startcol+a;
                }
                else{
                    long long int a=endval-n;
                    row=endrow+a;
                    col=endcol;
                }
            }
        }
        printf("Case %d: %lld %lld\n",tt,row,col);
        tt++;
    }
    return 0;
}
