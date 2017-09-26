#include <stdio.h>
#include <math.h>

float adj[103][103];
float xs[103];
float ys[103];
bool safe[103][103];
int main(){
    //ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    for(int i=0;i<103;++i){
        adj[i][i]=0.0;
    }
    int cs=1;
    while(t--){
        int node;
        scanf("%d",&node);

        for(int i=1;i<=node;++i){
            scanf("%f %f",&xs[i-1],&ys[i-1]);
        }



        for(int i=0;i<node;++i){
            for(int j=i;j<node;++j){
                float d;
                if(i==j)
                d=0.0;
                else{d=(xs[i]-xs[j])*(xs[i]-xs[j])+(ys[i]-ys[j])*(ys[i]-ys[j]);}
                //printf("%.8lf\n",d);
                float w=sqrt(d);
                adj[i+1][j+1]=w;
                safe[i+1][j+1]=(d>100.00000000?false:true);
                adj[j+1][i+1]=w;
                safe[j+1][i+1]=safe[i+1][j+1];
            }
        }


            for(int k=1;k<=node;++k){

                for(int i=1;i<=node;++i){
                    if(k==i)continue;
                    for(int j=1;j<=node;++j){
                        if(k==j || i==j)continue;
                        if(!safe[i][j]){
                            if(safe[i][k] && safe[k][j]){
                                safe[i][j]=true;
                                adj[i][j]=adj[i][k]+adj[k][j];
                            }
                        }
                        else{
                            if((adj[i][k]+adj[k][j]<adj[i][j]) && safe[i][k] && safe[k][j]){

                                adj[i][j]=adj[i][k]+adj[k][j];
                            }
                        }
                    }
                }
            }
            float mx=0.0;
            int f=1;
            for(int i=1;i<=node && f;++i){
                for(int j=i+1;j<=node && f;++j){
                    if(safe[i][j] && adj[i][j]>mx){
                        mx=adj[i][j];
                    }
                    else if(!safe[i][j]){
                        f=0;
                    }
                }
            }
            printf("Case #%d:\n",cs++);
            if(!f)printf("Send Kurdy\n");
            else{
                printf("%.4f\n",mx);
            }
            printf("\n");

    }
    return 0;
}
