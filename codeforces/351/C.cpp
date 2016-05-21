#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int indiv2[100006];
int indiv1[100006];

int cnt[5003];
int curdominant,curdominantcolor;
int dominant[5003];
int color[5003];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&color[i]);
        dominant[i]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cnt[j]=0;
        }
        curdominant=0;
        curdominantcolor=1000000007;
        for(int j=i;j<=n;++j){
            int curcolor=color[j];
            cnt[curcolor]++;
            if(cnt[curcolor]>curdominant){
                curdominant=cnt[curcolor];
                curdominantcolor=curcolor;
                //dominant[curcolor]++;
            }
            else if(cnt[curcolor]==curdominant){
                if(curcolor<curdominantcolor){
                    curdominantcolor=curcolor;
                  //  dominant[curcolor]++;
                }
            }

            dominant[curdominantcolor]++;

        }
    }
    for(int i=1;i<=n;++i){
        printf("%d ",dominant[i]);
    }
    printf("\n");
    return 0;

}
