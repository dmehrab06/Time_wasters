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
//0=noop
//1=or
//2=xor
vector<VLLI>facts;
LLI dp[2003][2003];
//dp[length][lastnumber]
void init(){
    FREP(i,0,2001){
        FREP(j,0,2001)dp[i][j]=0;
    }
    FREP(i,1,2001){
        dp[i][1]=1;
        dp[1][i]=1;
    }
}

void pre(int n){
    VLLI line;
    FREP(i,1,(n+3))facts.PB(line);
    facts[1].PB(1);
    FREP(i,2,n){
        facts[i].PB(i);
        facts[i].PB(1);
        LLI b=sqrt(i);
        FREP(j,2,(b)){
            if(i%j==0){
                facts[i].PB(j);
                LLI q=i/j;
                if(q!=j)
                facts[i].PB(q);
            }
        }

    }
}

int main(){
    LLI n,k;
    cin>>n>>k;
    init();
    pre(n);
    FREP(i,2,k){
        FREP(j,2,n){
            int sz=facts[j].size();
            FREP(d,0,(sz-1)){
                dp[i][j]+=dp[i-1][facts[j][d]];
                dp[i][j]%=1000000007;
            }
        }
    }
    LLI ans=0;
    FREP(j,1,n){
        ans+=dp[k][j];
        ans%=1000000007;
    }
    cout<<ans<<"\n";
    return 0;
}
