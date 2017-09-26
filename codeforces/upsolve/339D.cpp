#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define pi acos(-1.0)
#define float double
using namespace std;
//0=noop
//1=or
//2=xor
struct node{
    int val;
    int op;
    node(int _val=0, int _op=0){
        val=_val;
        op=_op;
    }
};

node segtree[500006];
int arr[100005];

void init(int b, int e, int node){
    if(b==e){
        segtree[node].val=arr[b];
        segtree[node].op=0;
        return ;
    }
    if(b>e)return;
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;
    init(b,mid,l);
    init(mid+1,e,r);
    if(segtree[l].op==0 || segtree[l].op==2){
        segtree[node].op=1;
    }
    else{
        segtree[node].op=2;
    }
    if(segtree[node].op==1){
        segtree[node].val=segtree[l].val|segtree[r].val;
    }
    else{
        segtree[node].val=segtree[l].val^segtree[r].val;
    }
    return;
}

void update(int k, int b, int e, int node, int val){
    if(b==e && b==k){
        segtree[node].val=val;
        return ;
    }
    if(k<b || k>e)return;
    if(b>e)return;
    int mid=(b+e)>>1;
    int l=node<<1;
    int r=l+1;
    update(k,b,mid,l,val);
    update(k,mid+1,e,r,val);
    if(segtree[node].op==1){
        segtree[node].val=segtree[l].val|segtree[r].val;
    }
    else{
        segtree[node].val=segtree[l].val^segtree[r].val;
    }
    return;
}

int main(){
    int N,Q;
    scanf("%d %d",&N,&Q);
    int until=1<<N;
    FREP(i,1,until)cin>>arr[i];
    init(1,until,1);
    FREP(i,1,Q){
        int k,val;
        scanf("%d %d",&k,&val);
        update(k,1,until,1,val);
        printf("%d\n",segtree[1].val);
    }
    return 0;
}
