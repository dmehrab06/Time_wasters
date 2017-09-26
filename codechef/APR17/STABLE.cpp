/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000000000000
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < PII, null_type, less<PII>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int market[100005];
int blocks[100005];
int startpos[100005];
int blocksize[100005];

ordered_set segtree[600005];

void init(int l, int r, int node){
    int t=1;
    FREP(i,l,r) segtree[node].insert(make_pair(blocksize[i],t++));
    if(l>=r)return;
    int mid=(l+r)/2; int lt=node<<1; int rt=lt+1;
    init(l,mid,lt); init(mid+1,r,rt);
}

void del(int l, int r, int node){
    segtree[node].clear();
    if(l>=r)return;
    int mid=(l+r)/2; int lt=node<<1; int rt=lt+1;
    del(l,mid,lt); del(mid+1,r,rt);
}

int query(int l, int r, int node, int i, int j, int x){
    if(r<i || l>j || i>j)return 0;
    if(l>=i && r<=j){
        int sz=segtree[node].size();
        int ss=segtree[node].order_of_key(make_pair(x,0));
        return max(0,sz-ss);
    }
    int mid=(l+r)/2; int lt=node<<1; int rt=lt+1;
    return query(l,mid,lt,i,j,x)+query(mid+1,r,rt,i,j,x);
}

int calcstart(int n){
    int cnt=1;
    startpos[cnt++]=1;
    FREP(i,2,n){
        if(market[i]!=market[i-1]) startpos[cnt++]=i;
    }
    startpos[cnt]=n+1;
    return cnt-1;
}

int calcblocksize(int n){
    int tot=calcstart(n);
    FREP(i,1,tot){
        blocksize[i]=startpos[i+1]-startpos[i];
    }
    return tot;
}

int bs1(int ll, int tot){
    //first number strictly greater than ll
    //ll je block e ache tarer porer block
    int l=1;
    int r=tot+1;
    while(true){
        int mid=(l+r)/2;
        int val=startpos[mid];
        if(val>ll){
            if(mid<=1 || startpos[mid-1]<=ll){
                return mid;
            }
            else{
                r=mid;
            }
        }
        else{
            l=mid+1;
        }
    }
}

int bs2(int rr, int tot){
    //last number less than or eq to rr
    //rr je block e ache tar ager block
    int l=1;
    int r=tot;
    while(true){
        int mid=(l+r)/2;
        int val=startpos[mid];
        if(val<=rr){
            if(startpos[mid+1]>rr){
                return mid;
            }
            else{
                l=mid+1;
            }
        }
        else{
            r=mid;
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        FREP(i,1,n){
            scanf("%d",&market[i]);
        }
        int tot=calcblocksize(n);
        del(1,tot,1);
        init(1,tot,1);
        FREP(i,1,q){
            int l,r,k;
            scanf("%d %d %d",&l,&r,&k);
            int lblockidx=bs1(l,tot);
            int rblockidx=bs2(r,tot)-1;
            //cout<<"lidx: "<<lblockidx<<" ridx: "<<rblockidx<<"\n";
            int ans=query(1,tot,1,lblockidx,rblockidx,k);
            int leftblock=lblockidx-1;
            int rightblock=rblockidx+1;
            //cout<<"leftblock: "<<leftblock<<" rightblock: "<<rightblock<<"\n";
            if(leftblock==rightblock){
              //  cout<<"same block\n";
                int sz=(r-l)+1;
                if(sz>=k)ans++;
               // cout<<sz<<"\n";
            }
            else{
               // cout<<"diff blocks\n";
                int lsz=startpos[leftblock+1]-l;
                if(lsz>=k)ans++;
                int rsz=r-startpos[rightblock]+1;
                if(rsz>=k)ans++;
               // cout<<lsz<<" "<<rsz<<"\n";
            }
            printf("%d\n",ans);
        }

    }
    return 0;
}
