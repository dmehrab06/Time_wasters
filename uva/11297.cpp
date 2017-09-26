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

int grid[1003][1003];

int segtree[1400000];

void build(int node, int l1, int r1, int l2, int r2){
    //cout<<node<<" "<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<"\n";
    if(l1>l2 || r1>r2){
        //segtree[node]=0;
        return;
    }
    if(l1==l2 && r1==r2){
        segtree[node]=0;
        return;
    }
    int lmid = (l1+l2)/2; int rmid = (r1+r2)/2;
    int node3 = (node<<2); int node1 = node3-2; int node2 = node3-1; int node4 = node3+1;
    build(node1,l1,r1,lmid,rmid); build(node2,lmid+1,r1,l2,rmid);
    build(node3,l1,rmid+1,lmid,r2); build(node4,lmid+1,rmid+1,l2,r2);
    segtree[node]=segtree[node1]+segtree[node2]+segtree[node3]+segtree[node4];
    //cout<<"in node "<<node<<" "<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" has "<<segtree[node].first<<" "<<segtree[node].second<<"\n";
    return;
}

void update(int node, int l1, int r1, int l2, int r2, int x, int y, int val){
    if(l1>l2 || r1>r2 || l1>x || l2<x || r1>y || r2<y)return;
    if(l1==l2 && r1==r2 && l1==x && r1==y){
        segtree[node]+=val;
        return;
    }
    int lmid = (l1+l2)/2; int rmid = (r1+r2)/2;
    int node3 = (node<<2); int node1 = node3-2; int node2 = node3-1; int node4 = node3+1;
    update(node1,l1,r1,lmid,rmid,x,y,val); update(node2,lmid+1,r1,l2,rmid,x,y,val);
    update(node3,l1,rmid+1,lmid,r2,x,y,val); update(node4,lmid+1,rmid+1,l2,r2,x,y,val);
    segtree[node]=segtree[node1]+segtree[node2]+segtree[node3]+segtree[node4];
    return;
}

int query(int node, int l1, int r1, int l2, int r2, int x1, int y1, int x2, int y2){
    if(l1>l2 || r1>r2 || l1>x2 || l2<x1 || r1>y2 || r2<y1)return make_pair(0,1000000000);
    if(l1>=x1 && l2<=x2 && r1>=y1 && r2<=y2){
        //cout<<"from node "<<node<<" "<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" returning "<<segtree[node].first<<" "<<segtree[node].second<<"\n";
        return segtree[node];
    }
    int lmid = (l1+l2)/2; int rmid = (r1+r2)/2;
    int node3 = (node<<2); int node1 = node3-2; int node2 = node3-1; int node4 = node3+1;
    int ans1 = query(node1,l1,r1,lmid,rmid,x1,y1,x2,y2); int ans2 = query(node2,lmid+1,r1,l2,rmid,x1,y1,x2,y2);
    int ans3 = query(node3,l1,rmid+1,lmid,r2,x1,y1,x2,y2); int ans4 = query(node4,lmid+1,rmid+1,l2,r2,x1,y1,x2,y2);
    return ans1+ans2+ans3+ans4;
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        FREP(j,1,n){
            scanf("%d",&grid[i][j]);
        }
    }
    build(1,1,1,n,n);
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        char type[3];
        scanf("%s",type);
        if(type[0]=='q'){
            int x1, y1, x2, y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            PII ans = query(1,1,1,n,n,x1,y1,x2,y2);
            printf("%d %d\n",ans.first,ans.second);
        }
        else{
            int x,y,val;
            scanf("%d %d %d",&x,&y,&val);
            update(1,1,1,n,n,x,y,val);
        }
    }
    return 0;
}
