/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
//#include <dirent.h>
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
#define MDD 1000000009
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

const int MAXN = 1007;

LLI ncr[MAXN][MAXN];
LLI bernoulli[MAXN];

void init(){
    MSET(ncr,-1);
}

int kronecker(int i, int j){
    if(i==j)return 1;
    return 0;
}

LLI bigmod(LLI base, LLI pw){
    if(pw==0)return 1;
    if(pw==1)return (base%MDD);
    LLI pp = pw/2;
    LLI ret = bigmod(base,pp);
    if(pw%2==0)return (ret*ret)%MDD;
    return ((((base%MDD)*ret)%MDD)*ret)%MDD;
}

LLI calcncr(int n, int r){
    if(n==r)return ncr[n][r] = 1;
    if(n<r)return ncr[n][r]=0;
    if(r==0)return ncr[n][r]=1;
    if(ncr[n][r]!=-1)return ncr[n][r];
    return ncr[n][r] = ((calcncr(n-1,r))%MDD+(calcncr(n-1,r-1)%MDD))%MDD;
}

LLI calcbern(int n){
    LLI s = 0;
    FREP(k,0,n-1){
        LLI a = ncr[n+1][k];
        LLI b = bernoulli[k];
        LLI cc = (a*b)%MDD;
        s+=cc;
        while(s>=MDD)s-=MDD;
    }
    LLI mmi = bigmod(n+1,MDD-2);
    s = s*mmi;
    s%=MDD;
    s=s*(-1);
    if(s<0)s+=MDD;
    return s;
}

void filltables(){
    FREP(n,0,MAXN-1){
        FREP(r,0,n){
            calcncr(n,r);
        }
    }
    bernoulli[0]=1;
    FREP(i,1,MAXN-1)bernoulli[i]=calcbern(i);

    //FREP(i,0,51)cout<<i<<": "<<bernoulli[i]<<"\n";
}

LLI seriessum(LLI n, int p){
    LLI s = 0;
    FREP(k,1,(p+1)){
        LLI a = ncr[p+1][k];
        LLI b = bernoulli[p+1-k];
        LLI c = (a*b)%MDD;
        LLI d = bigmod(n,k);
        c = (c*d)%MDD;
        int kk = kronecker(k,p);
        if(kk==1){
            s = s-c;
            while(s<0)s+=MDD;
        }
        else{
            s = s+c;
            while(s>=MDD)s-=MDD;
        }
    }
    LLI mm = bigmod(p+1,MDD-2);
    s = (s*mm)%MDD;
    return s;
}

int main(){
    init();
    filltables();
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        LLI n; int k;
        scanf("%lld %d",&n,&k);
        if(n==1){
            printf("0\n");
            continue;
        }
        LLI ans = seriessum(n-1,k)-1;
        if(ans<0)ans+=MDD;
        printf("%lld\n",ans);
    }
    //cout<<seriessum(5,0)<<"\n";
    //cout<<seriessum(5,1)<<"\n";
    //cout<<seriessum(5,2)<<"\n";
    //cout<<seriessum(5,3)<<"\n";
    //cout<<seriessum(5,4)<<"\n";
    return 0;
}
