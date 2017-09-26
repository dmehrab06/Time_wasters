#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;


struct fibo{
    int val;
    int lev;
    int lastused;
    fibo(int a, int b, int c){
        val=a;
        lev=b;
        lastused=c;
    }
};

int chevonacci[100];
int MD=1000000007;
int dp[10004][12][20];


int coin(int value, int step,int lastused){
    if(step==0){
        if(value==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(value==0){
        if(step!=0){
            return 0;
        }
    }
    if(dp[value][step][lastused]!=-1)return dp[value][step][lastused];
    int ret1=0;
    for(int i=lastused;i<20;++i){
        if(chevonacci[i]>value){
            break;
        }
        else{
            ret1+=coin(value-chevonacci[i],step-1,i);
            ret1%=MD;
        }
    }
    dp[value][step][lastused]=ret1;
    return dp[value][step][lastused];
}


int bfs(int val,int step){
    queue<fibo>all;
    fibo src(val,step,0);
    int res=0;
    all.push(src);
    while(!all.empty()){
        fibo a=all.front();
        all.pop();
        int curval=a.val;
        int curlev=a.lev;
        int curused=a.lastused;
        if(curlev==0){
            if(curval==0){
                res++;
            }
        }
        else{
            for(int i=curused;i<=44;++i){
                if(chevonacci[i]>curval){
                    break;
                }
                else{
                    fibo b(curval-chevonacci[i],curlev-1,i);
                    all.push(b);
                }
            }
        }
    }
    return res;
}

int main(){
    chevonacci[0]=1;
    chevonacci[1]=2;
    for(int i=2;i<100;++i){
        chevonacci[i]=chevonacci[i-1]+chevonacci[i-2];
    }
    int t;
    scanf("%d",&t);
    for(int i=0;i<10004;++i){
        for(int j=0;j<12;++j){
            for(int k=0;k<20;++k)
            dp[i][j][k]=-1;
        }
    }
    while(t--){
        int val,step;
        scanf("%d %d",&val,&step);
        int ans=0;
        if(true){
            ans=coin(val,step,0);
        }
        else{
          //  int g;
            ans=bfs(val,step);
        }
        printf("%d\n",ans);
    }
    //ei 42 ta nia e mainly matha ghamano
    return 0;
}
