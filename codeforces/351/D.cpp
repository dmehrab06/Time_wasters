#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int road1[1005];
int road2[1005];
int used[1005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i){
        used[i]=0;
    }
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(n==4){
        printf("-1\n");
    }
    else{
        int req=n+1;
        if(k<req){
            printf("-1\n");
        }
        else{
            road1[1]=a;
            road1[n]=b;
            road1[n-1]=d;
            road1[n-3]=c;
            used[a]=1;
            used[b]=1;
            used[c]=1;
            used[d]=1;
            int unusedfirst=-1;
            for(int i=n;i>=1;--i){
                if(!used[i]){
                    unusedfirst=i;
                    break;
                }
            }
            road1[n-2]=unusedfirst;
            used[unusedfirst]=1;
            int start=2;
            for(int i=1;i<=n;++i){
                if(!used[i]){
                    road1[start]=i;
                    used[i]=1;
                    start++;
                }
            }
            //road1 complete;
            int road2start=1;
            for(int i=(n-3);i>=1;--i){
                road2[road2start]=road1[i];
                road2start++;
            }
            road2[road2start]=unusedfirst;
            road2[road2start+1]=b;
            road2[road2start+2]=d;
            for(int i=1;i<=n;++i){
                printf("%d ",road1[i]);
            }
            printf("\n");
            for(int i=1;i<=n;++i){
                printf("%d ",road2[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
