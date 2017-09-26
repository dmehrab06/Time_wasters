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

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

PII item[4003];

vector < set<PII> > visits;

vector <VI>segtree;

int queryans[20005];

void build(int id, int l, int r, int tstart, int tfinish, int node){
    if(r<tstart || l>tfinish)return;
    if(l>=tstart && r<=tfinish){
        segtree[node].PB(id);
        return;
    }
    int m=(l+r)/2;
    build(id,l,m,tstart,tfinish,2*node);
    build(id,m+1,r,tstart,tfinish,2*node+1);
}

void solve(int node,int l, int r, VI curhappiness, int maxk){
    //cout<<"in node "<<node<<"\n";
    VI newhappiness=curhappiness;
    int ll=segtree[node].size();
    FREP(i,0,(ll-1)){
        int curitem=segtree[node][i];
        int cost=item[curitem].first;
        int hp=item[curitem].second;
        RFREP(k,maxk,0){
            if(k>=cost){
                newhappiness[k]=max(newhappiness[k],newhappiness[k-cost]+hp);
            }
        }
    }
    if(l==r){
        if(l>20001)return;
       set<PII>::iterator it;
        for(it=visits[l].begin();it!=visits[l].end();++it){
            PII oka=*it;
            int qidx=oka.second;
            int k=oka.first;
            //cout<<qidx<<"\n";
            queryans[qidx]=newhappiness[k];

        }
        return;
    }
    int m=(l+r)/2;
    solve(2*node,l,m,newhappiness,maxk);
    solve(2*node+1,m+1,r,newhappiness,maxk);
}

void takeiteminput(int n, int p){
    VI line;
    FREP(i,1,60005){
        segtree.PB(line);
    }
    FREP(i,1,n){
        int c,h,t;
        scanf("%d %d %d",&c,&h,&t);
        item[i]=make_pair(c,h);
        build(i,1,20005,t,t+p-1,1);
    }
}

int takeqinput(int q){
    set<PII>oka;
    int maxb=0;
    FREP(i,1,20000+3){
        visits.PB(oka);
    }
    FREP(i,1,q){
        int a,b;
        scanf("%d %d",&a,&b);
        visits[a].insert(make_pair(b,i));
        maxb=max(maxb,b);
    }
    return maxb;
}

void doit(int mxb){
    VI happy;
    FREP(i,0,mxb+2){
        happy.PB(0);
    }
    solve(1,1,20005,happy,mxb);
}

void printans(int q){
    FREP(i,1,q){
        printf("%d\n",queryans[i]);
    }
}

int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    takeiteminput(n,p);
    int q;
    scanf("%d",&q);
    int mxx=takeqinput(q);
    doit(mxx);
    printans(q);
}
