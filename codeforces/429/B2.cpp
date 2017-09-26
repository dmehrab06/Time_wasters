
#include <bits/stdc++.h>
using namespace std;
char s[100005];

int b[26]; int f[26];

void calc(int l){
    for(int i=0;i<26;++i)b[i]=-1;
    for(int i=0;i<l;++i){
        if(b[s[i]-'A']==-1) b[s[i]-'A']=i;
        f[s[i]-'A']=i;
    }
}

int calc2(int l){
    int c = 0, m = 0;
    for(int i=0;i<l;++i){
        int val = s[i]-'A';
        if(b[val]==i){
            c++; if(c>m)m=c;
        }
        else if(f[val]==i)c--;
    }
    return m;
}

int main(){
    int n,k;
    cin>>n>>k;
    scanf("%s",s);
    calc(n);
    int ans = calc2(n);
    if(ans>k) cout<<"yes\n";

    else cout<<"no\n";

    return 0;
}
