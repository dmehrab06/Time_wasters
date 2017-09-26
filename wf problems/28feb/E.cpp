/*-------property of the half blood prince-----*/
//dmehrab06
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


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int arr[200005];
int segtree[600005];
int lazyval[600005];
int querytype[200005];
int queryparam1[200005];
int queryparam2[200005];

SI pointsneeded;

map<int,int>pointmap;


int lowerbinsearch(int val, int n){
    int lo=1;
    int hi=n;
    if(arr[n]<val){
        return (n+1);
    }
    while(true){
        int mid=(lo+hi)/2;
        if(arr[mid]>=val){
            if(mid>1 && arr[mid-1]>=val){
                hi=mid;
            }
            else{
                return mid;
            }
        }
        else{
            lo=mid+1;
        }
    }
}

int upperbinsearch(int val, int n){
    int lo=1;
    int hi=n;
    if(arr[1]>val){
        return 0;
    }
    while(true){
        int mid=(lo+hi)/2;
        if(arr[mid]<=val){
            if(mid<n && arr[mid+1]<=val){
                lo=mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            hi=mid;
        }
    }
}

void init(int l, int r, int curnode){
    if(l>r)return;
    if(l==r){
        segtree[curnode]=0;
        return;
    }
    int mid=(l+r)/2;
    int lnode=curnode<<1;int rnode=lnode+1;
    init(l,mid,lnode);init(mid+1,r,rnode);
    segtree[curnode]=segtree[lnode]+segtree[rnode];
}

void update(int l, int r, int curnode, int i, int j, int val){
    if(l>r || j<l || i>r){
        return;
    }
    if(l>=i && r<=j){
        segtree[curnode]=segtree[curnode]+val;
        lazyval[curnode]+=val;
        return;
    }
    int mid=(l+r)/2;
    int lnode=curnode<<1;
    int rnode=lnode+1;
    update(l,mid,lnode,i,j,val);
    update(mid+1,r,rnode,i,j,val);
    segtree[curnode]=segtree[lnode]+segtree[rnode];
}

void lazy(int l, int r,int curnode){
    if(l==r){
        return;
    }
    int lnode=curnode<<1; int rnode=lnode+1;
    segtree[lnode]+=lazyval[curnode];segtree[rnode]+=lazyval[curnode];
    lazyval[lnode]+=lazyval[curnode];lazyval[rnode]+=lazyval[curnode];
    lazyval[curnode]=0;
}

int query(int l, int r, int curnode, int x){
    if(l>r || x<l || x>r)return 0;
    if(l>=x && r<=x)return segtree[curnode];
    lazy(l,r,curnode);
    int mid=(l+r)/2;
    int lnode=curnode<<1;int rnode=lnode+1;
    int lans=query(l,mid,lnode,x);int rans=query(mid+1,r,rnode,x);
    return lans+rans;
}

void printsegtree(int l, int r, int curnode){
    if(l>r)return;
    if(l==r){
        printf("in range %d %d : %d\n",l,r,segtree[curnode]);
        return;
    }
    int mid=(l+r)/2;
    int lnode=curnode<<1;
    int rnode=lnode+1;
    printf("in range %d %d : %d\n",l,r,segtree[curnode]);
    printsegtree(l,mid,lnode);
    printsegtree(mid+1,r,rnode);
}

void printarr(int n){
    FREP(i,1,n){
        printf("%d : %d\n",i,arr[i]);
    }
}

ifstream fin("environment.in");
ofstream fout("environment.out");

int main(){
    int n;
    fin>>n;
    FREP(i,1,n){
        fin>>querytype[i];
        if(querytype[i]==1){
            fin>>queryparam1[i]>>queryparam2[i];
        }
        else{
            fin>>queryparam1[i];
            pointsneeded.insert(queryparam1[i]);
        }
    }
    SI::iterator it;
    int tot=0;
    for(it=pointsneeded.begin();it!=pointsneeded.end();++it){
        int curpoint=*it;
        arr[++tot]=curpoint;
        pointmap[curpoint]=tot;
    }
    //printarr(tot);
    int d=0;
    init(1,tot,1);
    FREP(i,1,n){
        if(querytype[i]==1){
            int lpoint=queryparam1[i]+d;
            int rpoint=queryparam2[i]+d;
            //cout<<"query 1: "<<lpoint<<" "<<rpoint<<"\n";
            int lidx=lowerbinsearch(lpoint,tot);
            int ridx=upperbinsearch(rpoint,tot);
            //cout<<"idx: "<<lidx<<" "<<ridx<<"\n";
            if(lidx>ridx){
                continue;
            }
            update(1,tot,1,lidx,ridx,1);
        }
        else{
            int curp=queryparam1[i];
            int idx=pointmap[curp];
            int ans=query(1,tot,1,idx);
            d=ans;
            fout<<ans<<"\n";
        }
        //printsegtree(1,tot,1);
    }
    fin.close();
    fout.close();
    return 0;
}
