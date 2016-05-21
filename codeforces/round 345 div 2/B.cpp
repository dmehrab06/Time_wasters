#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int GCD(int a,int b){
    return a==0?b:GCD(b%a,a);
}

string ntoa(int b){
    string a="";
    while(b){
        a+=(b%10+'0');
        b/=10;
    }
    reverse(a.begin(),a.end());
    return a;

}

struct myitem{
    int x;
    int y;
    myitem(){
        x=0;
        y=0;
    }
    myitem(int a, int b){
        x=a;
        y=b;
    }
    bool operator=(const myitem &b){
        return x==b.x && y==b.y;

    }
};


//int representative[20005];


long long int NC2(int n){
    if(n<2)return 0;
    long long int huda=n;
    huda=huda*(huda-1);
    return huda/2;
}

int ara[1002];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<1002;++i){
        ara[i]=0;
    }
    for(int i=1;i<=n;++i){
        int c;
        scanf("%d",&c);
        ara[c]++;
    }
    vector<int>counts;
    for(int i=0;i<1002;++i){
        if(ara[i]!=0){
            counts.push_back(ara[i]);
        }
    }
    sort(counts.begin(),counts.end());
    int l=counts.size();
    int nn=l;
    int tot=0;
    for(int i=0;i<l;++i){
        int now=counts[i];
        tot+=(nn-1)*now;
        for(int j=i+1;j<l;++j){
            counts[j]-=now;
        }
        nn--;
    }
    cout<<tot<<"\n";

}
