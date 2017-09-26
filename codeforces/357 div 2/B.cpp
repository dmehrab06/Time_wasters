#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int main(){
    long long int n;
    cin>>n;
    int flag=0;
    for(int x=1;x<=900;++x){
        for(int y=1;y<=9000;++y){
            long long int dd=n-(1234567)*x-(123456)*y;

                if(dd>0 && dd%1234==0){
                    flag=1;
                    break;
                }

        }
        if(flag){
            break;
        }
    }
    if(flag){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
