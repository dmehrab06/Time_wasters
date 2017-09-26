#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int gethour(string a){
    int h=0;
    int l=a.size();
    for(int i=0;i<l;++i){
        if(a[i]==':'){
            break;
        }
        h=h*10+(a[i]-'0');
    }
    return h;
}

int getmin(string a){
    int m=0;
    int l=a.size();
    int idx=-1;
    for(int i=0;i<l;++i){
        if(a[i]==':'){
            idx=i;
            break;
        }
       // h=h*10+(a[i]-'0');
    }
    for(int i=(idx+1);i<l;++i){
        m=m*10+(a[i]-'0');
    }
    return m;
}
int main(){
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        string sehri,iftar;
        cin>>sehri;
        cin>>iftar;
        int sh=gethour(sehri);
        int sm=getmin(sehri);
        int ih=gethour(iftar);
        int im=getmin(iftar);
        int stime=sh*60+sm;
        int itime=ih*60+im;
        if(stime<=itime){
            int dif=itime-stime;
            int difh=dif/60;
            int difm=dif%60;
            printf("Case %d: %d hours %d minutes\n",cs++,difh,difm);
        }
        else{
            int dif=(24*60)-stime+itime;
            int difh=dif/60;
            int difm=dif%60;
            printf("Case %d: %d hours %d minutes\n",cs++,difh,difm);
        }
    }
    return 0;
}
