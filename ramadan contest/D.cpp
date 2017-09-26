#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int main(){
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int s=a+b+c+d;
        int dis=0;
        if(s>=10000){
            dis=(s*20)/100;
        }
        else if(s>=7500){
            dis=(s*10)/100;
        }
        s-=dis;
        printf("Case %d: %d\n",cs++,s);
    }
    return 0;
}



