
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
using namespace std;

struct tour{
    int l,r,cost;
    tour(int _l=0, int _r=0, int _cost = 0){
        l=_l; r=_r; cost = _cost;
    }
};

bool cmp1(tour &a, tour &b){
    if(a.l==b.l){
        return a.cost<b.cost;
    }
    return a.l<b.l;
}

bool cmp2(tour &a, tour &b){
    if(a.r==b.r){
        return a.cost<b.cost;
    }
    return a.r<b.r;
}

vector < vector < vector <tour> > > duration;
vector < vector < VI > >  segtree;

void seginit(int idx, int b, int e, int node, int segidx){
    if(b>e)return;
    if(b==e){
        segtree[segidx][idx][node]=duration[segidx][idx][b].cost;
        return;
    }
    int mid = (b+e)/2;
    int l = node<<1; int r = l+1;
    seginit(idx,b,mid,l,segidx); seginit(idx,mid+1,e,r,segidx);
    segtree[segidx][idx][node]=min(segtree[segidx][idx][l],segtree[segidx][idx][r]);
}

int query(int idx, int b, int e, int i, int j, int node, int segtreeidx){
    //cout<<"at "<<idx<<" "<<b<<" "<<e<<" "<<i<<" "<<j<<" "<<node<<"\n";
    if(b>e || i>j)return 2000000002;
    if(b>=i && e<=j){
        return segtree[segtreeidx][idx][node];
    }
    if(e<i || b>j || b>e)return 2000000002;
    int mid = (b+e)/2;
    int l = node<<1; int r = l+1;
    int lans=query(idx,b,mid,i,j,l,segtreeidx); int rans = query(idx,mid+1,e,i,j,r,segtreeidx);
    return min(lans,rans);
}

int bin_searchgreaterthan(int rr, int idx){
    int lo = 1;
    int hi = duration[0][idx][0].l;
    if(lo>hi)return 2000000000;
    if(duration[0][idx][hi].l<=rr)return 2000000000;
    int ans = -1;
    while(true){
        int mid = (lo+hi)/2;
        int curl = duration[0][idx][mid].l;
        if(curl>rr){
            if(mid>1 && duration[0][idx][mid-1].l>rr){
                hi=mid;
            }
            else{
                ans = mid;
                break;
            }
        }
        else{
            lo = mid+1;
        }
    }
    //cout<<ans<<" "<<duration[0][idx][0].l<<"\n";
    return query(idx,1,duration[0][idx][0].l,ans,duration[0][idx][0].l,1,0);

}

int bin_searchsmallerthan(int ll, int idx){
    int lo = 1;
    int hi = duration[1][idx][0].l;
    if(lo>hi)return 2000000000;
    if(duration[1][idx][lo].r>=ll)return 2000000000;
    int ans = -1;
    while(true){
        int mid = (lo+hi)/2;
        int curr = duration[1][idx][mid].r;
        if(curr<ll){
            if(mid<duration[1][idx][0].l && duration[1][idx][mid+1].r<ll){
                lo=mid+1;
            }
            else{
                ans = mid;
                break;
            }
        }
        else{
            hi = mid;
        }
    }
    //cout<<ans<<" "<<duration[1][idx][0].l<<"\n";;
    return query(idx,1,duration[1][idx][0].l,1,ans,1,1);

}

void init(){
    FREP(t,1,2){
        vector < vector <tour> >liness;
        duration.PB(liness);
        FREP(i,1,200050){
            vector<tour>line;
            duration[t-1].PB(line);
            duration[t-1][i-1].PB(tour(0,0,0));
        }
    }

}

void sortthem(){
    FREP(i,1,200050){
        sort(duration[0][i-1].begin()+1,duration[0][i-1].end(),cmp1);
        sort(duration[1][i-1].begin()+1,duration[1][i-1].end(),cmp2);
    }
    //cout<<"korsi\n";
    FREP(tot,1,2){
        vector< VI >liness;
        segtree.PB(liness);
        FREP(i,1,200050){
            int sz = duration[tot-1][i-1][0].l;
            vector<int>line;
            segtree[tot-1].PB(line);
            FREP(j,1,(4*sz))segtree[tot-1][i-1].PB(0);
            //cout<<"push hoise\n";
            seginit(i-1,1,sz,1,tot-1);
        }
        //cout<<tot<<"\n";
    }
}



tour arr[200005];

int main(){
    init();
    int n,x;
    scanf("%d %d",&n,&x);
    FREP(i,1,n){
        int l,r,cost;
        scanf("%d %d %d",&l,&r,&cost);
        tour t(l,r,cost);
        int dur = r-l+1;
        duration[0][dur].PB(t);
        duration[0][dur][0].l++;
        duration[1][dur].PB(t);
        duration[1][dur][0].l++;
        arr[i]=t;
    }
    sortthem();
    //cout<<"sort hoise\n";
    LLI mnncost = 2000000002;
    FREP(i,1,n){
        int curl = arr[i].l;
        int curr = arr[i].r;
        int curcost = arr[i].cost;
        int idx = x-(curr-curl+1);
        if(idx<=0)continue;
        //cout<<"idx "<<idx<<"\n";
        LLI cost = (LLI)curcost + min(bin_searchgreaterthan(curr,idx),bin_searchsmallerthan(curl,idx));
        mnncost = min(mnncost,cost);
    }
    if(mnncost>2000000000)cout<<"-1\n";
    else cout<<mnncost<<"\n";
    return 0;
}
