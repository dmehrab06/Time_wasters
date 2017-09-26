#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
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
#define pi acos(-1.0)
#define float double
using namespace std;
LLI cnt(int n, LLI N, int m){
    LLI s=0;
    FREP(i,1,n){
        LLI tot=(N-1)/i;
        if(tot==0)break;
        s+=min(tot,(LLI)m);
    }
    return s;
}

LLI bs(int n, int m, LLI l, LLI h, LLI k){
    LLI mid=(l+h)/2;
    LLI c=cnt(n,mid,m);
    //LLI cr=cnt(n,mid+1,m);
    //LLI cl=cnt(n,mid-1,m);
    if(c<k){
        if((mid+1)<=((LLI)n*(LLI)m)){
            LLI cr=cnt(n,mid+1,m);
            if(cr>=k){
                return mid;
            }
            else{
                return bs(n,m,mid+1,h,k);
            }
        }
        else{
            return mid;
        }
    }
    else{
        return bs(n,m,l,mid,k);
    }
}

int main(){
    int n,m;
    LLI k;
    cin>>n>>m>>k;
    LLI mx=(LLI)n*(LLI)m;
    LLI ans=bs(n,m,1,mx,k);
    cout<<ans<<"\n";
}
