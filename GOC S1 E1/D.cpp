//ds--
//algo -- math

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;

struct frac{
    LLI lob;
    LLI hor;
    frac(LLI _l=0 , LLI _h=1){
        lob=_l;
        hor=_h;
    }
};

LLI gcd(LLI a, LLI b){
    if(a==0)return b;
    return gcd(b%a,a);
}

frac add(frac a, frac b){
    LLI losagu=a.hor/(gcd(a.hor,b.hor));
    losagu=losagu*b.hor;
    LLI anslob=(losagu/a.hor)*a.lob+(losagu/b.hor)*b.lob;
    frac ans(anslob,losagu);
    return ans;
}

int mat[100005][32];

void init(int tot){
    FREP(i,1,tot){
        FREP(j,0,31){
            mat[i][j]=0;
        }
    }
}

void load(int in, int n){
    int msk=1;
    int j=0;
    while(j<=31){
        if(msk&n){
            mat[in][j]=1;
        }
        else{
            mat[in][j]=0;
        }
        j++;
        //n>>=1;
        msk<<=1;
    }
}

int countzincol(int tot, int col){
    int s=0;
    FREP(i,1,tot){
        if(mat[i][col]==0){
            s++;
        }
    }
    return s;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        init(n);
        FREP(i,1,n){
            int a;
            scanf("%d",&a);
            load(i,a);
        }
        frac sum(0,1);
        LLI hor=((LLI)n*(LLI)(n-1))/2;
        LLI curp=1;
        FREP(i,0,31){
            int z=countzincol(n,i);
            LLI zz=((LLI)z*(LLI)(z-1))/2;
            LLI curlob=hor-zz;
            curlob=curlob*curp;
           // LLI gg=gcd(curlob,hor);
            frac cur(curlob,hor);
            sum=add(cur,sum);
            curp=curp*2;
        }
        LLI gg=gcd(sum.lob,sum.hor);
        sum.lob/=gg;
        sum.hor/=gg;
        printf("%lld/%lld\n",sum.lob,sum.hor);
    }
    return 0;
}
