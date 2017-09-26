#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

struct nodez{
    int val;
    int idx;
    nodez(){
        val=0;
        idx=0;
    }
    nodez(int v, int i){
        val=v;
        idx=i;
    }
};

nodez segtree[90025];
int arr[30005];
void init(int b, int e, int node){
    if(b==e){
        segtree[node].val=arr[b];
        segtree[node].idx=b;
    }
    else{
  //  printf("in node %d, range %d to %d\n",node,b,e);
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    init(b,mid,left);
    init(mid+1,e,right);
    if(segtree[left].val<segtree[right].val){
        segtree[node].val=segtree[left].val;
        segtree[node].idx=segtree[left].idx;
    }
    else{
        segtree[node].val=segtree[right].val;
        segtree[node].idx=segtree[right].idx;
    }
    }
}

nodez query(int i, int j, int b, int e, int node){
    if(b>=i && e<=j){
        return segtree[node];
    }
    if(e<i || b>j){
         nodez dummy;
         dummy.val=1000000009;
         dummy.idx=1000000009;
         return dummy;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    nodez min1=query(i,j,b,mid,left);
    nodez min2=query(i,j,mid+1,e,right);
    if(min1.val<min2.val){
        return min1;
    }
    else{
        return min2;
    }
}

long long int foo(int left, int right, int N){
    if(left==right)return arr[left];
    if(left>right)return 0;
    nodez m=query(left,right,1,N,1);
    long long int mn=m.val;
    long long int minidx=m.idx;
    long long int mx=mn*(right-left+1);
    long long int mx1=foo(left,minidx-1,N);
    mx=max(mx,mx1);
    long long int mx2=foo(minidx+1,right,N);
    return max(mx,mx2);
}


int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int N;
        scanf("%d",&N);
        for(int i=1;i<=N;++i){
            scanf("%d",&arr[i]);
        }
        init(1,N,1);
       long long int mxarea=foo(1,N,N);
        printf("Case %d: %lld\n",cs++,mxarea);

    }
    return 0;
}
