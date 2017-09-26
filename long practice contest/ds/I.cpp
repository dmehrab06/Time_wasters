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
    int mod0;
    int mod1;
    int mod2;
    int lazyval;
    info(){
        mod0=0;
        mod1=0;
        mod2=0;
        lazyval=0;
    }
    info(int a,int b, int c,int d){
        mod0=a;
        mod1=b;
        mod2=c;
        lazyval=d;
    }
    void add(int shiftval){
        int val=shiftval%3;
        if(val==1){
            int t=mod0;
            mod0=mod2;
            mod2=mod1;
            mod1=t;
        }
        else if(val==2){
            int t=mod0;
            mod0=mod1;
            mod1=mod2;
            mod2=t;
        }
    }
};

info seg[300005];
//int arr[50005];
//b1 ar e1 hoilo row

//b2 ar e2 hoilo column
void init(int b, int e, int node){
    //cout<<"aschi\n";
    //cout<<b1<<" "<<b2<<" "<<e1<<" "<<e2<<" "<<node<<"\n";
    if(b==e){
        seg[node].mod0=1;
        seg[node].mod1=0;
        seg[node].mod2=0;
        seg[node].lazyval=0;
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
        seg[node].mod0=seg[lt].mod0+seg[rt].mod0;
        seg[node].mod1=seg[lt].mod1+seg[rt].mod1;
        seg[node].mod2=seg[lt].mod2+seg[rt].mod2;
        seg[node].lazyval=0;
        return;
    }
}

void propagatebelow(int node,int b, int e){
    seg[node].add(seg[node].lazyval);
    if(b<e){
        int ll=node<<1;
        int rr=ll+1;
        seg[ll].lazyval+=seg[node].lazyval;
        seg[rr].lazyval+=seg[node].lazyval;
    }
    seg[node].lazyval=0;
}

void update(int i, int j, int b,int e, int node){
    if(b>e)return;
    propagatebelow(node,b,e);
    if(b>=i && e<=j){
        seg[node].lazyval++;
        propagatebelow(node,b,e);
        return;
    }
    if(e<i || b>j){
        return;
    }
    //if(b1>e1 || b2>e2)return;
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    update(i,j,b,mid,lt);
    update(i,j,mid+1,e,rt);
    seg[node].mod0=seg[lt].mod0+seg[rt].mod0;
    seg[node].mod1=seg[lt].mod1+seg[rt].mod1;
    seg[node].mod2=seg[lt].mod2+seg[rt].mod2;
    return;
}

info query(int i, int j, int b, int e, int node){
    if(b>e)return info(0,0,0,0);
    propagatebelow(node,b,e);
    if(b>=i && e<=j){
        info nw=seg[node];
       // nw.add(propval);
        return nw;
    }
    if(e<i || b>j){
        return info(0,0,0,0);
    }
    info ans;
    //int prop=seg[node].lazyval;
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    info lans=query(i,j,b,mid,lt);
    info rans=query(i,j,mid+1,e,rt);
    ans.mod0=lans.mod0+rans.mod0;
    ans.mod1=lans.mod1+rans.mod1;
    ans.mod2=lans.mod2+rans.mod2;
    return ans;
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    init(1,n,1);
  //  scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int type;
        int x,y;
        scanf("%d %d %d",&type,&x,&y);
        if(type==1){
            info ans=query(x+1,y+1,1,n,1);
            printf("%d\n",ans.mod0);
        }
        else if(type==0){
            update(x+1,y+1,1,n,1);
        }
    }
    return 0;
}
