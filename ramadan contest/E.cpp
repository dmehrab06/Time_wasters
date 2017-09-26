#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

long long int frombtodec(string a, int base){
    int l=a.size();
    long long int s=0;
    for(int i=0;i<l;++i){
        int curdig;
        if(ISCAP(a[i])){
            curdig=a[i]-'A'+10;
        }
        else{
            curdig=a[i]-'0';
        }
        s=s*(long long int)base+(long long int)curdig;
    }
    return s;
}

string fromdectobase(int base, long long int d){
    string mynum="";
    long long int t=d;
    while(t){
        int cur=t%base;
        char a;
        if(cur>=10){
            a=(cur-10)+65;
        }
        else{
            a=cur+48;
        }
        mynum.push_back(a);
        t/=base;
    }
    reverse(mynum.begin(),mynum.end());
   if(mynum.size()==0)mynum="0";
    return mynum;
}

int main(){
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        string s;
        int n,m;
        cin>>s>>n>>m;
        long long int d=frombtodec(s,n);
        string ans=fromdectobase(m,d);
        cout<<ans<<"\n";
    }
    return 0;
}



