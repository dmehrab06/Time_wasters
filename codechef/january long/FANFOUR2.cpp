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

long long int mulmod(long long int a,long long int b, long long int M) {
    if (M <= 1000000009) return a * b % M;

    long long int res = 0;
    while (a > 0) {
        if (a & 1) {
            res += b;
            if (res >= M) res -= M;
        }
        a >>= 1;
        b <<= 1;
        if (b >= M) b -= M;
    }
    return res;
}

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI sqr[1000005];
LLI mdd;
LLI segtree[400005];
LLI arr[100005];

int mapvals1=1;
int mapvals2=1;

map<LLI,int>cmprs1;
map<LLI,int>cmprs2;

LLI dp[3000005][4];

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
        //segtree[node]=(segtree[lt]*segtree[rt])%mdd;
        if(segtree[lt]>1000000000 || segtree[rt]>1000000000){
            segtree[node]=mulmod(segtree[lt],segtree[rt],mdd);
        }
        else{
            segtree[node]=(segtree[lt]*segtree[rt])%mdd;
        }
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
    LLI tosend;
    if(leftinfo>1000000000 || rightinfo>1000000000){
        tosend=mulmod(leftinfo,rightinfo,mdd);
    }
    else{
        tosend=(leftinfo*rightinfo)%mdd;
    }
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
    if(segtree[lt]>1000000000 || segtree[rt]>1000000000){
        segtree[node]=mulmod(segtree[lt],segtree[rt],mdd);
    }
    else{
        segtree[node]=(segtree[lt]*segtree[rt])%mdd;
    }
    return;
}


unsigned long long llrand() {
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return (r & 0xFFFFFFFFFFFFFFFFULL)%928037044463;
}


pair<bool,int> solve(LLI make, int cur){
 //   cout<<"in make: "<<make<<" cur "<<cur<<"\n";
  //  cout<<"in cur: "<<cur<<" make: "<<make<<"\n";
    if(cur==1){
        LLI dekhi=sqrt(make);
        if((dekhi*dekhi)==make){
            return make_pair(true,dekhi);
         //  cout<<dekhi<<" dia milse\n";
        }
        return make_pair(false,-1);
    }
    if(cur==2){
        int dpidx;
        if(cmprs2.find(make)!=cmprs2.end()){
            dpidx=cmprs2[make];
            return make_pair(true,dp[dpidx][cur]);
        }
        LLI dekhi=sqrt(make);
        pair<bool,int>oka;
        LLI damn;
        while(dekhi>=0 && (damn=(make-dekhi*dekhi))>=0){
            oka=solve(damn,cur-1);
            if(oka.first==true){
             //   cout<<dekhi<<" dia milse\n";
                dpidx=mapvals2;
                cmprs2[make]=dpidx;
                mapvals2++;
                dp[dpidx][cur]=dekhi;
                return make_pair(true,dp[dpidx][cur]);
            }
            dekhi--;
        }
        return make_pair(false,-1);
    }
    if(cur==3){
        int dpidx;
        if(cmprs1.find(make)!=cmprs1.end()){
            dpidx=cmprs1[make];
            return make_pair(true,dp[dpidx][cur]);
        }
        LLI dekhi=sqrt(make);
        pair<bool,int>oka;
        LLI damn;
        while(dekhi>=0 && (damn=(make-dekhi*dekhi))>=0){
            oka=solve(damn,cur-1);
            if(oka.first==true){
             //  cout<<dekhi<<" dia milse\n";
               dpidx=mapvals1;
                cmprs1[make]=dpidx;
                mapvals1++;
                dp[dpidx][cur]=dekhi;
                return make_pair(true,dp[dpidx][cur]);
            }
            dekhi--;
        }
        return make_pair(false,-1);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d %lld",&n,&q,&mdd);
        FREP(i,1,n){
            scanf("%lld",&arr[i]);
        }
        init(1,n,1);
      //  init2();
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
                    printf("bokachoda\n");
                    continue;
                }
                LLI twopow=1;
                /*while(multi>0 && multi%4==0){
                    multi/=4;
                    twopow*=2;
                }*/
                LLI dekhi=sqrt(multi);;
                LLI left;
                while(1){
                    left=multi-dekhi*dekhi;
                    twopow=1;
                    while(left>0 && left%4==0){
                        left/=4;
                        twopow*=2;
                    }
                    if((left-7)%8){
                        break;
                    }
                    dekhi--;
                }
                solve(left,3);
                LLI ans1=dekhi;
                int idx2=cmprs1[left];
                LLI ans2=dp[idx2][3];
                LLI left1=left-ans2*ans2;
                int idx3=cmprs2[left1];
                LLI ans3=dp[idx3][2];
                LLI ans4=sqrt(left1-ans3*ans3);
                printf("%lld %lld %lld %lld\n",abs(ans1),twopow*abs(ans2),twopow*abs(ans3),twopow*abs(ans4));
            }

        }
    }
    return 0;
}


