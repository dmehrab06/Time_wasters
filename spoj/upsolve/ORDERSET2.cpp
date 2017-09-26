/*-------property of the half blood prince-----*/

//data structure used- map, segment tree
//algo used- binary search, compression

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

char ask[200005][3];
int val[200005];

map<int,int>cmpress;
map<int,int>invcmpress;

int arr[200005];

int seg[800005];

void init(int b, int e, int node){
    if(b==e){
        seg[node]=arr[b]=0;
        return;
    }
    if(b>e)return;
    else{
        int lt=node<<1; int rt=lt+1;
        int mid=(b+e)>>1;
        init(b,mid,lt); init(mid+1,e,rt);
        seg[node]=seg[lt]+seg[rt];
        return;
    }
}

void update(int i, int val, int b,int e, int node){
    if(b>e || e<i || b>i)return;
    if(b>=i && e<=i){
        seg[node]=arr[b]=val;
        return;
    }
    int lt=node<<1; int rt=lt+1;
    int mid=(b+e)>>1;
    update(i,val,b,mid,lt); update(i,val,mid+1,e,rt);
    seg[node]=seg[lt]+seg[rt];
    return;
}

int query(int i, int j, int b, int e, int node){
    //cout<<"inside i: "<<i<<" j: "<<j<<" b: "<<b<<" e: "<<e<<" node: "<<node<<"\n";
    if(b>e || e<i || b>j)return 0;
    if(b>=i && e<=j)return seg[node];
    int lt=node<<1; int rt=lt+1;
    int mid=(b+e)>>1;
    int lans=query(i,j,b,mid,lt); int rans=query(i,j,mid+1,e,rt);
    return lans+rans;
}


int binsearch(int k, int N){
    int l=0;
    int r=200004;
    while((l+1)<r){
        int m=(l+r)/2;
        int ase=query(0,m,0,N,1);
        if(ase>=k){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    if(query(0,r,0,N,1)==k && arr[r])return r;
    if(query(0,l,0,N,1)==k && arr[l])return l;
    return -1;
}

int main(){
    ordered_set X;

    int q;
    scanf("%d",&q);
    int st=0;
    FREP(i,1,q){
        scanf("%s %d",ask[i],&val[i]);
        if(cmpress.find(val[i])==cmpress.end()){
            continue;
        }
        else{
            invcmpress[st]=val[i];
            cmpress[val[i]]=st++;
        }
    }
    init(0,(st+1),1);
    FREP(i,1,q){
        int curv=val[i];
        int mapval=cmpress[curv];
        if(ask[i][0]=='I'){
            update(mapval,1,0,(st+1),1);
        }
        else if(ask[i][0]=='D'){
            update(mapval,0,0,(st+1),1);
        }
        else if(ask[i][0]=='C'){
            printf("%d\n",query(0,(mapval-1),0,(st+1),1));
        }
        else if(ask[i][0]=='K'){
            int idx=binsearch(curv,(st+1));
            if(idx==-1){
                printf("invalid\n");
            }
            else{
                printf("%d\n",invcmpress[idx]);
            }
        }
    }
    return 0;
}

