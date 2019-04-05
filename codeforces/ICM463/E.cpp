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


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI stirling[5003][5003];

/*LLI solve(int n, int r){
    if(r>n)return 0;
    if(n==r)return 1;
    if(r==0)return 1;
    if(ncr[n][r]!=-1)return ncr[n][r];
    return ncr[n][r] = (solve(n-1,r)+solve(n-1,r-1))%1000000007;
}*/

LLI solvestirling(int n, int k){
    if(n==0 && k==0)return 1;
    if(n==0 && k>0)return 0;
    if(n>0 && k==0)return 0;
    if(stirling[n][k]!=-1)return stirling[n][k];
    LLI p1 = solvestirling(n-1,k-1);
    LLI p2 = (LLI)k*solvestirling(n-1,k);
    p2%=1000000007;
    return stirling[n][k] = (p1+p2)%1000000007;
}

LLI bigmod(LLI base, LLI pw, LLI mdd){
    if(pw==0)return 1;
    if(pw==1)return base;
    LLI rr = pw/2;
    LLI ret = bigmod(base,rr,mdd);
    if((pw%2)==0)return (ret*ret)%mdd;
    return (((base*ret)%mdd)*ret)%mdd;
}

LLI divmod(LLI lob, LLI hor, LLI m){
    LLI xx = bigmod( hor, m - 2, m );
    return (lob*xx)%m;
}

void pre(int n){
    FREP(i,0,n){
        solvestirling(n,i);
    }
}

LLI pow(int val, int k){
    int pp = 1;
    FREP(i,1,k)pp = pp*val;
    return pp;
}

LLI factt[5003];

void pre2(){
    factt[0]=1;
    FREP(i,1,5000){
        factt[i] = factt[i-1]*i;
        factt[i]%=1000000007;
    }
}

int main(){
    //MSET(ncr,-1);
    MSET(stirling,-1);
    int n,k;
    cin>>n>>k;
    pre(n);
    pre2();
    LLI s = 0;
    LLI lob = 1;
    LLI hor = 1;
    LLI lobstart = n;
    LLI horstart = 1;
    LLI mdd = 1000000007;
    FREP(q,0,k){
        lob = (lob*lobstart)%mdd;
        hor = (hor*horstart)%mdd;
        LLI p1 = divmod(lob,hor,mdd);
        if(q>n)p1 = 0;
        lobstart--;
        horstart++;
        LLI p2 = bigmod(2,n-q,mdd);
        if((n-q)<0)p2 = 0;
        LLI p3 = factt[q];
        LLI p4 = solvestirling(k,q);
        LLI p = (p1*p2)%mdd;
        p  = (p*p3)%mdd;
        p = (p*p4)%mdd;
        s+=p;
        s%=mdd;
    }
    cout<<s<<"\n";
    return 0;
}
