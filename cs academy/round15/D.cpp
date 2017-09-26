/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

LLI solve(int a, int b, int base){
    LLI res=0;
    vector<int>oka;
    while(a || b){
        int p=a%base;
        int q=b%base;
        int r=(p+q)%base;
        oka.PB(r);
      //  cout<<r<<"\n";
        a/=base;
        b/=base;
    }
    int l=oka.size();
    RFREP(i,(l-1),0){
        res=res*base+oka[i];
    }
    return res;
}

LLI solve2(int a,int base){
   // if(a==0)return 0;
    if(base==2){
        if(a%4==0){
            return a;
        }
        else if(a%4==1){
            return 1;
        }
        else if(a%4==2){
            return a+1;
        }
        else{
            return 0;
        }
    }
    if(base==3){
        if(a%3==0){
            return a;
        }
        else if(a%3==1){
            LLI ss=solve(a-1,a,3);
            return ss;
        }
        else{
            return 0;
        }
    }
    else if(base==4){
        if(a%8==0){
            return a;
        }
        else{
            int mod=a%8;
            LLI ss=a-mod;
            FREP(i,1,mod){
                ss=solve(ss,a,4);
                a--;
            }
            return ss;
        }
    }
    else if(base==5){
        if(a%5==0){
            return a;
        }
        else{
            int mod=a%5;
            LLI ss=a-mod;
            FREP(i,1,mod){
                ss=solve(ss,a,5);
                a--;
            }
            return ss;
        }
    }
    else if(base==6 || base==7 || base==9){
        if(a%base==0){
            return a;
        }
        else{
            int mod=a%base;
            LLI ss=a-mod;
            FREP(i,1,mod){
                ss=solve(ss,a,base);
                a--;
            }
            return ss;
        }
    }
    else if(base==8){
        if(a%16==0){
            return a;
        }
        else{
            int mod=a%16;
            LLI ss=a-mod;
            FREP(i,1,mod){
                ss=solve(ss,a,base);
                a--;
            }
            return ss;
        }
    }
    else if(base==10){
        if(a%20==0){
            return a;
        }
        else{
            int mod=a%20;
            LLI ss=a-mod;
            FREP(i,1,mod){
                ss=solve(ss,a,base);
                a--;
            }
            return ss;
        }
    }
    return 0;
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);
        LLI ans1=solve2(b,k);
        LLI ans2=solve2(a-1,k);
      //  cout<<ans1<<" "<<ans2<<"\n";
        FREP(i,1,(k-1)){
            ans1=solve(ans1,ans2,k);
        }
        printf("%lld\n",ans1);
    }
    for(int b=2;b<=10;++b){
    cout<<"xor sum in"<< b<<"\n";
    int s=0;
    for(int i=0;i<=100;++i){
        s=solve(s,i,b);
        cout<<i<<" : "<<s<<"\n";
    }
    }
    return 0;
}
