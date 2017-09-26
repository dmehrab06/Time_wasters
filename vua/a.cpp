#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,T,W,N,M,c;
    scanf("%d",&T);
    if(T<=10000)
    for(i=1;i<=T;i++)
    {
        scanf("%d",&W);
        c=0;
        printf("Case %d: ",i);
        for(j=2;j<sqrt(W);j++)
        {
            if(W%j==0){
                M=W/j;
                if(j%2==0&&M%2!=0){
                    N=M;
                    M=j;
                    c=1;
                    printf("%d %d\n",N,M);
                    break;
                }
                else if(j%2!=0&&M%2==0){
                      N=j;
                      c=1;
                      printf("%d %d\n",N,M);
                      break;
                }
            }
        }
        if(c==0)
            printf("Impossible\n");
    }
    return 0;
}
