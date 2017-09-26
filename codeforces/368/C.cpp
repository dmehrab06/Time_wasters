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
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)

using namespace std;

int main(){
    LLI n;
    cin>>n;
    if(n==1 || n==2){
        printf("-1\n");
    }
    else{
        if(n%2){
            LLI m=(n-1)/2;
            LLI p=(n+1)/2;
            cout<<2*m*p<<" "<<m*m+p*p<<"\n";
        }
        else{
            LLI m=1;
            LLI p=n/2;
            cout<<p*p-m*m<<" "<<m*m+p*p<<"\n";
        }
    }
    return 0;
}
