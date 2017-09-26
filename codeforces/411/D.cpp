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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<LLI>cluster;

void print(){
    FREP(i,0,cluster.size())cout<<cluster[i]<<" ";
    cout<<"\n";
}

char mystr[1000005];
void fillcluster(int n){
    int cur=0;
    while(mystr[cur]=='b'){
        cur++;
    }
    if(cur==n)return;
    int cursize=1;
    for(int i=cur+1;i<n;++i){
        if(mystr[i]==mystr[i-1]){
            cursize++;
        }
        else{
            cluster.PB(cursize);
            cursize=1;
        }
    }
    cluster.PB(cursize);
}

LLI bigmod(LLI pow, LLI mdd){
    if(pow==0)return (LLI)1;
    if(pow==1)return (LLI)2;
    LLI ret=bigmod(pow/2,mdd);
    if(pow%2==0){
        return (ret*ret)%mdd;
    }
    else{
        return (((ret*ret)%mdd)*2)%mdd;
    }
}

LLI getval(LLI cnta, LLI cntb){
   // cout<<cnta<<" "<<cntb<<"\n";
    LLI boka=bigmod(cnta,MDD);
    boka-=1;
    if(boka<0){
        boka+=MDD;
    }
    return (cntb*boka)%MDD;
}

LLI solve(){
    int l=cluster.size();
    LLI ss=0;
    for(int i=0;i<l;i+=2){
        if(i>=(l-1)){
            break;
        }
        LLI cura=cluster[i];
        LLI curb=cluster[i+1];
        LLI thisval=getval(cura,curb);
        ss+=thisval;
        ss%=MDD;
        if((i+2)<l){
            cluster[i+2]+=cura;
            cluster[i+2]%=MDD;
        }

    }
    return ss;
}

int main(){
    scanf("%s",mystr);
    int l=strlen(mystr);
    fillcluster(l);
    LLI ans=solve();
    cout<<ans<<"\n";
    return 0;
}
