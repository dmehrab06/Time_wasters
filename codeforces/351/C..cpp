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

int lastinserted[5003];
int dominant[5003];
int color[5003];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&color[i]);
        dominant[i]=0;
    }
    set< pair<int,int> >::iterator it;
    for(int i=1;i<=n;++i){
        set< pair<int,int> >all;
        for(int j=1;j<=n;++j){
            lastinserted[j]=0;
        }
        for(int j=i;j<=n;++j){
            int curcolor=color[j];
            int lastfreq=lastinserted[curcolor];
            if(lastfreq!=0){
                pair<int,int>toextract(-lastfreq,curcolor);
                all.erase(toextract);
            }
            lastfreq++;
            pair<int,int>toinsert(-lastfreq,curcolor);
            all.insert(toinsert);
            it=all.begin();
            int colorfound=it->second;
            dominant[colorfound]++;
        }
    }
    for(int i=1;i<=n;++i){
        printf("%d ",dominant[i]);
    }
    printf("\n");
    return 0;

}
