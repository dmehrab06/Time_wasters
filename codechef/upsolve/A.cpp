//ds--
//algo--implementation

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))

using namespace std;

int main(){
    int reportto[100006];
    int n;

    cin>>n;
    for(int i=0;i<=n;++i){
        reportto[i]=0;
    }
    int tot=n;
    while(n--){
        int a;
        cin>>a;
        reportto[a]++;

    }
    for(int i=1;i<=tot;++i){
        if(reportto[i]==0){
            cout<<i<<" ";
        }
    }
    cout<<"\n";

}
