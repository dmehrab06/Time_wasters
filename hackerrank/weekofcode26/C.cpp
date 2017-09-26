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
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
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

vector<int>primes;

int gap;

int sieve[100006];

int modifiedsieve[1000006];

int possibleprimes[1000006];

void init(int hi){
    for(int i=2;i<=100000;++i){
        if(sieve[i]==1)continue;
        for(int j=(i+i);j<=100000;j+=i){
            sieve[j]=1;
        }
    }
    int hii=sqrt(hi);
    FREP(i,2,hii){
        if(sieve[i]==0){
            primes.PB(i);
        }
    }
}

int findst(int lo, int hi, int p){
    int div=lo/p;
    int loo=p*div;
    if(loo==lo && loo!=p)return loo;
    loo+=p;
    if(loo<=hi && loo!=p)return loo;
    loo+=p;
    if(loo<=hi)return loo;
    return -1;
}



int main(){
    int lo, hi;
    scanf("%d %d",&lo,&hi);
    init(hi);
    int l=primes.size();
    FREP(i,0,(l-1)){
        int p=primes[i];
        int start=findst(lo,hi,p);
        //cout<<"for prime "<<p<<" found "<<start<<"\n";
        if(start==-1)continue;
        for(int j=start;j<=hi;j+=p){
            modifiedsieve[j-lo]=1;
        }
    }
    int sz=0;
    FREP(i,0,(hi-lo)){
        if(modifiedsieve[i]==0){
            int oka=i+lo;
            if(oka<2)continue;
            possibleprimes[++sz]=oka;
        }
    }

    /*FREP(i,1,sz){
        cout<<possibleprimes[i]<<"\n";
    }*/

    int tot=0;

    FREP(i,2,sz){
        if((possibleprimes[i]-possibleprimes[i-1])==2){
            tot++;
        }
    }
    printf("%d\n",tot);
    return 0;
}
