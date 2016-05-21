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

int myarr[200005];
int tmparr[200005];
vector<myitem>points;
int main(){
    int n;
    pair<int,int> pp;
    scanf("%d",&n);
    map<int,int>xpair;
    map<int,int>ypair;
    map< pair<int,int>,int>pointcount;
    for(int i=1;i<=n;++i){
        int x,y;
        scanf("%d %d",&x,&y);
        myitem point(x,y);
        pp=pair<int,int>(x,y);
        points.push_back(point);
        pointcount[pp]++;
    }
    for(int i=0;i<n;++i){
        myitem p=points[i];
            xpair[p.x]++;


            ypair[p.y]++;

    }
    long long int way=0;
    for (map<int,int>::iterator it=xpair.begin(); it!=xpair.end(); ++it){
        int nn=it->second;
        way+=NC2(nn);
    }
    for (map<int,int>::iterator it=ypair.begin(); it!=ypair.end(); ++it){
        int nn=it->second;
        way+=NC2(nn);
    }
    for (map< pair<int,int>,int>::iterator it=pointcount.begin(); it!=pointcount.end(); ++it){
        int nn=it->second;
        way-=NC2(nn);
    }
    printf("%I64d\n",way);



}
