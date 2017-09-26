#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;
typedef pair<int,int> rng;

bool seg[2000005];
vector<rng>post;

void init(int b, int e, int node){
    //cout<<"aschi\n";
    //cout<<b1<<" "<<b2<<" "<<e1<<" "<<e2<<" "<<node<<"\n";
    if(b==e){
        //seg[node].tot=1;
        seg[node]=false;
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
       // seg[node].tot=seg[lt].tot+seg[rt].tot;
        seg[node]=false;
        return;
    }
}

void propagatebelow(int node,int b, int e){
    if(b<e){
        int ll=node<<1;
        int rr=ll+1;
        seg[ll]|=seg[node];
        seg[rr]|=seg[node];
    }
}

void update(int i, int j, int b,int e, int node){
    if(b>e)return;
    propagatebelow(node,b,e);
    if(b>=i && e<=j){
        seg[node]=true;
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
    seg[node]=seg[lt]&seg[rt];
    return;
}

int query(int i, int j, int b, int e, int node){
    if(b>e)return 0;
    propagatebelow(node,b,e);
    if(b>=i && e<=j){
        int mul=0;
        if(seg[node])mul=1;
        return (e-b+1)*mul;
    }
    if(e<i || b>j){
        return 0;
    }
    //int prop=seg[node].lazyval;
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    int lans=query(i,j,b,mid,lt);
    int rans=query(i,j,mid+1,e,rt);
    return lans+rans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        map<int,int>compress;
      //  scanf("%d",&q);
      set<int>pts;
        int mx=-1;
       // int idx=1;
        for(int i=1;i<=n;++i){
            int l,r;
            scanf("%d %d",&l,&r);
            post.push_back(make_pair(l,r));
            pts.insert(l);
            pts.insert(r);
        }
        set<int>::iterator it;
        int idx=1;
        for(it=pts.begin();it!=pts.end();++it){
            compress[*it]=idx;
            idx++;
        }
        mx=idx;
        init(1,mx+2,1);
        int total=0;
        for(int i=n-1;i>=0;--i){
            int l=compress[post[i].first];
            int r=compress[post[i].second];
            int sz=query(l,r,1,mx+2,1);
            if(sz<(r-l+1)){
                total++;
            }
            update(l,r,1,mx+2,1);
        }
        printf("%d\n",total);
        post.clear();

    }
    return 0;
}
