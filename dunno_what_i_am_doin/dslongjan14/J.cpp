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

int twopows[MXBIT+1];
int seg[300005][MXBIT+1]; //seg[i][j] number of 1s in range of node j at ith bit
int lazy[300005][MXBIT+1];
int arr[100005][MXBIT+1];

void init(int b, int e, int node, int bit){
    if(b==e){
        seg[node][bit] = arr[b][bit];
        return;
    }
    if(b>e)return;
    int mid = (b+e)>>1; int l = node<<1; int r = l+1;
    init(b,mid,l,bit); init(mid+1,e,r,bit);
    seg[node][bit] = seg[l][bit]+seg[r][bit];
}

void printtree(int b, int e, int node, int bit){
    if(b==e){
        cout<<"from "<<b<<" to "<<e<<" has "<<seg[node][bit]<<" ones\n";
        //seg[node][bit] = arr[b][bit];
        return;
    }
    if(b>e)return;
    int mid = (b+e)>>1; int l = node<<1; int r = l+1;
    printtree(b,mid,l,bit); printtree(mid+1,e,r,bit);
    //seg[node][bit] = seg[l][bit]+seg[r][bit];
    cout<<"from "<<b<<" to "<<e<<" has "<<seg[node][bit]<<" ones\n";
}

void printlazy(int b, int e, int node, int bit){
    if(b==e){
        cout<<"from "<<b<<" to "<<e<<" has lazy "<<lazy[node][bit]<<" xor\n";
        //seg[node][bit] = arr[b][bit];
        return;
    }
    if(b>e)return;
    int mid = (b+e)>>1; int l = node<<1; int r = l+1;
    printtree(b,mid,l,bit); printtree(mid+1,e,r,bit);
    //seg[node][bit] = seg[l][bit]+seg[r][bit];
    cout<<"from "<<b<<" to "<<e<<" has "<<lazy[node][bit]<<" ones\n";
}

int pre(){
    twopows[0]=1;
    FREP(i,1,MXBIT)twopows[i]=twopows[i-1]*2;

    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        int a;
        scanf("%d",&a);
        FREP(j,0,MXBIT){
            arr[i][j] = (a&1);
            a/=2;
        }
    }
    FREP(j,0,MXBIT){
        init(1,n,1,j);
    }
    return n;
}

void printnums(int n){
    FREP(i,1,n){
        RFREP(j,MXBIT,0){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
}

void lazyprop(int node, int bit, int b, int e){
    if(b<e){
        int t = lazy[node][bit];
        if(t){
            int l = node<<1; int r = l+1;
            int mid = (b+e)>>1; int lcnt = (mid-b+1); int rcnt = (e-mid);
            seg[l][bit] = lcnt-(seg[l][bit]); seg[r][bit] = rcnt-(seg[r][bit]);
            lazy[l][bit]^=1; lazy[r][bit]^=1;
            lazy[node][bit] = 0;
        }
    }
}

void update(int b, int e, int node, int x, int l, int r, int bit){
    if(b>r || e<l)return;
    if(b>=l && e<=r){
        int bt = x & (1<<bit);
        if(bt){
            seg[node][bit] = (e-b+1)-(seg[node][bit]);
            lazy[node][bit]^=1;
        }
        return;
    }
    lazyprop(node,bit,b,e);
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    update(b,mid,ln,x,l,r,bit); update(mid+1,e,rn,x,l,r,bit);
    seg[node][bit] = seg[ln][bit]+seg[rn][bit];
}

int query(int b, int e, int node, int l, int r, int bit){
    if(b>r || e<l)return 0;
    if(b>=l && e<=r){
        return seg[node][bit];
    }
    lazyprop(node,bit,b,e);
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    int lans = query(b,mid,ln,l,r,bit); int rans = query(mid+1,e,rn,l,r,bit);
    return lans+rans;
}

LLI solve(int l , int r, int n){
    LLI ans = 0;
    FREP(bit,0,MXBIT){
        int cnt_1 = query(1,n,1,l,r,bit);
        //cout<<"number of 1s in "<<bit<<" "<<cnt_1<<"\n";
        int pw = twopows[bit];
        ans = ans+(LLI)cnt_1*pw;
    }
    return ans;
}

void xor_update(int l , int r, int x, int n){
    FREP(bit,0,MXBIT){
        update(1,n,1,x,l,r,bit);
    }
}

int main(){
    int n = pre();
    int m;
    scanf("%d",&m);
    FREP(i,1,m){
        int type;
        scanf("%d",&type);
        if(type==1){
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%lld\n",solve(l,r,n));
            //printtree(1,n,1,0);
        }
        else{
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            xor_update(l,r,x,n);
            //printtree(1,n,1,0);
        }
    }
    return 0;
}
