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
//char str[100006];
int main(){
    LLI n,b,d;
    cin>>n>>b>>d;
    LLI s=0;
    int ans=0;
    FREP(i,1,n){
        int a;
        scanf("%d",&a);
        if(a<=b){
            s+=(LLI)a;
        }
        if(s>d){
            ans++;
            s=0;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
