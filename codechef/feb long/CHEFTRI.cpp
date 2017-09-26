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
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI arr[1000005];

vector< pair< LLI, LLI> >allranges;

void calcrange(int n, LLI mn, LLI mx){
    FREP(i,1,(n-1)){
        LLI ff=arr[i];
        LLI ss=arr[i+1];
        LLI ll=max(mn,ss-ff+1);
        LLI rr=min(mx,ss+ff-1);
        if(ll>rr){
            continue;
        }
        pair<LLI,LLI>oka=make_pair(ll,rr);
        allranges.PB(oka);
    }
    return;
}

LLI solve(){
    SORTV(allranges);
    int l=allranges.size();
    LLI prevr=0;
    LLI prevlen=0;
    FREP(i,0,(l-1)){
        LLI curl=allranges[i].first;
        LLI curr=allranges[i].second;
        //cout<<curl<<" "<<curr<<"\n";
        if(curl<=prevr){
            if(curr<=prevr){
                continue;
            }
            else{
                LLI extra=curr-prevr;
                prevlen+=extra;
                prevr=curr;
            }
        }
        else{
            prevlen+=(curr-curl+1);
            prevr=curr;
        }
        //cout<<"now len: "<<prevlen<<"\n";
    }
    return prevlen;
}

int main(){
    int n;
    LLI mn,mx;
    scanf("%d %lld %lld",&n,&mn,&mx);
    FREP(i,1,n){
        scanf("%lld",&arr[i]);
    }
    sort(arr+1,arr+1+n);
    calcrange(n,mn,mx);
    LLI ans=solve();
    printf("%lld\n",ans);
}
