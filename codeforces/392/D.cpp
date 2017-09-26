/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

char thenumber[103];

LLI base;

double basepowdd[103];
LLI basepow[103];
LLI tenpow[103];

LLI dp[103][103];

void init(LLI base){
    memset(dp,-1,sizeof(dp));
    basepow[0]=1;
    basepowdd[0]=1.0;
    tenpow[0]=1;
    FREP(i,1,100){
        basepow[i]=basepow[i-1]*base;
        basepowdd[i]=basepowdd[i-1]*base;
        tenpow[i]=tenpow[i-1]*10;
    }
}

LLI solve(int cur, int pow){
    if(cur<=0)return 0;
    if(dp[cur][pow]!=-1)return dp[cur][pow];
    LLI s=0;
    LLI tpw=0;
    int pos=cur;
    LLI ret1=1000000000000000000;
    LLI prev=-1;
    while(pos>0){
       cout<<"at pos "<<pos<<"\n";
       if(thenumber[pos]!='0' && tpw>10){
            break;
       }
        s=s+(LLI)(thenumber[pos]-'0')*tenpow[tpw];
        cout<<"will try "<<s<<"\n";
        if(s>=base)break;
        double basepowdbl=basepowdd[pow];
        LLI basepowlld=basepow[pow];
        double multi=(double)s*basepowdbl;
        if(multi>1000000000000000000.00)break;
        LLI multi2=s*basepowlld;
        //if(multi2==prev)continue;
       cout<<"trying with "<<s<<" at pow "<<pow<<"\n";
        pos--;
        tpw++;
        if(s==prev)continue;
        ret1=min(ret1,multi2+solve(pos,pow+1));
        prev=s;
    }
    return dp[cur][pow]=ret1;
}


int main(){
    cin>>base;
    init(base);
    scanf("%s",thenumber);
    int l=strlen(thenumber);
    RFREP(i,l,1){
        thenumber[i]=thenumber[i-1];
    }
    LLI ans=solve(l,0);
    cout<<ans<<"\n";
}
