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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

#define MAXNUM 1500000
#define MAXN 100000

int segtree[3*MAXNUM];

void init(int b, int e, int node){
    if(b==e){
        if(b&1)segtree[node]=1;
        else segtree[node] = 0;
        return;
    }
    int mid = (b+e)/2;
    int l = node<<1; int r = l+1;
    init(b,mid,l); init(mid+1,e,r);
    segtree[node]=segtree[l]+segtree[r];
}

void update(int b, int e, int node, int idx, int val){
    if(b==e && b==idx){
        segtree[node]+=val;
        return;
    }
    if(b>idx || e<idx)return;
    int mid = (b+e)/2;
    int l = node<<1; int r = l+1;
    update(b,mid,l,idx,val); update(mid+1,e,r,idx,val);
    segtree[node]=segtree[l]+segtree[r];
}

int query(int b, int e, int node, int f){
    if(b==e){return b;}
    int mid = (b+e)/2;
    int l = node<<1; int r = l+1;
    if(f<=segtree[l])return query(b,mid,l,f);
    else return query(mid+1,e,r,f-segtree[l]);
}

void precalc(){
    init(1,MAXNUM,1);
    for(int i = 2; i<=MAXN; ++i){
        //for(int ii=1;ii<=MAXN;++ii){
            //printf("##%dth value is %d\n",ii,query(1,MAXNUM,1,ii));
        //}
        int cur = query(1,MAXNUM,1,i);
        //printf("%dth number: %d\n",i,cur);
        int sub = 0;
        int t = cur;
        while(true){
            int j = query(1,MAXNUM,1,t-sub);
            //printf("    striking out %d\n",j);
            if(j>=MAXNUM)break;
            update(1,MAXNUM,1,j,-1);
            sub++;
            t+=cur;
        }
    }
}

int main(){
    precalc();
    //printf("done\n");
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int n;
        scanf("%d",&n);
        int ans = query(1,MAXNUM,1,n);
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
