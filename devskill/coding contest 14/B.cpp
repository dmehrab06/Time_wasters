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
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

bool isleap(LLI year){
    if(year%400==0)return true;

    if(year%4==0){
        if(year%100)return true;
        return false;
    }
    return false;
}

LLI bigmod(LLI base, LLI pow){
    if(pow==0)return (LLI)1;
    if(pow==1) return (base%MDD);
    LLI ret=bigmod(base,pow/2);
    if(pow%2==0){
        return (ret*ret)%MDD;
    }
    LLI oka=base%MDD;
    LLI nxt1=(oka*ret)%MDD;
    LLI nxt2=(nxt1*ret)%MDD;
    return nxt2;
}

int main(){
    int t;
    int cs=1;
    scanf("%d",&t);
    while(t--){
        LLI n,m;
        scanf("%lld %lld",&n,&m);
        LLI ret=bigmod(n,365);
        printf("Case %d: ",cs++);
        if(!isleap(m)){
            printf("%lld\n",ret);
        }
        else{
            LLI ans= (ret*(n%MDD))%MDD;
            ans=(ans*((n-1)%MDD))%MDD;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
