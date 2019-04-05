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
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

LLI fact[2000006];
int s[100005];
int d[100005];

void calcfact(){
    fact[0] = 1;
    FREP(i,1,2000004){
        fact[i] = fact[i-1]*i;
        fact[i] = fact[i]%MDD;
    }
}

long long power(int a, int n, int mod){
    long long power = a;
    long long result = 1;

    while (n){
        if (n & 1) result = (result * power) % mod;

        power = (power * power) % mod;
        n >>= 1;

    }
    return result;
}

int main(){
    calcfact();
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int dim;
        scanf("%d",&dim);
        FREP(i,1,dim)scanf("%d",&s[i]);
        FREP(i,1,dim)scanf("%d",&d[i]);
        LLI hor = 1;
        int tot = 0;
        FREP(i,1,dim){
            hor = hor*fact[d[i]-s[i]];
            hor = hor%MDD;
            tot+=(d[i]-s[i]);
        }
        LLI lob = fact[tot];
        LLI ans1 = power(hor,MDD-2,MDD);
        LLI ans = lob*ans1;
        ans%=MDD;
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}
