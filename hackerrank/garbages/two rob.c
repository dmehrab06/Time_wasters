#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int src[1002];
int des[1002];
int dp[1002][1002][1002];

int min(int a, int b){
    return a<b?a:b;
}
int func(int i, int r1, int r2,int n){
    if(i>n){
        return 0;
    }
    if(r1==-1){
        return func(i+1,des[i],r2,n);
    }
    int dis1=999999999;
    int dis2=999999999;
    if(r2==-1){
        dis1=func(i+1,r1,des[i],n);
        dis2=abs(r1-src[i])+func(i+1,des[i],r2,n);
        return min(dis1,dis2);
    }
    if(dp[i][r1][r2]!=-1){
        return dp[i][r1][r2];
    }
    dis1=abs(r1-src[i])+func(i+1,des[i],r2,n);
    dis2=abs(r2-src[i])+func(i+1,r1,des[i],n);
    dp[i][r1][r2]=min(dis1,dis2);
    return dp[i][r1][r2];
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n;
        scanf("%d %d",&m,&n);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                for(int k=1;k<=m;++k){
                    dp[i][j][k]=-1;
                }
            }
        }
        int dis=0;
        for(int i=1;i<=n;++i){
            scanf("%d %d",&src[i],&des[i]);
           dis+=abs(src[i]-des[i]);
        }
        int thendis=func(1,-1,-1,n);
        printf("%d\n",thendis+dis);
    }
    return 0;

}
