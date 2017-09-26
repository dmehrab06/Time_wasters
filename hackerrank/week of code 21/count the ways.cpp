#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;


struct info{
    int v;
    int zer;
    info(int a, int b){
        v=a;
        zer=b;
    }
};
int complement[51][51];
int graph[51][51];
int vis[51];
int val[51];
long long int twopows[51];
void init(){
    for(int i=0;i<51;++i){
        vis[i]=0;
    }
    for(int i=0;i<51;++i){
        for(int j=0;j<51;++j){
           graph[i][j]=0;
           graph[j][i]=0;
            complement[i][j]=1;
            complement[j][i]=1;
        }
    }
    twopows[0]=1;
    for(int i=1;i<51;++i){
        twopows[i]=twopows[i-1]<<1;
    }
}

info dfs(int cur, int n){
   // printf("rec in %d\n",cur);
    int f=1;
    for(int i=1;i<=n;++i){
        if(graph[cur][i] && vis[i]){
            f=0;
            break;
        }
    }

    int vl=val[cur];
    if(!f){
        vl=0;
    }
    int z=0;
    if(vl==0){
        z=1;
    }
    vis[cur]=1;
    //for(int i=1;i<=n;++i){
      //  if(graph[cur][i] && vis[i]!=1){
        //    vis[i]+=2;
        //}
   // }
    for(int i=1;i<=n;++i){
        if(complement[cur][i] && !vis[i]){
            info inf=dfs(i,n);
            vl+=inf.v;
            z+=inf.zer;
        }
    }
    //for(int i=1;i<=n;++i){
      //  if(graph[cur][i] && vis[i]!=1){
        //    vis[i]-=2;
        //}
    //}
    info ii(vl,z);
    vis[cur]=0;
    return ii;
}

int main(){
    init();
    int n,m;
    scanf("%d %d",&n,&m);
    int s=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&val[i]);
        s+=val[i];
    }
    if(false){
        //taile ekta kechal ase
        //2^n hobe ans
        long long int s=(long long int)1<<(long long int)n;
        printf("0 %lld\n",s);
    }
    else{
        for(int i=1;i<=m;++i){
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u][v]=1;
            graph[v][u]=1;
            complement[u][v]=0;
            complement[v][u]=0;
        }
        int mxval=-1;
        long long int way=0;
        for(int i=1;i<=n;++i){
            if(!vis[i]){
               // printf("going in %d\n",i);
                info curinf=dfs(i,n);
               // printf("after dfs\n");
               // for(int j=1;j<=n;++j){
                 //   printf("%d ",vis[j]);
               // }
               // printf("\n");
                int curval=curinf.v;
                int curzer=curinf.zer;
                if(curval>mxval){
                    mxval=curval;
                    way=1;
                }
                else if(curval==mxval){
                    way+=1;
                }
            }
        }
        printf("%d %lld\n",mxval,way);
    }
    return 0;
}
