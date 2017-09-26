/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

typedef tree<
PII,
null_type,
greater<PII>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

LLI ai[200005];
LLI mai[200005];
LLI bi[200005];
LLI mbi[200005];

LLI binsearch(LLI mxmana, int k){
    if(mxmana>=mbi[k]){
        return bi[k];
    }
    else if(mxmana<mbi[1]){
        return 0;
    }
    int l=1;
    int h=k;
    while(true){
        int md=(l+h)/2;
        if(mxmana>=mbi[md]){
            if((md+1)<=k && mbi[md+1]<=mxmana){
                l=md+1;
            }
            else{
                return bi[md];
            }
        }
        else{
            h=md;
        }
    }
    return -1;
}

int main(){
    LLI n; int m,k;
    cin>>n>>m>>k;
    LLI x,s;
    cin>>x>>s;
    FREP(i,1,m){
        cin>>ai[i];
    }
    FREP(i,1,m){
        cin>>mai[i];
    }
    FREP(i,1,k){
        cin>>bi[i];
    }
    FREP(i,1,k){
        cin>>mbi[i];
    }
    LLI mn=(x*n);
    FREP(i,1,m){
        LLI need=n;
        LLI leftmana=s;
        LLI per=x;
        if(mai[i]>leftmana){
            leftmana-=0;
            per=x;
            need-=0;
            LLI dn=binsearch(leftmana,k);
            //cout<<"in "<<i<<" returning "<<dn<<"\n";
            need-=dn;
            if(need<0)need=0;
            LLI ans=need*per;
            if(mn==-1 || ans<mn){
                mn=ans;
            }
        }
        else{
            leftmana-=mai[i];
            per=ai[i];
            LLI dn=binsearch(leftmana,k);
            //cout<<"in "<<i<<" returning "<<dn<<"\n";
            need-=dn;
            if(need<0)need=0;
            LLI ans=need*per;
            //cout<<ans<<"\n";
            if(mn==-1 || ans<mn){
                mn=ans;
            }
        }
    }
    cout<<mn<<"\n";
    return 0;
}
