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
#define ON first
#define STATE second
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

PII segtree[600005];

char str[100005];

void shift(int l){
    RFREP(i,l,1){
        str[i]=str[i-1];
    }
}

void init(int l, int r, int node){
    if(l==r){segtree[node].ON=str[l]-'0';segtree[node].STATE=0;}
    if(l>=r)return;
    int mid=(l+r)/2;
    int lt=node<<1; int rt=lt+1;
    init(l,mid,lt);init(mid+1,r,rt);
    segtree[node].ON=segtree[lt].ON+segtree[rt].ON;
    segtree[node].STATE=0;
}

void print(int l, int r, int node){
    if(l>r)return;
    printf("l: %d, r: %d, on: %d, flipped: %d\n",l,r,segtree[node].ON,segtree[node].STATE);
    if(l==r)return;
    int mid=(l+r)/2;
    int lt=node<<1; int rt=lt+1;
    print(l,mid,lt);print(mid+1,r,rt);
    //segtree[node].ON=segtree[lt].ON+segtree[rt].ON;
    //segtree[node].STATE=0;
}

void update(int l, int r, int node, int i, int j){
    if(r<i || l>j)return;
    if(l>=i && r<=j){
        int tot=(r-l+1);
        segtree[node].ON=tot-segtree[node].ON;
        segtree[node].STATE^=1;
        return;
    }
    int mid=(l+r)/2;
    int lt=node<<1; int rt=lt+1;
    update(l,mid,lt,i,j);update(mid+1,r,rt,i,j);
    segtree[node].ON=segtree[lt].ON+segtree[rt].ON;
}

void lazy(int l, int r, int node){
    int mid=(l+r)/2;
    int lt=node<<1; int rt=lt+1;
    if(segtree[node].STATE==1){
        int ltsize=(mid-l+1);
        segtree[lt].ON=ltsize-segtree[lt].ON;
        int rtsize=(r-mid);
        segtree[rt].ON=rtsize-segtree[rt].ON;
    }
    segtree[lt].STATE^=segtree[node].STATE;segtree[rt].STATE^=segtree[node].STATE;
    segtree[node].STATE^=segtree[node].STATE;
}

int query(int l, int r, int node, int i, int j){
    if(r<i || l>j)return 0;
    if(l>=i && r<=j){
        return segtree[node].ON;
    }
    lazy(l,r,node);
    int mid=(l+r)/2;
    int lt=node<<1; int rt=lt+1;
    int ll=query(l,mid,lt,i,j);int rr=query(mid+1,r,rt,i,j);
    return ll+rr;
}

void simulate(int q, int n){
    FREP(i,1,q){
        int idx,l,r;
        scanf("%d %d %d",&idx,&l,&r);
        if(idx==1){
            update(1,n,1,l,r);
            print(1,n,1);
        }
        else if(idx==2){
            int ans=query(1,n,1,l,r);
            printf("%d\n",ans);
            print(1,n,1);
        }
    }
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    scanf("%s",str);
    shift(n);
    init(1,n,1);
    simulate(q,n);
    return 0;
}
