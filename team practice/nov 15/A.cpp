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

LLI arr[1004];

bool isvalid(LLI n){
    LLI t=n;
    VI chk;
    while(t){
        chk.PB(t%10);
        t/=10;
    }
    int l=chk.size();
    int st=chk[l-1];
    RFREP(i,(l-2),0){
        if(chk[i]!=(st+1))return false;
        st++;
    }
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    LLI mx=-1;
    FREP(i,1,n){
        scanf("%lld",&arr[i]);
    }
    FREP(i,1,n){
        FREP(j,(i+1),n){
            LLI mul=arr[i]*arr[j];
            if(isvalid(mul)){
                if(mul>mx)mx=mul;
            }
        }
    }
    printf("%lld\n",mx);
    return 0;
}
