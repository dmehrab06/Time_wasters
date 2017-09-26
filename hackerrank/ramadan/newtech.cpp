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

string doors;

char doorshifted[1000005];

struct nodestate{
    int len,o,c;
    nodestate(int _l=0, int _o=0, int _c=0){len=_l;o=_o;c=_c;}
};

nodestate segtree[5000006];

/*void print(int node, int b, int e){
    if(b==e){
        cout<<"in node "<<node<<" begin: "<<b<<" end: "<<e<<" contains "<<segtree[node].len<<" "<<segtree[node].o<<" "<<segtree[node].c<<"\n";
        return;
    }
    int mid=(b+e)/2;
    int l=node<<1; int r=node+1;
    print(l,b,mid); print(r,mid+1,e);
    cout<<"in node "<<node<<" begin: "<<b<<" end: "<<e<<" contains "<<segtree[node].len<<" "<<segtree[node].o<<" "<<segtree[node].c<<"\n";
    return;
}*/

void build(int node, int b, int e){
    if(b==e){
        segtree[node].len=0;
        if(doorshifted[b]=='O'){segtree[node].o=1;segtree[node].c=0;}
        else {segtree[node].c=1; segtree[node].o=0;}
        return;
    }
    int mid=(b+e)/2;
    int l=node<<1; int r=node+1;
    build(l,b,mid); build(r,mid+1,e);
    int t=min(segtree[l].o,segtree[r].c);
    segtree[node].len=segtree[l].len+segtree[r].len+2*t;
    segtree[node].o=segtree[l].o+segtree[r].o-t;
    segtree[node].c=segtree[l].c+segtree[r].c-t;
    return;
}

void update(int node, int b, int e, int idx){
    if(b==e && b==idx){
        segtree[node].len=0;
        if(doorshifted[b]=='O'){
            doorshifted[b]='C';
            segtree[node].o=0;
            segtree[node].c=1;
        }
        else{
            doorshifted[b]='O';
            segtree[node].o=1;
            segtree[node].c=0;
        }
        return;
    }
    if(e<idx || b>idx)return;
    int mid=(b+e)/2;
    int l=node<<1; int r=node+1;
    update(l,b,mid,idx); update(r,mid+1,e,idx);
    int t=min(segtree[l].o,segtree[r].c);
    segtree[node].len=segtree[l].len+segtree[r].len+2*t;
    segtree[node].o=segtree[l].o+segtree[r].o-t;
    segtree[node].c=segtree[l].c+segtree[r].c-t;
    return;
}

nodestate query(int node, int b, int e, int lft, int rgt){
    if(lft>=b && e<=rgt){
        return segtree[node];
    }
    if(b>rgt || e<lft)return nodestate(0,0,0);
    int mid=(b+e)/2;
    int l=node<<1; int r=node+1;
    nodestate lans=query(l,b,mid,lft,rgt); nodestate rans=query(r,mid+1,e,lft,rgt);
    int t=min(lans.o,rans.c);
    nodestate mynode(lans.len+rans.len+2*t,lans.o+rans.o-t,lans.c+rans.c-t);
    return mynode;
}

int main() {
    cin>>doors;
    int ll=doors.size();
    FREP(i,0,(ll-1)){
        doorshifted[i+1]=doors[i];
    }
    build(1,1,ll);
    //print(1,1,ll);
    int q;
    scanf("%d",&q);
    while(q--){
        char st[3];
        scanf("%s",st);
        if(st[0]=='R'){
            int idx;
            scanf("%d",&idx);
            update(1,1,ll,idx);
        }
        else{
            int l,r;
            scanf("%d %d",&l,&r);
            nodestate ans=query(1,1,ll,l,r);
            printf("%d\n",ans.len);
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
