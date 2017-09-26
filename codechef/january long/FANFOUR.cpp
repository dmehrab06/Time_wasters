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

LLI sqr[1000005];
LLI mdd;
LLI segtree[400005];
LLI arr[100005];

void init(int b, int e, int node){
    if(b==e){
        segtree[node]=arr[b]%mdd;
        return;
    }
    if(b>e)return;
    else{
        int lt=node<<1;
        int rt=lt+1;
        int mid=(b+e)>>1;
        init(b,mid,lt);
        init(mid+1,e,rt);
        segtree[node]=(segtree[lt]*segtree[rt])%mdd;
        return;
    }
}

LLI query(int i, int j, int b, int e, int node){
    if(b>=i && e<=j){
        return segtree[node];
    }
    if(e<i || b>j){
        return 1%mdd;
    }
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    LLI leftinfo=query(i,j,b,mid,lt);
    LLI rightinfo=query(i,j,mid+1,e,rt);
    LLI tosend=(leftinfo*rightinfo)%mdd;
    return tosend;
}

void update(int i, int b,int e, int node,int val){
    if(b==i && e==i){
        segtree[node]=val%mdd;
        return;
    }
    if(e<i || b>i){
        return;
    }
    //if(b1>e1 || b2>e2)return;
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    update(i,b,mid,lt,val);
    update(i,mid+1,e,rt,val);
    //segtree[node]=segtree[left]+segtree[right];
    segtree[node]=(segtree[lt]*segtree[rt])%mdd;
    return;
}

void makesqr(){
    FREP(i,0,1000004){
        sqr[i]=(LLI)i*(LLI)i;
    }
}

int binsearch(LLI score){
    int lo=0;
    int hi=1000004;
    while(true){
        int mid=(lo+hi)/2;
        if(sqr[mid]<=score){
            if(mid<1000004 && sqr[mid+1]<=score){
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

unsigned long long llrand() {
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return (r & 0xFFFFFFFFFFFFFFFFULL)%928037044463;
}

int ans[6];

map<LLI, pair<PII,PII> >ansmap;

map< pair<LLI,int>, int >dpmap;

void solve(LLI make, int cur){
  //  cout<<"in make: "<<make<<" cur "<<cur<<"\n";
    if(cur==1){
        int idx=binsearch(make);
        if(sqr[idx]==make){
            ans[cur]=idx;
        }
        else{
            ans[cur]=-1;
        }
        return;
    }
    pair<LLI,int>oka=make_pair(make,cur);
    if(dpmap.find(oka)!=dpmap.end()){
        int gt=dpmap[oka];
        solve(make-gt,cur-1);
        ans[cur]=gt;
        return;
    }
    int idx=binsearch(make);
    RFREP(k,idx,0){
        solve(make-sqr[k],cur-1);
        if(ans[cur-1]!=-1){
            ans[cur]=k;
            dpmap[oka]=k;
            return;
        }
    }
    ans[cur]=-1;
    return;
}

int main(){
    makesqr();
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d %lld",&n,&q,&mdd);
        FREP(i,1,n){
            scanf("%lld",&arr[i]);
        }
        init(1,n,1);
        while(q--){
            int type;
            scanf("%d",&type);
            if(type==1){
                int x, y;
                scanf("%d %d",&x,&y);
                update(x,1,n,1,y);
            }
            else if(type==2){
                int l,r;
                scanf("%d %d",&l,&r);
                LLI multi=query(l,r,1,n,1);
                //cout<<multi<<"\n";
                if(multi<0){
                    printf("mairalam\n");
                    continue;
                }
                FREP(k,1,4)ans[k]=-1;
                LLI twopow=1;
                while(multi>0 && multi%4==0){
                    multi/=4;
                    twopow*=2;
                }
                if(ansmap.find(multi)!=ansmap.end()){
                    pair<PII,PII>oka=ansmap[multi];
                    printf("%lld %lld %lld %lld\n",twopow*oka.first.first,twopow*oka.first.second,twopow*oka.second.first,twopow*oka.second.second);
                    continue;
                }
                solve(multi,4);
                if(ans[1]==-1){
                    printf("-1\n");
                }
                else{
                    FREP(k,1,4){
                        if(k>1)printf(" ");
                        printf("%lld",twopow*ans[k]);
                    }
                    ansmap[multi]=make_pair(make_pair(ans[1],ans[2]),make_pair(ans[3],ans[4]));
                    printf("\n");
                }
            }
            else{
                LLI tofind;
                tofind=(LLI)llrand();
                //tofind%=1000000000000;
                printf("%lld\n",tofind);
                solve(tofind,4);
                printf("%d %d %d %d\n",ans[1],ans[2],ans[3],ans[4]);

            }
        }
    }
    return 0;
}


