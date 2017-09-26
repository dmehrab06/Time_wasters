#include <stdio.h>
#include <stdlib.h>
long int adj[103][103];


int main()
{
   int C,S,Q;
   int cs=1;
   int fflag=1;
   while(scanf("%d %d %d",&C,&S,&Q)==3 && !(C==0 && S==0 && Q==0)){
        for(int i=1;i<=C;++i){
            for(int j=1;j<=C;++j){
                if(i==j){
                    adj[i][j]=0;
                }
                else{
                    adj[i][j]=20000000000;
                }
            }
        }
        for(int i=1;i<=S;++i){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            adj[u][v]=(long int)w;
            adj[v][u]=(long int)w;
        }
        for(int k=1;k<=C;++k){
            for(int i=1;i<=C;++i){
                for(int j=1;j<=C;++j){
                    if(max(adj[i][k],adj[k][j])<adj[i][j]){
                        adj[i][j]=max(adj[i][k],adj[k][j]);
                    }
                }
            }
        }
        if(fflag){
            fflag=0;
        }
        else{
            printf("\n");
        }
        printf("Case #%d\n",cs++);
        for(int i=1;i<=Q;++i){
            int src,dest;
            scanf("%d %d",&src,&dest);
            if(adj[src][dest]==20000000000){
                printf("no path\n");
            }
            else{
                printf("%ld\n",adj[src][dest]);
            }
        }

   }
   return 0;
}
