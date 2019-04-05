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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int seq1[100005];
int seq2[100005];

int zerocnt[100005];

LLI bigmod(LLI base, LLI pw, LLI mdd){
    if(pw==0)return 1;
    LLI ret = bigmod(base,pw/2,mdd);
    if((pw%2)==0)return (ret*ret)%mdd;
    return (((base*ret)%mdd)*ret)%mdd;
}

int getzerocnt(int l, int r){
    if(l>r)return 0;
    return zerocnt[r]-zerocnt[l-1];
}

LLI solve(int idx, int n, int m){
    if(idx>n)return 0;
    if(seq1[idx] && seq2[idx]){
        if(seq1[idx]>seq2[idx]){
            LLI zr = getzerocnt(idx+1,n);
            LLI nxtpossible = bigmod(m,zr,mdd);
            return nxtpossible;
        }
        if(seq1[idx]<seq2[idx])return 0;
        else return solve(idx+1,n,m);
    }
    if((seq1[idx]==0) && (seq2[idx]==0)){
        int zr = getzerocnt(idx+1,n);
        LLI sureway = ((LLI)m*(LLI)(m-1))/2;
        sureway%=MDD;
        LLI nxtpossible = bigmod(m,zr,MDD);
        sureway = (sureway*nxtpossible)%MDD;
        LLI possibleway = m*(solve(idx+1,n,m));
        return (sureway+possibleway)%MDD;
    }
    if(seq1[idx]==0){
        int val = seq2[idx];
        int left = m-val;
        LLI zr = getzerocnt(idx+1,n);
        LLI nxtpossible = bigmod(m,zr,MDD);
        LLI sureway = (left*nxtpossible)%MDD;
        LLI possibleway = (solve(idx+1,n,m));
        return (sureway+possibleway)%MDD;
    }
    if(seq2[idx]==0){
        int val = seq1[idx];
        int left = val-1;
        LLI zr = getzerocnt(idx+1,n);
        LLI nxtpossible = bigmod(m,zr,MDD);
        LLI sureway = (left*nxtpossible)%MDD;
        LLI possibleway = (solve(idx+1,n,m));
        return (sureway+possibleway)%MDD;
    }
    return -1;
}

LLI vv(LLI lob, LLI hor, LLI md){
    LLI hr = bigmod(hor,md-2,md);
    return (lob*hr)%md;
}

LLI gcd(LLI a, LLI b){
    if(a==0)return b;
    return gcd(b%a,a);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,1,n)scanf("%d",&seq1[i]);
    FREP(i,1,n)scanf("%d",&seq2[i]);
    FREP(i,1,n){
        if(seq1[i]==0)zerocnt[i]++;
        if(seq2[i]==0)zerocnt[i]++;
        zerocnt[i] = zerocnt[i-1]+zerocnt[i];
    }
    LLI totzero = zerocnt[n];
    LLI hor = bigmod(m,totzero,MDD);
    LLI lob = solve(1,n,m);
    //LLI gg = gcd(lob,hor);
    //lob/=gg; hor/=gg;
    cout<<lob<<" "<<hor<<"\n";
    printf("%lld\n",vv(lob,hor,MDD));
    return 0;
}
