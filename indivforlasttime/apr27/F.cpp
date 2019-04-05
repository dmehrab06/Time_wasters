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

int segtree[1200005];
int cumsum[300005];
int lazy[1200005];
string brak;


void construct(){
    int l = brak.size();
    FREP(i,0,(l-1)){
        if(brak[i]=='('){
            cumsum[i+1] = 1;
        }
        else{
            cumsum[i+1] = -1;
        }
    }
    FREP(i,1,l)cumsum[i]+=cumsum[i-1];

}


void init(int node, int b, int e){
    if(b==e){
        segtree[node] = cumsum[b];
        lazy[node] = 0;
        return;
    }
    int ln = node<<1; int rn = ln+1;
    int m = (b+e)>>1;
    init(ln,b,m);
    init(rn,m+1,e);
    segtree[node] = min(segtree[ln],segtree[rn]);
    lazy[node] = 0;
}

void prop(int node, int b, int e){
    if(b!=e){
        int ln = node<<1; int rn = ln+1;
        //int m = (b+e)>>1;
        lazy[ln]+=lazy[node]; lazy[rn]+=lazy[node];
        segtree[ln]+=lazy[node]; segtree[rn]+=lazy[node];
        segtree[node] = min(segtree[ln],segtree[rn]);
        lazy[node] = 0;
    }
    return;
}

void update(int node, int b, int e, int l, int r, int val){
    if(b>r || e<l)return;
    if(b>=l && e<=r){segtree[node]+=val; lazy[node]+=val; return;}
    prop(node,b,e);
    int ln = node<<1; int rn = ln+1;
    int m = (b+e)>>1;
    update(ln,b,m,l,r,val); update(rn,m+1,e,l,r,val);
    segtree[node] = min(segtree[ln],segtree[rn]);
}

int query(int node, int b, int e, int l, int r){
    if(b>r || e<l)return 1000000000;
    if(b>=l && e<=r)return segtree[node];
    prop(node,b,e);
    int ln = node<<1; int rn = ln+1;
    int m = (b+e)>>1;
    int lans = query(ln,b,m,l,r); int rans = query(rn,m+1,e,l,r);
    return min(lans,rans);
}

int query1(int pos, int n){
    int lo = 1;
    int hi = pos;
    while((lo+1)<hi){
        int m = (lo+hi)>>1;
        int mnn = query(1,1,n,m,m);
        if(mnn<=(m-2))hi = m;
        else lo = m;
    }
    if(query(1,1,n,lo,lo)<=(lo-2))return lo;
    else return hi;
}

int query2(int pos, int n){
    int lo = 1;
    int hi = pos;
    while((lo+1)<hi){
        int m = (lo+hi)>>1;
        int mnn = query(1,1,n,m,n);
        if(mnn>=2)hi = m;
        else lo = m;
    }
    if(query(1,1,n,lo,n)>=2)return lo;
    else return hi;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    while(cin>>n>>q){
        cin>>brak;
        construct();
        //MSET(lazy,0);
        init(1,1,n);
        FREP(i,1,q){
            int flip;
            cin>>flip;
            if(brak[flip-1]=='('){
                brak[flip-1] = ')';
                update(1,1,n,flip,n,-2);
                int ans = query1(flip,n);
                update(1,1,n,ans,n,2);
                brak[ans-1] = '(';
                cout<<ans<<"\n";
            }
            else if(brak[flip-1]==')'){
                brak[flip-1] = '(';
                update(1,1,n,flip,n,2);
                int ans = query2(flip,n);
                update(1,1,n,ans,n,-2);
                brak[ans-1] = ')';
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
