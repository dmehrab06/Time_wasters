#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

struct info{
    int p;
    int d;
    info(int a, int b){
        p=a;
        d=b;
    }
};

int par[200005];
int dis[200005];

info findpar(int a){
    if(par[a]==a){
        return info(a,dis[a]);
    }
    info b=findpar(par[a]);
    dis[a]=dis[a]+b.d;
    par[a]=b.p;
    return info(par[a],dis[a]);
}

void upd(int a , int b){
    par[a]=b;
    dis[a]=abs(a-b)%1000;
}

void init(int n){
    for(int i=1;i<=n;++i){
        par[i]=i;
        dis[i]=0;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        init(n);
        char type[3];
        while(true){
            scanf("%s",type);
            if(type[0]=='O')break;
            if(type[0]=='E'){
                int val;
                scanf(" %d",&val);
                info a=findpar(val);
                printf("%d\n",a.d);
            }
            else if(type[0]=='I'){
                int a,b;
                scanf(" %d %d",&a,&b);
                upd(a,b);
            }
        }
    }
    return 0;
}

