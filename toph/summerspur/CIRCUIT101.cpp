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
#define MDD 1000003
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int n,q;
int currange[5000005];
int nxtrange[5000005];

PII ranges[103];

int calcb(){
    LLI s=1;
    FREP(i,1,n){
        s=s*(ranges[i].second-ranges[i].first+1);
        s%=MDD;
    }
    return (int)s;
}

LLI bigmod(LLI base, LLI pow, LLI mdd){
    if(pow==0){
        return (LLI)(1%mdd);
    }
    LLI ex=pow/2;
    LLI ret=bigmod(base,ex,mdd);
    if(pow%2){
        return  (((ret*ret)%mdd)*base)%mdd;
    }
    return (ret*ret)%mdd;
}


LLI getans(LLI lob, LLI bingo, LLI mdd){
    LLI ans=(lob*bingo)%mdd;
    return ans;
}

int modulo (int m, int n) {
    return (m >= 0) ? (m % n) : ( n - abs ( m%n ) ) % n;
}

void update(int prevmn, int prevmx, int l, int r){
    for(int i=(prevmn+l);i<=(prevmx+r);++i){
        nxtrange[i]=0;
    }
    for(int i=prevmn;i<=prevmx;++i){
        int ll=i+l;
        int rr=i+r;
        nxtrange[ll]+=currange[i];
        nxtrange[rr+1]-=currange[i];
    }
    nxtrange[prevmn+l-1]=0;
    for(int i=(prevmn+l);i<=(prevmx+r+2);++i){
        nxtrange[i]=nxtrange[i-1]+nxtrange[i];
       // cout<<"nxt i "<<i<<" : "<<nxtrange[i]<<"\n";
        nxtrange[i]=modulo(nxtrange[i],MDD);
        currange[i]=nxtrange[i];
        currange[i]%=MDD;
    }

}


int main(){
    int q;
    scanf("%d %d",&n,&q);
    int mn=0;
    int mx=0;
    currange[0]=1;
    FREP(i,1,n){
        int l,r;
        scanf("%d %d",&l,&r);
        ranges[i].first=l;
        ranges[i].second=r;
        update(mn,mx,l,r);
        mn+=l;
        mx+=r;

    }
    LLI b=calcb();
    LLI bingo=bigmod(b,MDD-2,MDD);
    FREP(i,1,q){
        int make;
        scanf("%d",&make);
        if(make<mn || make>mx){
            printf("0\n");
            continue;
        }
        LLI a=currange[make];
        LLI ans=getans(a,bingo,MDD);
        printf("%lld\n",ans);
    }
    return 0;
}
