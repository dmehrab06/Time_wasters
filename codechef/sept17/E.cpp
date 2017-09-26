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
using namespace std;
using namespace __gnu_pbds;
#define MDD 1000000007
#define FEMSIZE 200005

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI seg[2][300005]; //0 for query //1 for final thingy
LLI lazy[2][300005];

int type[100005];
int ql[100005];
int qr[100005];

LLI add(LLI prev, LLI val){
    return (prev+val)%MDD;
}

void init(){
    memset(seg,0,sizeof(seg));
    memset(lazy,0,sizeof(lazy));
}

void update(int node, int left, int right, int i, int j, LLI val, int treeidx)
{
    if (left>right || left>j || right<i) return ;

    int lchild = node<<1; int rchild = lchild+1;

    if (lazy[treeidx][node]!= 0){
        LLI valadd = (LLI)lazy[treeidx][node]*(LLI)(right-left+1); valadd%=MDD;
        seg[treeidx][node] =  add(seg[treeidx][node],valadd);
        if (left != right){
            lazy[treeidx][lchild]=add(lazy[treeidx][lchild],lazy[treeidx][node]);
            lazy[treeidx][rchild]=add(lazy[treeidx][rchild],lazy[treeidx][node]);
        }
        lazy[treeidx][node]=0;
    }

    if (left>=i && right<=j){
        LLI valadd = (LLI)val*(LLI)(right-left+1); valadd%=MDD;
        seg[treeidx][node] = add(seg[treeidx][node],valadd);
        if (left!=right){
            lazy[treeidx][lchild]=add(lazy[treeidx][lchild],val);
            lazy[treeidx][rchild]=add(lazy[treeidx][rchild],val);
        }
        return;
    }

    int mid = (left+right)>>1;
    update(lchild, left, mid, i, j, val, treeidx);
    update(rchild, mid+1, right, i, j, val, treeidx);
    seg[treeidx][node] = add(seg[treeidx][lchild],seg[treeidx][rchild]);
}

LLI query(int node, int left, int right, int i, int j, int treeidx)
{
    if (left>right || left>j || right<i) return 0;

    int lchild = node<<1; int rchild = lchild+1;

    if (lazy[treeidx][node]!= 0){
        LLI valadd = (LLI)lazy[treeidx][node]*(LLI)(right-left+1); valadd%=MDD;
        seg[treeidx][node] =  add(seg[treeidx][node],valadd);
        if (left != right){
            lazy[treeidx][lchild]=add(lazy[treeidx][lchild],lazy[treeidx][node]);
            lazy[treeidx][rchild]=add(lazy[treeidx][rchild],lazy[treeidx][node]);
        }
        lazy[treeidx][node]=0;
    }

    if (left>=i && right<=j) return seg[treeidx][node];

    int mid = (left+right)>>1;
    LLI ll = query(lchild, left, mid, i, j, treeidx);
    LLI rr = query(rchild, mid+1, right, i, j, treeidx);
    LLI ans = add(ll,rr); return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        int n,q;
        scanf("%d %d",&n,&q);
        FREP(i,1,q){
            scanf("%d %d %d",&type[i],&ql[i],&qr[i]);
        }
        update(1,1,q,1,q,1,0); //sokol query initially 1 bola holo;
        RFREP(i,q,1){ //traverse in reverse order
            if(type[i]==1)continue;
            LLI cur = query(1,1,q,i,i,0); //ei query er opertaion time
            int l = ql[i]; int r = qr[i];
            update(1,1,q,l,r,cur,0);
        }
        //ekhon kon query kotobar chalate hobe jana ase
        FREP(i,1,q){
            if(type[i]==2)continue;
            LLI freq = query(1,1,q,i,i,0); //original tree te ei value barate hobe
            int l = ql[i]; int r = qr[i];
            update(1,1,n,l,r,freq,1);
        }

        FREP(i,1,n){
            printf("%lld ",query(1,1,n,i,i,1));
        }
        printf("\n");
    }
}
