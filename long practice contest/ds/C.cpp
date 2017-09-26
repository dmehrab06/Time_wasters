#include <cstdio>
#include <algorithm>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))

using namespace std;

struct info{
    int openneeded;
    int closedneeded;
    info(){
        openneeded=0;
        closedneeded=0;
    }
    info(int a,int b){
        openneeded=a;
        closedneeded=b;
    }
};

info segtree[120005];
char brckt[30005];
//b1 ar e1 hoilo row

//b2 ar e2 hoilo column
void init(int b, int e, int node){
    //cout<<"aschi\n";
    //cout<<b1<<" "<<b2<<" "<<e1<<" "<<e2<<" "<<node<<"\n";
    if(b==e){
        segtree[node].openneeded=(brckt[b]==')'?1:0);
        segtree[node].closedneeded=(brckt[b]=='('?1:0);
        return;
    }
    if(b>e)return;
    else{
  //  printf("in node %d, range %d to %d\n",node,b,e);
        int lt=node<<1;
        int rt=lt+1;
        int mid=(b+e)>>1;
        init(b,mid,lt);
        init(mid+1,e,rt);
        int canmatch=min(segtree[lt].closedneeded,segtree[rt].openneeded);
        segtree[node].openneeded=segtree[lt].openneeded+segtree[rt].openneeded-canmatch;
        segtree[node].closedneeded=segtree[lt].closedneeded+segtree[rt].closedneeded-canmatch;
        return;
    }
}

void update(int idx, int b,int e, int node){
    if(b==idx && e==idx){
        swap(segtree[node].openneeded,segtree[node].closedneeded);
        return;
    }
    if(e<idx || b>idx){
        return;
    }
    //if(b1>e1 || b2>e2)return;
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    update(idx,b,mid,lt);
    update(idx,mid+1,e,rt);
    //segtree[node]=segtree[left]+segtree[right];
    int canmatch=min(segtree[lt].closedneeded,segtree[rt].openneeded);
    segtree[node].openneeded=segtree[lt].openneeded+segtree[rt].openneeded-canmatch;
    segtree[node].closedneeded=segtree[lt].closedneeded+segtree[rt].closedneeded-canmatch;
    return;
}

int main(){
    for(int ii=1;ii<=10;++ii){
        printf("Test %d:\n",ii);
        int n;
        scanf("%d",&n);
        scanf("%s",brckt);
        init(0,n-1,1);
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;++i){
            int idx;
            scanf("%d",&idx);
            if(idx==0){
                if(!segtree[1].openneeded && !segtree[1].closedneeded){
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }
            }
            else{
                update(idx-1,0,n-1,1);
            }
        }
    }
    return 0;
}
