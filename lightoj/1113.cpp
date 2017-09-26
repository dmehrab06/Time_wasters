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
    int h;
    int w;
    myitem(int a, int b){
        h=a;
        w=b;
        if(h>w){
            int t=h;
            h=w;
            w=t;
        }
    }
};
 
bool mycompare (myitem a, myitem b){
    if(a.h==b.h)return a.w<b.w;
    return a.h<b.h;
}
 
 
int main(){
    int t;
    cin>>t;
    int c=1;
    while(t--){
    cout<<"Case "<<c++<<":\n";
    stack<string>backpages;
    stack<string>frontpages;
    stack<string>emptystack;
    string curpage="http://www.lightoj.com/";
    string command, page;
    while(cin>>command && command!="QUIT"){
        if(command=="VISIT"){
            cin>>page;
            frontpages=emptystack;
            backpages.push(curpage);
            cout<<page<<"\n";
            curpage=page;
        }
        else if(command=="BACK"){
            if(backpages.empty()){
                cout<<"Ignored\n";
            }
            else{
                frontpages.push(curpage);
                string t=backpages.top();
                backpages.pop();
                curpage=t;
                cout<<curpage<<"\n";
            }
        }
        else if(command=="FORWARD"){
            if(frontpages.empty()){
                cout<<"Ignored\n";
            }
            else{
                backpages.push(curpage);
                string t=frontpages.top();
                frontpages.pop();
                curpage=t;
                cout<<curpage<<"\n";
            }
        }
    }
    }
    return 0;
}
