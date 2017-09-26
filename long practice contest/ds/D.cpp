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
    int maxs;
    int sufmaxs;
    int prefmaxs;
    int tot;
    info(){
        maxs=sufmaxs=prefmaxs=tot=0;
    }
    info(int a,int b, int c, int d){
        maxs=a;
        prefmaxs=b;
        sufmaxs=c;
        tot=d;
    }
};

info seg[300005];
int arr[50005];
//b1 ar e1 hoilo row

//b2 ar e2 hoilo column
void init(int b, int e, int node){
    //cout<<"aschi\n";
    //cout<<b1<<" "<<b2<<" "<<e1<<" "<<e2<<" "<<node<<"\n";
    if(b==e){
        seg[node].maxs=seg[node].prefmaxs=seg[node].sufmaxs=seg[node].tot=arr[b];
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
        int curprefmx=max(seg[lt].prefmaxs,seg[lt].tot+seg[rt].prefmaxs);
        int cursufmx=max(seg[rt].sufmaxs,seg[rt].tot+seg[lt].sufmaxs);
        seg[node].prefmaxs=curprefmx;
        seg[node].sufmaxs=cursufmx;
        seg[node].tot=seg[lt].tot+seg[rt].tot;
        //mx may come in these ways
        //only from left
        int mx1=seg[lt].maxs;
        //only from right
        int mx2=seg[rt].maxs;
        //from whole left and some right
        int mx3=seg[lt].tot+seg[rt].prefmaxs;
        //from whole right and some left
        int mx4=seg[rt].tot+seg[lt].sufmaxs;
        //from some left and some right
        int mx5=seg[lt].sufmaxs+seg[rt].prefmaxs;
        seg[node].maxs=max(mx1,max(mx2,max(mx3,max(mx4,mx5))));
        return;
    }
}

void update(int idx, int b,int e, int node, int val){
    if(b==idx && e==idx){
        seg[node].maxs=seg[node].prefmaxs=seg[node].sufmaxs=seg[node].tot=val;
        return;
    }
    if(e<idx || b>idx){
        return;
    }
    //if(b1>e1 || b2>e2)return;
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    update(idx,b,mid,lt,val);
    update(idx,mid+1,e,rt,val);
    int curprefmx=max(seg[lt].prefmaxs,seg[lt].tot+seg[rt].prefmaxs);
    int cursufmx=max(seg[rt].sufmaxs,seg[rt].tot+seg[lt].sufmaxs);
    seg[node].prefmaxs=curprefmx;
    seg[node].sufmaxs=cursufmx;
    seg[node].tot=seg[lt].tot+seg[rt].tot;
    //mx may come in these ways
    //only from left
    int mx1=seg[lt].maxs;
    //only from right
    int mx2=seg[rt].maxs;
    //from whole left and some right
    int mx3=seg[lt].tot+seg[rt].prefmaxs;
    //from whole right and some left
    int mx4=seg[rt].tot+seg[lt].sufmaxs;
    //from some left and some right
    int mx5=seg[lt].sufmaxs+seg[rt].prefmaxs;
    seg[node].maxs=max(mx1,max(mx2,max(mx3,max(mx4,mx5))));
    return;
}

info query(int i, int j, int b, int e, int node){
    if(b>=i && e<=j){
        return seg[node];
    }
    if(e<i || b>j){
        return info(-1000000009,-1000000009,-1000000009,0);
    }
    info ans;
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    info lans=query(i,j,b,mid,lt);
    info rans=query(i,j,mid+1,e,rt);
    int curprefmx=max(lans.prefmaxs,lans.tot+rans.prefmaxs);
    int cursufmx=max(rans.sufmaxs,rans.tot+lans.sufmaxs);
    ans.prefmaxs=curprefmx;
    ans.sufmaxs=cursufmx;
    ans.tot=lans.tot+rans.tot;
    //mx may come in these ways
    //only from left
    int mx1=lans.maxs;
    //only from right
    int mx2=rans.maxs;
    //from whole left and some right
    int mx3=lans.tot+rans.prefmaxs;
    //from whole right and some left
    int mx4=rans.tot+lans.sufmaxs;
    //from some left and some right
    int mx5=lans.sufmaxs+rans.prefmaxs;
    ans.maxs=max(mx1,max(mx2,max(mx3,max(mx4,mx5))));
    return ans;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&arr[i]);
    }
    init(1,n,1);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int type;
        int x,y;
        scanf("%d %d %d",&type,&x,&y);
        if(type==1){
            info ans=query(x,y,1,n,1);
            printf("%d\n",ans.maxs);
        }
        else if(type==0){
            update(x,1,n,1,y);
        }
    }
    return 0;
}
