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

LLI gcd(LLI a, LLI b){
    if(a==0)return b;
    return gcd(b%a,a);
}

int main(){
    ios_base::sync_with_stdio(false);
    LLI n;
    cin>>n;
    LLI until=n+1;
    LLI cur=1;
    LLI start=2;
    while(cur<until){
        LLI nxt=cur+1;
        LLI losagu=cur*nxt;
        LLI go=((nxt)*losagu)-(start/cur);
       // if(go%cur)printf("moira gesi\n");
        cout<<go<<"\n";
        start=losagu;
        cur++;
    }
    return 0;
}
