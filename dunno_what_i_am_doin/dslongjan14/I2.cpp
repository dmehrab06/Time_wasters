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

#define MXBIT 20

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI segtree[400005];
PLLI sorter[100005];
LLI mainseq[100005];
int ranker[100005];

bool cmp (pair<long long int, LLI> u,pair<long long int, LLI> v)
{
	return ((u.first<v.first) || ( (u.first==v.first) && (u.second>v.second)));
}

void takeinp(int n){
    FREP(i,1,n){
        int r,h;
        scanf("%d %d",&r,&h);
        mainseq[i] = (LLI)r*(LLI)r*(LLI)h;
        sorter[i] = make_pair(mainseq[i],i);
    }
    sort(sorter+1,sorter+1+n);
    FREP(i,1,n){
        ranker[sorter[i].second] = i;
    }
}

void update(int b, int e, int node, int x, LLI val){
    if(b==e && b==x){segtree[node]=val;return;}
    if(b>x || e<x)return;
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    update(b,mid,ln,x,val); update(mid+1,e,rn,x,val);
    segtree[node] = max(segtree[ln],segtree[rn]);
}

LLI query(int b, int e, int node, int l, int r){
    if(b>=l && e<=r)return segtree[node];
    if(b>r || e<l || b>e)return 0;
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    LLI lans = query(b,mid,ln,l,r); LLI rans = query(mid+1,e,rn,l,r);
    return max(lans,rans);
}

LLI solve(int n){
    FREP(i,1,n){
        int cur = ranker[i];
        LLI mxx = query(1,n,1,1,cur-1);
        update(1,n,1,cur,mainseq[i]+mxx);
    }
    return query(1,n,1,1,n);
}

int main(){
    int n;
    scanf("%d",&n);
    takeinp(n);
    int ans = solve(n);
    printf("%lld\n",ans);
    printf("%.9lf\n",acos(-1.0)*ans);
}
