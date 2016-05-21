#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;
string ntoa(int b){
    string a="";
    while(b){
        a+=(b%10+'0');
        b/=10;
    }
    reverse(a.begin(),a.end());
    return a;

}

int a[26];

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int l=s.size();
    for(int i=0;i<26;++i){
        a[i]=0;
    }
    for(int i=0;i<l;++i){
        a[s[i]-'a']++;
    }
    int c=0;
    if(l>26){
        printf("-1\n");
    }
    else{
    for(int i=0;i<26;++i){
        if(a[i]>=1){
            c+=(a[i]-1);
        }
    }
    printf("%d\n",c);
    }
    return 0;
}
