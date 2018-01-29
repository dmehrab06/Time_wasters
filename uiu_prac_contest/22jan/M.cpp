/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
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
//using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int segtree[4000005];

void update(int b, int e, int node, int x, int val){
    if(b==e && b==x){
        segtree[node] += val;
        return;
    }
    if(b>e || b>x || e<x)return;
    int m = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    update(b,m,ln,x,val); update(m+1,e,rn,x,val);
    segtree[node] = segtree[ln]+segtree[rn];
}

int query(int b, int e, int node, int ll, int rr){
    if(b>=ll && e<=rr){
        return segtree[node];
    }
    if(b>rr || e<ll)return 0;
    int m = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    int lans = query(b,m,ln,ll,rr); int rans = query(m+1,e,rn,ll,rr);
    return lans+rans;
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    FREP(i,1,q){
        char comm[10];
        scanf("%s",comm);
        if(comm[0]=='a'){
            int x,val;
            scanf("%d %d",&x,&val);
            update(1,n,1,x,val);
        }
        else{
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%d\n",query(1,n,1,a,b));
        }
    }
    return 0;
}
