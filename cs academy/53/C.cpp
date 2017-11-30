/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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

int arr[100005];
PII seg[400005];

void init(int b, int e, int node){
    if(b==e){
        seg[node]=make_pair(arr[b],b);
        return;
    }
    if(b>e)return;
    int mid = (b+e)/2;
    int lnode = node<<1; int rnode = lnode+1;
    init(b,mid,lnode); init(mid+1,e,rnode);
    if(seg[lnode].first>seg[rnode].first)seg[node] = seg[lnode];
    else seg[node]=seg[rnode];
}

PII query(int b, int e,int l, int r, int node){
    if(e<l || b>r)return make_pair(-1,-1);
    if(b>=l && e<=r)return seg[node];
    int mid = (b+e)/2;
    int lnode = node<<1; int rnode = lnode+1;
    PII lq = query(b,mid,l,r,lnode); PII rq = query(mid+1,e,l,r,rnode);
    if(lq.first>rq.first)return lq;
    else return rq;
}

int cnt(int n,int l, int r){
    cout<<"in "<<l<<" "<<r<<"\n";
    if(l>r)return 0;
    //set<int>nums;
    int mxidx = query(1,n,l,r,1).second;
    cout<<mxidx<<"\n";
    //nums.insert(arr[mxidx]);
    int rr = mxidx+1;
    while(rr<=r){
        if(arr[rr]>arr[rr-1])break;
        //nums.insert(arr[rr]);
        rr++;
    }
    int ll = mxidx - 1;
    while(ll>=l){
        if(arr[ll]>arr[ll+1])break;
        //nums.insert(arr[ll]);
        ll--;
    }
    int here = 0;
    int cur = arr[mxidx];
    int ln = mxidx-1;
    int rn = mxidx+1;
    while(ln>=(ll+1) || rn<=(rr-1)){
        int lval = -5, rval = -5;
        if(ln>=(ll+1))lval = arr[ln]; if(rn<=(rr-1))rval = arr[rn];
        if(lval>rval){
            if(lval!=cur){
                here++;
                cur = lval;
            }
            ln--;
        }
        else{
            if(rval!=cur){
                here++;
                cur = rval;
            }
        }
    }
    return here+cnt(n,l,ll)+cnt(n,rr,r);
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n)scanf("%d",&arr[i]);
    init(1,n,1);
    printf("%d\n",cnt(n,1,n));
    return 0;
}
