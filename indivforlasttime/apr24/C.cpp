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

vector<VI>nums;
vector< vector <PII> >rngs;

int arr[100005];
LLI ans[100005];

LLI getrng(LLI len){
    return (len*(len+1))/2;
}

void init(int n){
    rngs.clear();
    FREP(i,1,(n+4)){
        vector <PII> ln;
        rngs.PB(ln);
    }
}

void solve(int n){
    FREP(div,1,n){
        int sz = rngs[div].size();
        LLI s = 0;
        FREP(j,0,sz-1){
            PII cc = rngs[div][j];
            s+=getrng(cc.second-cc.first+1);
        }
        ans[div] = s;
    }
}

void tryinsert(int div, int cur){
    int sz = rngs[div].size();
    if(sz>0){
        PII last = rngs[div][sz-1];
        if(cur==(last.second+1)){
            rngs[div][sz-1].second = cur;
        }
        else{
            rngs[div].PB(make_pair(cur,cur));
        }
    }
    else{
        rngs[div].PB(make_pair(cur,cur));
    }
}

void fillup(int idx){
    int num = arr[idx];
    int sq = sqrt(num);
    FREP(i,1,sq){
        if((num%i)==0){
            tryinsert(i,idx);
            int j = num/i;
            if(j!=i){
                tryinsert(j,idx);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&arr[i]);
    }
    init(n);
    FREP(i,1,n)fillup(i);
    solve(n);
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        int d;
        scanf("%d",&d);
        printf("%lld\n",ans[d]);
    }
    return 0;
}
