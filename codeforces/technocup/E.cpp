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

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<PII>all;

char dir[200005];

int slices[1000006];

int howmany(int wholesz, int piece){
    if(piece>wholesz)return 0;
    if((wholesz/piece)==1)return 1;
    if(piece==1)return wholesz;
    //cout<<"in that bloody function for "<<wholesz<<"\n";
    int lval=wholesz/2; int rval=wholesz/2+wholesz%2;
    int mxxfreq=2;
    int tot=2;
    while(true){
        //cout<<lval<<" "<<rval<<"\n";
        lval>>=1; rval=(rval>>1)+(rval&1);
        tot<<=1;
        int ltot=lval*tot; int lft=wholesz-ltot;
        int rfreq=lft; int lfreq=tot-lft;
        int curpiecefreq=0;
        if(lval>=piece)curpiecefreq+=lfreq; if(rval>=piece)curpiecefreq+=rfreq;
        mxxfreq=max(curpiecefreq,mxxfreq);
        if(rval<piece)break;
    }
    return mxxfreq;
}

bool can(int atleast, int n, int k){
    LLI ss=0;
    //cout<<"calc for "<<atleast<<"\n";
    RFREP(i,n,1){
        int nwslice=howmany(slices[i],atleast);
      //  cout<<"in "<<slices[i]<<" "<<atleast<<" is present of amount "<<nwslice<<"\n";
        ss+=nwslice;
        if(nwslice==0)break;
        if(ss>=k)return true;
    }
    return false;
}



int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int mxx=0;

    FREP(i,1,n){
        scanf("%d",&slices[i]);
        mxx=max(mxx,slices[i]);
    }
    sort(slices+1,slices+1+n);
    int lo=1;
    int hi=mxx;
    if(!can(lo,n,k)){
        cout<<"-1\n";
        return 0;
    }
    int ans=-1;
    while(true){
        int mid=(lo+hi)/2;
        if(can(mid,n,k)){
            if(mid<hi && can(mid+1,n,k)){
                lo=mid+1;
            }
            else{
                ans=mid;
                break;
            }
        }
        else{
            hi=mid;
        }
    }

    printf("%d\n",ans);

    return 0;
}

