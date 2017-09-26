#include <bits/stdc++.h>

using namespace std;

//int xpointsexist[200005];

int szneeded(long long int d){
    long long int t=d;
    string a="";
    while(t){
        a.push_back(t%7+'0');
        t/=7;
    }
    if(a.size()==0)a.push_back('0');
    int l=a.size();
    return l;
}

long long int sevtodec(string a){
    int l=a.size();
    long long int ans=0;
    for(int i=0;i<l;++i){
        ans=ans*7+a[i]-'0';
    }
    return ans;
}

string dectosev(long long int d, int sz){
    long long int t=d;
    string a="";
    while(t){
        a.push_back(t%7+'0');
        t/=7;
    }
    int l=a.size();
    int need=sz-l;
    for(int i=0;i<need;++i){
        a.push_back('0');
    }
    reverse(a.begin(),a.end());
    return a;
}

int distinct(long long int d, int sz){
    string ret=dectosev(d,sz);
    int ar[7];
    for(int i=0;i<7;++i){
        ar[i]=0;
    }
    for(int i=0;i<sz;++i){
        ar[ret[i]-'0']++;
    }
    for(int i=0;i<7;++i){
        if(ar[i]>1){
            return 0;
        }
    }
    return 1;
}

int cumsum[830000];
int cumsum2[830000];
int main(){

    //cout<<x<<" "<<dis<<"\n";
    long long int n,m;
    cin>>n>>m;
    int hoursize=szneeded(n-1);
    int minsize=szneeded(m-1);
    int tot=hoursize+minsize;
    cout<<tot<<"\n";
    if(tot>8){
        printf("0\n");
    }
    else{
    cumsum[0]=0;
    for(int i=1;i<=823542;++i){
        int f=distinct((long long int)i,tot);
        if(f){
            cumsum[i]=1;
        }
        else{
            cumsum[i]=0;
        }
    }
    cumsum2[0]=0;
    for(int i=1;i<=823542;++i){
        cumsum2[i]=cumsum2[i-1]+cumsum[i];
    }
    long long int ans=0;
    long long int mn=min(n,(long long int)823543);
    for(int i=0;i<(int)mn;++i){
        string cur=dectosev((long long int)i,hoursize);
        cout<<cur<<"\n";
        string minmn=dectosev(0,minsize);
        string minmx=dectosev(m-1,minsize);
        cout<<minmn<<" "<<minmx<<"\n";
        long long int a=sevtodec(cur+minmn);
        long long int b=sevtodec(cur+minmx);
        if(a>823542){
            continue;
        }
        long long int mm=min(b,(long long int)823542);
        int getmx=cumsum2[mm];
        int getmn=0;
        if(a>0){
            getmn=cumsum2[a-1];
        }
        ans+=(getmx-getmn);
    }
    cout<<ans<<"\n";
    }
    return 0;
}
