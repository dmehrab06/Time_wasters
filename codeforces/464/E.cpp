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


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

map< pair<int,int> , int >pntcompress;

set< pair<int,int> >allpts;

pair<int,int> queries[500005];

ordered_set bin_srch_positions;

int compresspoints(){
    set< pair<int,int> >::iterator it;
    int cur = 0;
    for(it = allpts.begin(); it!=allpts.end() ; ++it){
        PII curpt = *it;
        pntcompress[curpt] = (++cur);
    }
    return cur;
}

LLI segtree[2000005];

void update(int b, int e, int node, int pos, int x){
    if(b>pos || e<pos || b>e)return;
    if(b==e && b==pos){
        segtree[node]  = x;
        return;
    }
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    update(b,mid,ln,pos,x); update(mid+1,e,rn,pos,x);
    segtree[node] = segtree[ln]+segtree[rn];
}

LLI query(int b, int e, int node, int ll, int rr){
    if(b>rr || e<ll)return 0;
    if(b>=ll && e<=rr)return segtree[node];
    int mid = (b+e)>>1; int ln = node<<1; int rn = ln+1;
    LLI lans = query(b,mid,ln,ll,rr); LLI rans = query(mid+1,e,rn,ll,rr);
    return lans+rans;
}

void processtype1(int queryidx, int tot){
    PII tofind = make_pair(queries[queryidx].second,queryidx);
    int pos = pntcompress[tofind];
    //ei pos e jeye value ta segtree te point update korte hobe
    update(1,tot,1,pos,queries[queryidx].second);
    bin_srch_positions.insert(pos);
}

double processtype2(int tot, int mxval){
    int ase = bin_srch_positions.size();
    int lo = 1;
    int hi = ase-1;
    int tlo = lo;
    int thi = hi;
    if(lo>hi)return (double)mxval;
    //double mxval = 0.0;
    while(true){
        int mid = lo+(hi-lo)/2;
        //cout<<lo<<" "<<hi<<"\n";
        int postojog = *(bin_srch_positions.find_by_order(mid-1));
        LLI jogfol = query(1,tot,1,1,postojog);
        double avghere = (double)(jogfol+mxval)/(double)(mid+1);
        double avgleft = 1000000000000.00;
        double avgright = 1000000000000.00;
        if((mid+1)<=thi){
            int postojogright = *(bin_srch_positions.find_by_order(mid));
            LLI jogfolright = query(1,tot,1,1,postojogright);
            avgright = (double)(jogfolright+mxval)/(double)(mid+2);
        }
        if((mid-1)>=tlo){
            int postojogleft = *(bin_srch_positions.find_by_order(mid-2));
            LLI jogfolleft = query(1,tot,1,1,postojogleft);
            avgleft = (double)(jogfolleft+mxval)/(double)(mid);
        }
        if((avgright<avghere) || (fabs(avgright-avghere)<eps)){
            lo = mid+1;
        }
        else if(avgleft<avghere){
            hi = mid;
        }
        else{
            return avghere;
        }
    }
    return -100.000; //should not happen
}

int main(){
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        int type;
        scanf("%d",&type);
        if(type==1){
            int x;
            scanf("%d",&x);
            queries[i] = make_pair(type,x);
            allpts.insert(make_pair(x,i));
        }
        else{
            queries[i] = make_pair(type,-1);
        }
    }
    int totpoint = compresspoints();
    int mxx = 0;
    FREP(i,1,q){
        int t = queries[i].first;
        mxx = max(queries[i].second,mxx);
        if(t==1){
            processtype1(i,totpoint);
        }
        else{
            double avg = processtype2(totpoint,mxx);
            double ans = (double)mxx-avg;
            printf("%.8lf\n",ans);
        }
    }
    return 0;
}
