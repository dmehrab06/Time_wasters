#include <cstdio>
#include <algorithm>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))

using namespace std;

struct info{
    long long int mxsum;
    long long int mx;
    info(){
        mxsum=0;
        mx=0;
    }
    info(long long int a, long long int b){
        mxsum=a;
        mx=b;
    }
};

info segtree[600005];
long long int arr[200005];
//b1 ar e1 hoilo row

//b2 ar e2 hoilo column
void init(int b, int e, int node){
    //cout<<"aschi\n";
    //cout<<b1<<" "<<b2<<" "<<e1<<" "<<e2<<" "<<node<<"\n";
    if(b==e){
        segtree[node].mxsum=arr[b];
        segtree[node].mx=arr[b];
        return;
    }
    if(b>e)return;
    else{
  //  printf("in node %d, range %d to %d\n",node,b,e);
        int lt=node<<1;
        int rt=lt+1;
        int mid=(b+e)>>1;
        init(b,mid,lt);
        init(mid+1,e,rt);
        long long int mx1=max(segtree[lt].mxsum,segtree[rt].mxsum);
        long long int mxx=max(mx1,segtree[lt].mx+segtree[rt].mx);
        segtree[node].mxsum=mxx;
        segtree[node].mx=max(segtree[lt].mx,segtree[rt].mx);
        return;
    }
}

info query(int i, int j, int b, int e, int node){
    //int cur=0;
    if(b>=i && e<=j){
        //cur=segtree[node];
        return segtree[node];
    }
    if(e<i || b>j){
        return info(-1000000009,-1000000009);
    }
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    info leftinfo=query(i,j,b,mid,lt);
    info rightinfo=query(i,j,mid+1,e,rt);
    info tosend(max(leftinfo.mx+rightinfo.mx, max(leftinfo.mxsum,rightinfo.mxsum)), max(leftinfo.mx,rightinfo.mx) );
    return tosend;
}

void update(int i, int b,int e, int node,int val){
    if(b==i && e==i){
        segtree[node].mx=val;
        segtree[node].mxsum=val;
        return;
    }
    if(e<i || b>i){
        return;
    }
    //if(b1>e1 || b2>e2)return;
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    update(i,b,mid,lt,val);
    update(i,mid+1,e,rt,val);
    //segtree[node]=segtree[left]+segtree[right];
    long long int mx1=max(segtree[lt].mxsum,segtree[rt].mxsum);
    long long int mxx=max(mx1,segtree[lt].mx+segtree[rt].mx);
    segtree[node].mxsum=mxx;
    segtree[node].mx=max(segtree[lt].mx,segtree[rt].mx);
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&arr[i]);
    }
    init(1,n,1);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        char c[2];
        int x,y;
        scanf("%s %d %d",c,&x,&y);
        if(c[0]=='U'){
            update(x,1,n,1,y);
        }
        else if(c[0]=='Q'){
            info ans=query(x,y,1,n,1);
            printf("%lld\n",ans.mxsum);
        }
    }
    return 0;
}
