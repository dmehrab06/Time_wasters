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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

//int st[200005];
int ed[200005];
PII segtree[800005];
int arr[100005];
int cnt[200005];

int shiftval = 100002;

PII maxp(PII p1, PII p2){
    if(p1.first>p2.first)return p1;
    return p2;
}

int getstartidx(int num){
    int e = ed[num];
    int cc = cnt[num];
    return e-cc+1;
}

void init(){
    //memset(st,0,sizeof(st));
    //memset(ed,0,sizeof(ed));
    memset(cnt,0,sizeof(cnt));
}

void printseg(int node, int l, int r, int ll, int rr){
    if(l>=ll && r<=rr)cout<<"in node "<<node<<" l "<<l-shiftval<<" r "<<r-shiftval<<" has "<<segtree[node].first<<" "<<segtree[node].second-shiftval<<"\n";
    if(l==r){
        return;
    }
    int mid = (l+r)/2;
    int lft = node<<1; int rgt = lft+1;
    printseg(lft,l,mid,ll,rr); printseg(rgt,mid+1,r,ll,rr);
}

void build(int node, int l, int r){
    if(l==r){
        segtree[node].first = cnt[l];
        segtree[node].second = l;
        return;
    }
    int mid = (l+r)/2;
    int lft = node<<1; int rgt = lft+1;
    build(lft,l,mid); build(rgt,mid+1,r);
    if(segtree[lft].first>segtree[rgt].first)segtree[node]=segtree[lft];
    else segtree[node]=segtree[rgt];
}

PII query(int node, int l, int r, int val1, int val2){
    if(l>val2 || r<val1 || val1>val2)return make_pair(0,0);
    if(l>=val1 && r<=val2)return segtree[node];
    int mid = (l+r)/2;
    int lft = node<<1; int rgt = lft+1;
    PII ansl = query(lft,l,mid,val1,val2); PII ansr = query(rgt,mid+1,r,val1,val2);
    if(ansl.first>ansr.first)return ansl;
    else return ansr;
}

//set<int>nums;

int main(){
    int n;
    while(scanf("%d",&n)){
        init();
        int q;
        scanf("%d",&q);
        int mnn=1000000000;
        int mxx=-1000000000;
        FREP(i,1,n){
            scanf("%d",&arr[i]);
            mnn=min(mnn,arr[i]);
            mxx=max(mxx,arr[i]);
            //if(st[arr[i]+shiftval]==0)st[arr[i]+shiftval]=i;
            //ed[arr[i]+shiftval]=i;
            //cnt[arr[i]+shiftval]++;
            //nums.insert(arr[i]);
        }
        if(mnn<=0)shiftval=abs(mnn)+1;
        else shiftval=0;
        mnn=min(1,mnn+shiftval);
        mxx=mxx+shiftval;
        FREP(i,1,n){
            ed[arr[i]+shiftval]=i;
            cnt[arr[i]+shiftval]++;
        }
       /* set<int>::iterator it;
        for(it=nums.begin();it!=nums.end();++it){
            int v =*it;
            cout<<v<<"\n";
            cout<<"start "<<st[v+shiftval]<<"\n";
            cout<<"end "<<ed[v+shiftval]<<"\n";
            cout<<"freq "<<cnt[v+shiftval]<<"\n\n";
        }*/
        build(1,mnn,mxx);
        //printseg(1,1,200004,100000,100020);
        FREP(i,1,q){
            int l,r;
            scanf("%d %d",&l,&r);
            int val1 = arr[l]+shiftval;
            int val2 = arr[r]+shiftval;
            if(val1==val2){
                printf("%d\n",(r-l+1));
            }
            else{
                int stidx = ed[val1]+1;
                int edidx = getstartidx(val2)-1;
                if(stidx>edidx){
                    int llfreq = ed[val1]-l+1; PII p1 = make_pair(llfreq,val1);
                    int rrfreq = r-getstartidx(val2)+1; PII p2 = make_pair(rrfreq,val2);
                    PII myp = maxp(p1,p2);
                    printf("%d\n",myp.first);
                }
                else{
                    int lval = arr[stidx]+shiftval;
                    int rval = arr[edidx]+shiftval;
                    //cout<<lval-shiftval<<" "<<rval-shiftval<<"\n";
                    //cout<<cnt[lval]<<" "<<cnt[rval]<<"\n";
                    PII qq = query(1,mnn,mxx,lval,rval);
                    int llfreq = ed[val1]-l+1; PII p1 = make_pair(llfreq,val1);
                    int rrfreq = r-getstartidx(val2)+1; PII p2 = make_pair(rrfreq,val2);
                    PII myp = maxp(p1,maxp(p2,qq));
                    printf("%d\n",myp.first);
                }
            }
        }
    }
    return 0;
}
