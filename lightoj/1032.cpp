/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
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
//using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

unordered_map<int,int>twopowbase;

LLI dp[60];
LLI ans[60];

void pre(){
    twopowbase[1] = 0;
    int vv = 1;
    FREP(i,1,40){
        vv<<=1;
        twopowbase[vv] = i;
    }
    FREP(i,1,40){
        ans[i] = dp[i-1]+((LLI)1<<(i-1));
        dp[i] = dp[i-1]+ans[i];
    }
}

LLI solve(int val){
    //cout<<val<<"\n";
    if(val<=1)return 0;
    if(twopowbase.find(val)!=twopowbase.end()){
        int bs = twopowbase[val];
        return dp[bs-1];
    }
    LLI pw = 1;
    int bs = 0;
    while(pw<=(LLI)val){
        pw<<=1;
        bs++;
    }
    int dif = val-(1<<(bs-1));
    int ext = max(0,dif-((1<<(bs-2))-1));
    //cout<<"val: "<<val<<" consists of dp: "<<(1<<(bs-1))<<" having "<<dp[bs-2]<<" extra 1: "<<ext<<" and from "<<dif<<"\n";
    return dp[bs-2]+(LLI)ext+solve(dif);
}

int main(){
    int t;
    scanf("%d",&t);
    pre();
    //FREP(i,1,30)cout<<dp[i]<<"\n";
    FREP(cs,1,t){
        int n;
        scanf("%d",&n);
        printf("Case %d: %lld\n",cs,solve(n));
    }
    return 0;
}
