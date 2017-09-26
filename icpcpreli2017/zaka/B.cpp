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



#define MOD 1000000007
#define SIZE 200009


long long bigMod(long long a, long long b, long long M)
{
    if (b==0)
    {
        return 1%M;
    }
    long long x = bigMod(a, b/2, M);
    x = (x*x) % M;
    if ( b & 1LL )
    {
        x = (x*a) % M;
    }
    return x;
}

long long getInvMod(long long num, long long M)
{
    return bigMod(num, M-2, M);
}


long long facAr[SIZE];
long long invFacAr[SIZE];

void makeFar()
{
    long long a, b, c, d, e;
    facAr[0] = 1;
    invFacAr[0] = 1;
    for (a = 1; a < SIZE; a++)
    {
        facAr[a] = (facAr[a-1] * a ) % MOD;
        invFacAr[a] = ( invFacAr[a-1] * getInvMod(a, MOD) ) % MOD;
    }
}


long long getNcr(long long n, long long r)
{
    long long ans = facAr[n] % MOD;
    ans = (ans * invFacAr[r] ) % MOD;
    ans = ( ans * invFacAr[n-r] ) % MOD;
    return ans % MOD;
}

int p[100005];
int c[100005];

int main(){
    makeFar();
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int n,ase;
        scanf("%d %d",&n,&ase);
        FREP(i,1,ase){
            scanf("%d %d",&p[i],&c[i]);
        }
        LLI s = 1;
        FREP(i,1,(ase-1)){
            LLI M = p[i+1]-p[i]-1;
            LLI N = c[i+1]-c[i]+1;
            s = s*getNcr(N+M-1,M);
            s%=MOD;
        }
        if(p[1]!=0){
            LLI M = p[1];
            LLI N = c[1];
            s = s*getNcr(N+M-1,M);
            s%=MOD;
        }
        if(p[ase]!=(n-1)){
            LLI M = (n-1)-p[ase];
            LLI N = n-c[ase]+1;
            s = s*getNcr(N+M-1,M);
            s%=MOD;
        }
        printf("Case %d: %lld\n",cs,s);
    }
    return 0;
}
