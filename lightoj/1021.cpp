/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

#define MAXN 16
//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI dp[1<<MAXN][20];
LLI basepow[18];
int hasdigs[20];

bool allused(int mask, int dig){
    int mm = 1;
    FREP(i,1,dig){
        if(!(mask&mm))return false;
        mm<<=1;
    }
    return true;
}

int cntset(int mask, int dig){
    int mm = 1;
    int cnt = 0;
    FREP(i,1,dig){
        if((mask&mm))cnt++;
        mm<<=1;
    }
    return cnt;
}

int setbit(int i, int mask){ //0th index
    return (mask | (1<<i));
}

int resetbit(int i, int mask){
    return (mask & ~(1<<i));
}

bool isset(int i, int mask){
    return (mask & (1<<i));
}

void init(int base, int mod){
    MSET(dp,-1);
    basepow[0]=1%mod;
    FREP(i,1,17){basepow[i]=basepow[i-1]*base;basepow[i]%=mod;}
}

LLI solve(int mask, int mod_so_far, int dig, int mod){
    if(allused(mask,dig)){
        if(mod_so_far==0)return dp[mask][mod_so_far] = 1;
        return dp[mask][mod_so_far]=0;
    }
    if(dp[mask][mod_so_far]!=-1)return dp[mask][mod_so_far];
    int curpow = cntset(mask,dig); //ekhon ja korbo curpow dia power hobe
    LLI s = 0;
    FREP(i,0,dig-1){
        if(!isset(i,mask)){
            int val = hasdigs[i];
            int newmask = setbit(i,mask);
            int newpw = basepow[curpow];
            int newmod = ((newpw*val)%mod+mod_so_far)%mod;
            s+=solve(newmask,newmod,dig,mod);
        }
    }
    return dp[mask][mod_so_far]=s;
}

char num[20];

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int base, K;
        scanf("%d %d",&base,&K);
        init(base,K);
        scanf("%s",num);
        int ll = strlen(num);
        FREP(i,0,(ll-1))hasdigs[i] = ISCAP(num[i])?(num[i]-'A'+10):(num[i]-'0');
        LLI ans = solve(0,0,ll,K);
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}
