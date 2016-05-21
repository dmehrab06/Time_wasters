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

int chairs[102][102];
int main(){
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int A1,A2;
    string seq1="",seq2="";
    if(a[0]=='A'){
        seq1+=a[0];
        if(a[1]!='X'){
            seq1+=a[1];
        }
        if(b[1]!='X'){
            seq1+=b[1];
        }
        if(b[0]!='X'){
            seq1+=b[0];
        }
    }
    else if(a[1]=='A'){
        seq1+=a[1];
        if(b[1]!='X'){
            seq1+=b[1];
        }
        if(b[0]!='X'){
            seq1+=b[0];
        }
        if(a[0]!='X'){
            seq1+=a[0];
        }
    }
    else if(b[1]=='A'){
        seq1+=b[1];
        if(b[0]!='X'){
            seq1+=b[0];
        }
        if(a[0]!='X'){
            seq1+=a[0];
        }
        if(a[1]!='X'){
            seq1+=a[1];
        }
    }
    else if(b[0]=='A'){
        seq1+=b[0];
        if(a[0]!='X'){
            seq1+=a[0];
        }
        if(a[1]!='X'){
            seq1+=a[1];
        }
        if(b[1]!='X'){
            seq1+=b[1];
        }
    }
    seq2=seq1;
    seq1="";
    a=c,b=d;
    if(a[0]=='A'){
        seq1+=a[0];
        if(a[1]!='X'){
            seq1+=a[1];
        }
        if(b[1]!='X'){
            seq1+=b[1];
        }
        if(b[0]!='X'){
            seq1+=b[0];
        }
    }
    else if(a[1]=='A'){
        seq1+=a[1];
        if(b[1]!='X'){
            seq1+=b[1];
        }
        if(b[0]!='X'){
            seq1+=b[0];
        }
        if(a[0]!='X'){
            seq1+=a[0];
        }
    }
    else if(b[1]=='A'){
        seq1+=b[1];
        if(b[0]!='X'){
            seq1+=b[0];
        }
        if(a[0]!='X'){
            seq1+=a[0];
        }
        if(a[1]!='X'){
            seq1+=a[1];
        }
    }
    else if(b[0]=='A'){
        seq1+=b[0];
        if(a[0]!='X'){
            seq1+=a[0];
        }
        if(a[1]!='X'){
            seq1+=a[1];
        }
        if(b[1]!='X'){
            seq1+=b[1];
        }
    }
    if(seq1==seq2){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}
