#include <cstdio>
#include <algorithm>
long long int y[50005];
int main(){
    int t;
    scanf("%d",&t);
    int tt=1;
    while(t--){
        scanf("\n");
        int x;
        int n,w;
        scanf("%d %d",&n,&w);
        for(int i=0;i<n;++i){
            scanf("%d %lld",&x,&y[i]);
        }
        std::sort(y,y+n);
        /*for(int i=0;i<=n;++i){
            printf("%d ",y[i]);
        }
        printf("\n"); //sort thik moto hoise?*/
        int j=0;
        int moves=0;
        while(j<n){
            long long int a=y[j]+w;
            while(y[j]<=a){
                j++;
            }
            moves++;
        }
        printf("Case %d: %d\n",tt,moves);
        tt++;
 
    }
    return 0;
}
