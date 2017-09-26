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

int g[31][31];

int MDD=1000003;

int dp[2005][31];

void takeg(int m){
    memset(dp,0,sizeof(dp));
    FREP(i,1,m){
        char a,b;
        cin>>a>>b;
        g[a-'A'][b-'A']=1;
        g[b-'A'][a-'A']=1;
    }
}

int solve(int n){
    if(n==1)return 26;
    if(n%2)
        return 0;

    int ll=n/2;
    FREP(i,0,25){
        if(g[i][i]==0)dp[1][i]=1;
    }
    FREP(i,1,(ll-1)){
        FREP(j,0,25){
            FREP(k,0,25){
                if(g[j][k]==0){
                    dp[i+1][k]+=dp[i][j];
                    dp[i+1][k]%=MDD;
                    //if((i+2)<=)
                    if((i+2)<=ll){
                        dp[i+2][j]-=dp[i][j];
                    }
                }
            }
        }
    }
    int ans=0;
    FREP(j,0,25){
        ans+=dp[ll][j];
        if(ans>MDD)ans%=MDD;
    }
    if(ans<0){
        while(ans<0){
            ans+=MDD;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    takeg(m);
    int ans=solve(n);
    cout<<ans<<"\n";
    return 0;
}
