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
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI dp[1003][1003];
int dpmaxlen[1003][1003];
int mindiv[1003][1003];

int possible[26];

char str[1003];

void init(){
    memset(dp,-1,sizeof(dp));
}

LLI solve(int l, int r){
    if(l>=r){
        if(l==r){
            dpmaxlen[l][r]=1;
            mindiv[l][r]=1;
        }
        else{
            dpmaxlen[l][r]=0;
            mindiv[l][r]=0;
        }
        return 1;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    LLI ret=0;
    int len2=0;
    int appeared[26];
    FREP(i,0,25){
        appeared[i]=0;
    }
    int mxlen=0;
    int mindivide=100000;
    FREP(i,l,r){
        len2++;
        int curidx=str[i]-'a';
        appeared[curidx]=1;
      //  cout<<len2<<" "<<curidx<<"\n";
        FREP(j,0,25){
            if(appeared[j] && len2>possible[j]){
                dpmaxlen[l][r]=mxlen;
                mindiv[l][r]=mindivide;
                return dp[l][r]=ret;
            }
        }
        mxlen=max(len2,mxlen);
        LLI ret1=solve(i+1,r);
        int retlen=dpmaxlen[i+1][r];
        mxlen=max(retlen,mxlen);
        mindivide=min(mindivide,1+mindiv[i+1][r]);
      //  cout<<"for "<<i+1<<" and "<<r<<" mindiv "<<mindiv[i+1][r]<<"\n";
      //  cout<<"for "<<i+1<<" and "<<r<<" mxlen "<<dpmaxlen[i+1][r]<<"\n";
      //  cout<<" in l: "<<l<<" and r: "<<r<<" splitting by i: "<<i<<" possible "<<ret1<<"\n";
        ret+=ret1;
        ret%=MDD;
      //  cout<<"in l: "<<l<<" and r: "<<r<<" total is now: "<<ret<<"\n";
    }
    dpmaxlen[l][r]=mxlen;
    mindiv[l][r]=mindivide;
    return dp[l][r]=ret;
}

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    FREP(i,0,25){
        scanf("%d",&possible[i]);
    }
    init();
    LLI ans=solve(0,(n-1));
    cout<<ans<<"\n";
    cout<<dpmaxlen[0][n-1]<<"\n";
    cout<<mindiv[0][n-1]<<"\n";

    return 0;
}
