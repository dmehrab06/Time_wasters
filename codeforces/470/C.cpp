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

LLI melt[100005];
LLI cumsummelt[100005];
LLI extramelt[100005];

LLI fullmelt[100005];

LLI tot[100005];

void takemelt(int n){
    FREP(i,1,n)scanf("%I64d",&melt[i]);
    melt[n+1] = 10000000000;
    FREP(i,1,n+1)cumsummelt[i] = cumsummelt[i-1]+melt[i];
}

LLI getmeltsum(int day, int cur){
    return cumsummelt[cur]-cumsummelt[day-1];
}

void binsearch(int day, int n, LLI totalamount){
    int lo = day; int hi = n+1;
    int ans = -1;
    while(true){
        int mid = (lo+hi)/2;
        if(getmeltsum(day,mid)>=totalamount){
            if(mid>day && (getmeltsum(day,mid-1)>=totalamount)){
                hi = mid;
            }
            else{
                ans = mid;
                break;
            }
        }
        else{
            lo = mid+1;
        }
    }
    fullmelt[day]+=1;
    fullmelt[ans]-=1;
    LLI extra = getmeltsum(day,ans)-totalamount;
    extramelt[ans]+=(melt[ans]-extra);
}

void solve(int n){
    fullmelt[0] = 0;
    FREP(i,1,(n+1))fullmelt[i]+=fullmelt[i-1];
    FREP(i,1,n){
        LLI full = fullmelt[i]; LLI ext = extramelt[i];
        printf("%I64d ",full*melt[i]+ext);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n)scanf("%I64d",&tot[i]);
    takemelt(n);
    FREP(i,1,n)binsearch(i,n,tot[i]);
    solve(n);
    return 0;
}
