#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)==1){
    int mn=1000000007;
    while(n--){
        int d,c;
        scanf("%d %d",&d,&c);
        int minneeded=d/5;
        if(d%5){
            minneeded++;
        }
        if(minneeded<=11){
            if(c<mn){
                mn=c;
            }
        }

    }
    if(mn==1000000007){
            printf("Bad luck\n");
        }
        else{
            printf("%d\n",mn);
        }
    }
    return 0;
}



