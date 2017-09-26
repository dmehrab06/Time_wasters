#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000000000009
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VS vector<string>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
#define PB push_back
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
using namespace std;

LLI dp[100005][3][3];
VI price;
VS all;

void init(){
    FREP(i,0,100004){
        FREP(j,0,2){
            FREP(k,0,2){
                dp[i][j][k]=-2;
            }
        }
    }
}

LLI solve(int idx, int cur, int post){
    if(dp[idx][cur][post]!=-2){
        return dp[idx][cur][post];
    }
    if(idx==1){
        string nw=all[idx];
        string nx=all[idx+1];
        LLI cost=cur?price[idx]:0;
        if(cur)reverse(nw.begin(),nw.end());
        if(post)reverse(nx.begin(),nx.end());
        if(!(nw.compare(nx)<=0))return dp[idx][cur][post]=MXX;
        return cost;
    }
    string nw=all[idx];
    string nx=all[idx+1];
    LLI cost=cur?price[idx]:0;
    if(cur)reverse(nw.begin(),nw.end());
    if(post)reverse(nx.begin(),nx.end());
    if(!(nw.compare(nx)<=0))return dp[idx][cur][post]=MXX;
    dp[idx][cur][post]=min((LLI)MXX,cost+solve(idx-1,0,cur));
    dp[idx][cur][post]=min(dp[idx][cur][post],cost+solve(idx-1,1,cur));
    return dp[idx][cur][post];
}

int main(){
    price.PB(-1);
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        int a;
        scanf("%d",&a);
        price.PB(a);
    }
    all.PB("");
    FREP(i,1,n){
        string a;
        cin>>a;
        all.PB(a);
    }
    string en="";
    FREP(i,1,300000)en.PB('z');
    all.PB(en);
    init();
    LLI ans=min(solve(n,0,0),solve(n,1,0));
    if(ans==MXX)ans=-1;
    cout<<ans<<"\n";
    return 0;
}
