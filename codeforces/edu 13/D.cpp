#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define ISVALID(N,X,Y) ((X)>=1 && (X)<=N && (Y)>=1 && (Y)<=N)
#define MDD 1000000007
using namespace std;

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
    long long int A,B,N,x;
    cin>>A>>B>>N>>x;
    long long int val1=modpow(A,N,MDD);
    //cout<<val1<<"\n";
    long long int val2=val1-1;
    //cout<<val2<<"\n";
    if(val2<0){
        val2+=MDD;
    }
    //cout<<val2<<"\n";
    long long int invval3=findMMI((A-1),MDD);
    //cout<<invval3<<"\n";
    long long int val3=val2*invval3;
    //cout<<val3<<"\n";
    val3%=MDD;
    if(A==1){
        val3=N%MDD;
    }
    long long int val4=val3*B;
    //cout<<val4<<"\n";
    val4%=MDD;
    val1=val1*x;
    //cout<<val1<<"\n";
    val1%=MDD;
    long long int ans=(val4+val1)%MDD;
    cout<<ans<<"\n";
}

