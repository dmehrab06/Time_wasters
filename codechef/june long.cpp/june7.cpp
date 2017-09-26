#include <bits/stdc++.h>
#define MDD 1000000007
#define eps 0.0000000001
using namespace std;

int cityfactor[100005];

vector < vector < int > > divv;

long double firstthousandfirstdigit[100003]; //1 er ta thakbe na
int firstthousandmultiplication[100003]; //1 er ta thakbe na

int multi(int N, int R){
    long long int s=1;
    for(int i=(1+R);i<=N;i+=R){
        s=s*(long long int)cityfactor[i];
        if(s>=MDD){
            s%=MDD;
        }
    }
    return (int)s;
}

int getmultifromarray(int i){
    long long int a=firstthousandmultiplication[i];
    a=a*(long long int)cityfactor[1];
    a%=MDD;
    return (int)a;
}

int getfirstdigitfromarray(int i){
    long double ans=firstthousandfirstdigit[i];
    ans+=log10(cityfactor[1]);
    int ans2=(int)ans;
    ans=ans-(long double)ans2;
    /*while(ans>=1.00000000){
        ans=ans/(10.00000000);
    }*/
    //cout<<ans<<"\n";
    long double best=floor(pow(10.0,ans+eps));
    int a=(int)best;
    return a;
}

long double firstdigitforarray(int N, int R){
    long double ans=0.0000000000;
    for(int i=(1+R);i<=N;i+=R){
        ans=ans+log10((long double)cityfactor[i]);
    }
    return ans;
}

int firstdigit(int N, int R){
    long double ans=0.0000000000;
    for(int i=(1+R);i<=N;i+=R){
        ans=ans+log10((long double)cityfactor[i]);
    }
    //cout<<ans<<"\n";

    int ans2=(int)ans;
    ans=ans-(long double)ans2;
    /*while(ans>=1.00000000){
        ans=ans/(10.00000000);
    }*/
    //cout<<ans<<"\n";
    long double best=floor(pow(10.0,ans+eps));
    int a=(int)best;
    return a;
}

long long int modpow(long long int b, long long int x,long long int MD)
{
    if(x==0){
        return 1;
    }
    if(x==1){
        return b;
    }
    long long int hf=modpow(b,x/2,MD);
    if(x%2==0){
        return (hf*hf)%MD;
    }
    else{
        return (((hf*hf)%MD)*b)%MD;
    }
}
long long int findMMI(long long int n,long long int M)
{
    return modpow(n,M-2,M);
}

int main(){
    int N;
    scanf("%d",&N);
    vector<int>line;
    for(int i=1;i<=N+2;++i){
        divv.push_back(line);
    }
    for(int i=1;i<=N+2;++i){
        int b=sqrt(i);
        for(int j=1;j<=b;++j){
            if(i%j==0){
                divv[i].push_back(j);
                int c=i/j;
                if(c!=j){
                    divv[i].push_back(c);
                }
            }
        }
    }
    for(int i=1;i<=N;++i){
        scanf("%d",&cityfactor[i]);
    }
    for(int r=1;r<=N;++r){
        firstthousandmultiplication[r]=multi(N,r);
    }
    for(int r=1;r<=N;++r){
        firstthousandfirstdigit[r]=firstdigitforarray(N,r);
    }
    int Q;
    scanf("%d",&Q);
    while(Q--){
        int command;
        scanf("%d",&command);
        if(command==1){
            int p,f;
            scanf("%d %d",&p,&f);
            if(p!=1){
                int pcur=p-1;
                int ll=divv[pcur].size();
                for(int kk=0;kk<ll;++kk){
                    int k=divv[pcur][kk];
                   // cout<<"updating for r="<<k<<"\n";
                    long long int prevmul=(long long int)firstthousandmultiplication[k];
                    int prevfriendliness=cityfactor[p];
                    prevmul=prevmul*findMMI(prevfriendliness,MDD);
                    if(prevmul>=MDD){
                        prevmul%=MDD;
                    }
                    prevmul=prevmul*(long long int)f;
                    if(prevmul>=MDD){
                        prevmul%=MDD;
                    }
                    firstthousandmultiplication[k]=(int)prevmul;
                    //multi gelo eibar first digit er ta edit krte hobe;
                    long double prevfirst=firstthousandfirstdigit[k];
                    long double prevlog=log10((long double)cityfactor[p]);
                    prevfirst-=prevlog;
                    long double nowlog=log10((long double)f);
                    prevfirst+=nowlog;
                    firstthousandfirstdigit[k]=prevfirst;
                   // cout<<"mul updated: "<<prevmul<<"\n";

                }
            }
            cityfactor[p]=f;

        }
        else{
            int R;
            scanf("%d",&R);
            int fd;
            int ml;

                ml=getmultifromarray(R);
                fd=getfirstdigitfromarray(R);
            printf("%d %d\n",fd,ml);

        }
    }
    return 0;
}

