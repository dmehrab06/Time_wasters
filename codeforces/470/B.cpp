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
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
using namespace std;
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int smalles[1000005];

void sieve(){
    for(int i = 2;i<=1000000;++i){
        if(smalles[i]==0){
            for(int j = i; j<=1000000; j+=i){
                if(smalles[j]==0){
                    smalles[j] = i;
                }
            }
        }
    }
}

int solve2(int x1){
    int mnval = 1000000;
    int t = x1;
    while(x1>1){
        int pp = smalles[x1];
        while((x1%pp)==0)x1/=pp;
        if(pp==t)continue;
        int d = (t/pp);
        mnval = min(mnval,(pp*(d-1))+1);
    }
    return mnval;
}

int solve1(int x2){
    int mnval = 1000000;
    int t = x2;
    while(x2>1){
        int pp = smalles[x2];
        while((x2%pp)==0)x2/=pp;
        if(pp==t)continue;
        int d = (t/pp);
        int st = pp*(d-1)+1;
        for(int j = st;j<=t;++j){
            mnval = min(mnval,solve2(j));
        }
    }
    return mnval;
}

int main(){
    int n;
    sieve();
    scanf("%d",&n);
    printf("%d\n",solve1(n));
    return 0;
}
