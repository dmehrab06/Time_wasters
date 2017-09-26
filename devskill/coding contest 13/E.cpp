/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int lob[20005];
int hor[20005];

int smallestprime[20005];

LLI bigmod(int base, int pw, int mdd){
    if(pw==0)return 1;
    if(pw==1) return (LLI)base;
    int pw2=pw/2;
    LLI ret=bigmod(base,pw2,mdd);
    if(pw%2==0){
        return (ret*ret)%mdd;
    }
    return (((ret*ret)%mdd)*(LLI)base)%mdd;
}

void init(){
    memset(lob,0,sizeof(lob));
    memset(hor,0,sizeof(hor));
}

void sieve(){
    FREP(i,2,20003){
        if(smallestprime[i]==0){
            smallestprime[i]=i;
            for(int j=(i+i);j<=20003;j+=i){
                if(smallestprime[j]==0){
                    smallestprime[j]=i;
                }
            }
        }
    }
}


void factorizelob(int n){
    if(n==1){
        return;
    }
    while(n>1){
        int p=smallestprime[n];
        while(n%p==0){
            n/=p;
            lob[p]++;
        }
    }
}

void factorizehor(int n){
    if(n==1){
        return;
    }
    while(n>1){
        int p=smallestprime[n];
        while(n%p==0){
            n/=p;
            hor[p]++;
        }
    }
}

void coprimelobhor(){
    FREP(i,0,20003){
        int a=lob[i];
        int b=hor[i];
        int mnn=min(a,b);
        lob[i]-=mnn;
        hor[i]-=mnn;
    }
}

LLI calca(){
    LLI s=1;
    FREP(i,0,20003){
        LLI rt=bigmod(i,lob[i],1000000007);
        s=s*rt;
        s%=1000000007;
    }
    return s;
}

LLI calcb(int n){
    LLI s=1;
    FREP(i,0,20003){
        LLI rt=bigmod(i,hor[i],1000000007);
        s=s*rt;
        s%=1000000007;
    }
    LLI twop=bigmod(2,n,1000000007);
    return (s*twop)%1000000007;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    sieve();
    while(t--){
        int n;
        scanf("%d",&n);
        init();
        for(int i=1;i<=(2*n-1);i+=2){
            factorizelob(i);
        }
        for(int i=1;i<=(n+1);i++){
            factorizehor(i);
        }
        coprimelobhor();
        LLI a=calca();
        LLI b=calcb(n);
        printf("Case %d: %lld %lld\n",cs++,a,b);
    }
    return 0;
}
