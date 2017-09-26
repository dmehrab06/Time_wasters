#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000000000005
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
using namespace std;

int divs[100010];

int divisor(int n){
    int b=sqrt(n)+1;
    int cnt=0;
    FREP(i,1,b){
        if(n%i==0){
            divs[cnt++]=i;
            int j=n/i;
            if(j!=i){
                divs[cnt++]=j;
            }
        }
    }
    return cnt;
}

LLI gcd(LLI a, LLI b){
    if(a==0)return b;
    return gcd(b%a,a);
}

int main(){
    int A,B;
    while(scanf("%d %d",&A,&B)==2){
        if(A==B){
            printf("1\n");
            continue;
        }
        if(B<A)swap(A,B);
        int P=B-A;
        int tot=divisor(P);
        LLI mn=(LLI)(A+1)*(LLI)(B+1);
        mn/=gcd((LLI)(A+1),(LLI)(B-A));
        LLI ans=1;
        LLI LCM;
        FREP(i,0,(tot-1)){
            int cur=divs[i];
            int X=-1;
            if(cur>A){
                X=cur-A;
            }
            else{
              //  if(A%cur){
                X=cur-(A%cur);
               // }
            }
            LCM=(LLI)(A+X)*(LLI)(B+X);
            LCM/=gcd((LLI)(A+X),(LLI)(B-A));
            if(LCM<mn){
                mn=LCM;
                ans=X;
            }
            else if(LCM==mn){
                if(X<ans){
                    ans=X;
                }
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}
