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

struct node{
    int p2s,p5s,zeros;
    node(){
        p2s = 0;
        p5s = 0;
        zeros = 0;
    }
    node(int _p2, int _p5, int _z){
        p2s = _p2;
        p5s = _p5;
        zeros = _z;
    }
};

int getdiv(int val, int div){
    if(val==0)return 0;
    int cnt = 0;
    while((val%div)==0){
        val/=div;
        cnt++;
    }
    return cnt;
}

node segtree[300005];
node lazy[300005];
int vals[100005];
int div2[1000005];
int div5[1000005];

void precalc(){
    FREP(i,0,1000000){
        div2[i] = getdiv(i,2);
        div5[i] = getdiv(i,5);
        //cout<<"done for "<<i<<"\n";
    }
}

void traverse(int b, int e, int node){
    if(b>e)return;
    if(b==e){
        cout<<" in node "<<node<<" ranging from "<<b<<" to "<<e<<" contains "<<segtree[node].p2s<<" "<<segtree[node].p5s<<" "<<segtree[node].zeros<<"\n";
        return;
    }
    int mid = (b+e)>>1;
    int ln = node<<1; int rn = ln+1;
    cout<<" in node "<<node<<" ranging from "<<b<<" to "<<e<<" contains "<<segtree[node].p2s<<" "<<segtree[node].p5s<<" "<<segtree[node].zeros<<"\n";
    traverse(b,mid,ln); traverse(mid+1,e,rn);
}

void init(int b, int e, int node){
    if(b>e)return;
    if(b==e){
        segtree[node].p2s = div2[vals[b]];
        segtree[node].p5s = div5[vals[b]];
        segtree[node].zeros = (vals[b]==0?1:0);
        lazy[node].p2s = -1;
        lazy[node].p5s = -1;
        lazy[node].zeros = -1;
        return;
    }
    int mid = (b+e)>>1;
    int ln = node<<1; int rn = ln+1;
    init(b,mid,ln); init(mid+1,e,rn);
    segtree[node].p2s = segtree[ln].p2s+segtree[rn].p2s;
    segtree[node].p5s = segtree[ln].p5s+segtree[rn].p5s;
    segtree[node].zeros = segtree[ln].zeros+segtree[rn].zeros;
    lazy[node].p2s = -1; lazy[node].p5s = -1; lazy[node].zeros = -1;
}

void lazyprop(int b, int e, int curnode){
    if(b>=e)return;

    if(lazy[curnode].p2s==-1)return;

    int ln = curnode<<1; int rn = ln+1;
    int mid = (b+e)>>1;
    segtree[ln].p2s=(lazy[curnode].p2s)*(mid-b+1); lazy[ln].p2s=lazy[curnode].p2s;
    segtree[ln].p5s=(lazy[curnode].p5s)*(mid-b+1); lazy[ln].p5s=lazy[curnode].p5s;
    segtree[rn].p2s=(lazy[curnode].p2s)*(e-mid); lazy[rn].p2s=lazy[curnode].p2s;
    segtree[rn].p5s=(lazy[curnode].p5s)*(e-mid); lazy[rn].p5s=lazy[curnode].p5s;
    segtree[ln].zeros=(lazy[curnode].zeros)*(mid-b+1); lazy[ln].zeros=lazy[curnode].zeros;
    segtree[rn].zeros=(lazy[curnode].zeros)*(e-mid); lazy[rn].zeros=lazy[curnode].zeros;
    lazy[curnode].p2s = -1; lazy[curnode].p5s = -1; lazy[curnode].zeros = -1;
}

void update(int b, int e, int node, int l, int r, int vv){
    if(b>=l && e<=r){
        int d2 = div2[vv]; int d5 = div5[vv];
        int zs = (vv==0)?1:0;
        segtree[node].p2s=(d2*(e-b+1)); segtree[node].p5s=(d5*(e-b+1));
        segtree[node].zeros=(zs*(e-b+1));
        lazy[node].p2s=d2; lazy[node].p5s=d5; lazy[node].zeros=zs;
        return;
    }
    if(b>r || e<l)return;
    lazyprop(b,e,node);
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    update(b,mid,ln,l,r,vv); update(mid+1,e,rn,l,r,vv);
    segtree[node].p2s = segtree[ln].p2s+segtree[rn].p2s;
    segtree[node].p5s = segtree[ln].p5s+segtree[rn].p5s;
    segtree[node].zeros = segtree[ln].zeros+segtree[rn].zeros;
}

pair<int, PII > query(int b, int e, int node, int l, int r){
    if(b>r || e<l)return make_pair(0,make_pair(0,0));
    if(b>=l && e<=r){
        int zz=0;
        if(segtree[node].zeros>0)zz=1;
        int d2 = segtree[node].p2s; int d5 = segtree[node].p5s;
        return make_pair(zz,make_pair(d2,d5));
    }
    lazyprop(b,e,node);
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    pair<int, PII > lans = query(b,mid,ln,l,r);
    pair<int, PII > rans = query(mid+1,e,rn,l,r);
    return make_pair(lans.first|rans.first,make_pair(lans.second.first+rans.second.first,lans.second.second+rans.second.second));
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&vals[i]);
    }
    precalc();
    init(1,n,1);
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        //traverse(1,n,1);
        int type;
        scanf("%d",&type);
        if(type==0){
            int l, r, v;
            scanf("%d %d %d",&l,&r,&v);
            update(1,n,1,l,r,v);
        }
        else{
            int l,r;
            scanf("%d %d",&l,&r);
            pair<int, PII >ans = query(1,n,1,l,r);
            if(ans.first!=0){
                printf("1\n");
            }
            else{
                printf("%d\n",min(ans.second.first,ans.second.second));
            }
        }
    }
    return 0;
}
