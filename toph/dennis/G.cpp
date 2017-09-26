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
#define OPEN first
#define CLOS second
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

char brack[100005];

PII segtree[400005];

void init(int b, int e, int node){
    if(b>e)return;
    if(b==e){
        if(brack[b-1]==')'){
            segtree[node].CLOS = 1; segtree[node].OPEN = 0;
        }
        else{
            segtree[node].CLOS = 0; segtree[node].OPEN = 1;
        }
        return ;
    }
    int mid = (b+e)/2;
    int lnode = node<<1; int rnode = lnode+1;
    init(b,mid,lnode); init(mid+1,e,rnode);
    segtree[node].CLOS = segtree[lnode].CLOS+segtree[rnode].CLOS;
    segtree[node].OPEN = segtree[lnode].OPEN+segtree[rnode].OPEN;
    return;
}

void update(int b, int e, int node, int idx){
    if(b>idx || e<idx)return;
    if(b==e && b==idx){
        if(brack[b-1]==')'){
            brack[b-1]='(';
            segtree[node].OPEN = 1; segtree[node].CLOS = 0;
        }
        else{
            brack[b-1]=')';
            segtree[node].CLOS = 1; segtree[node].OPEN = 0;
        }
        return ;
    }
    int mid = (b+e)/2;
    int lnode = node<<1; int rnode = lnode+1;
    update(b,mid,lnode,idx); update(mid+1,e,rnode,idx);
    segtree[node].CLOS = segtree[lnode].CLOS+segtree[rnode].CLOS;
    segtree[node].OPEN = segtree[lnode].OPEN+segtree[rnode].OPEN;
    return;
}

PII query(int b, int e, int node, int i, int j){
    if(b>j || e<i)return make_pair(0,0);
    if(b>=i && e<=j)return segtree[node];
    int mid = (b+e)/2;
    int lnode = node<<1; int rnode = lnode+1;
    PII ans1 = query(b,mid,lnode,i,j); PII ans2 = query(mid+1,e,rnode,i,j);
    return make_pair(ans1.OPEN+ans2.OPEN,ans1.CLOS+ans2.CLOS);
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        scanf("%s",brack);
        int ll = strlen(brack);
        init(1,ll,1);
        int q;
        printf("Case %d:\n",cs);
        scanf("%d",&q);
        while(q--){
            int type;
            scanf("%d",&type);
            if(type==1){
                int l,r;
                scanf("%d %d",&l,&r);
                PII ans = query(1,ll,1,l,r);
                if(ans.OPEN==ans.CLOS){
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }
            }
            else{
                int idx;
                scanf("%d",&idx);
                update(1,ll,1,idx);
            }
        }
    }
    return 0;
}
