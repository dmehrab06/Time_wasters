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

int main(){
    LLI n,a,b,c;
    cin>>n>>a>>b>>c;
    if(n%4==0){
        cout<<"0\n";
    }
    else if(n%4==1){
        LLI aa=3*a;
        LLI bb=a+b;
        LLI cc=c;
        cout<<min(aa,min(bb,cc))<<"\n";
    }
    else if(n%4==2){
        LLI aa=2*a;
        LLI bb=b;
        LLI cc=2*c;
        cout<<min(aa,min(bb,cc))<<"\n";
    }
    else{
        LLI aa=a;
        LLI bb=b+c;
        LLI cc=3*c;
        cout<<min(aa,min(bb,cc))<<"\n";
    }
    return 0;
}
