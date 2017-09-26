#include <bits/stdc++.h>

using namespace std;

int toi(string a){
    int s=0;
    int l=a.size();
    for(int i=0;i<l;++i){
        s=s*10+a[i]-'0';
    }
    return s;
}

string zerocut(string s){
    int l=s.size();
    int f=0;
    string res="";
    for(int i=0;i<l;++i){
        if(s[i]!='0'){
            res+=s[i];
            f=1;
        }
        if(s[i]=='0'){
            if(f){
                res+=s[i];
            }
        }
    }
    if(res.size()==0)res="0";
    return res;
}

int main(){
    string s;
    cin>>s;
    string a="",d="",b="";
    int i=0;
    int l=s.size();
    while(s[i]!='.'){
        a+=s[i];
        i++;
    }
    //int decpos=i;
    i++;
    while(s[i]!='e'){
        d+=s[i];
        i++;
    }
    i++;
    while(i<l){
        b+=s[i];
        i++;
    }
    int bval=toi(b);
    int dlen=d.size();
    if(bval>=dlen){
      //dec point thakbe na
      string res=a+d;
      int extra=bval-dlen;
      for(int i=1;i<=extra;++i){
        res.push_back('0');
      }
      string res2=zerocut(res);
      cout<<res2<<"\n";
    }
    else{
        int outside=bval;
        string dexit="";
        for(int i=0;i<outside;++i){
            dexit+=d[i];
        }
        string newd="";
        for(int i=outside;i<dlen;++i){
            newd+=d[i];
        }
        string res=zerocut(a+dexit);
        string chk=zerocut(newd);
        if(chk=="0"){
            cout<<res<<"\n";
        }
        else{
            res.push_back('.');
            res+=newd;
            cout<<res<<"\n";
        }
    }
    return 0;
}
