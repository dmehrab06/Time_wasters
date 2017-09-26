#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;





int segtree[400005];
int arr[100005];

void init(int b, int e, int node){
    if(b==e){
        segtree[node]=0;

    }
    else{
  //  printf("in node %d, range %d to %d\n",node,b,e);
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(b,mid,left);
    init(mid+1,e,right);
    segtree[node]=0;
    }
}

int query(int i, int j, int b, int e, int node,int nowval){
    //int cur=0;
    if(b>=i && e<=j){
        //cur=segtree[node];
        return nowval+segtree[node];
    }
    if(e<i || b>j){
        return 0;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    int valtoadd=0;
    if(i>=b && j<=e){
        valtoadd=segtree[node];
        int min1=query(i,j,b,mid,left,nowval+valtoadd);
        int min2=query(i,j,mid+1,e,right,nowval+valtoadd);
        return min1+min2;
    }
    else{
        return 0;
    }

}

void update(int i, int j, int b, int e, int node, int toadd){
    if(b>=i && e<=j){
        segtree[node]=segtree[node]+toadd;
        return;
    }
    if(e<i || b>j){
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    update(i,j,b,mid,left,toadd);
    update(i,j,mid+1,e,right,toadd);
    //segtree[node]=segtree[left]+segtree[right];
}

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)==2){
    //int cs=1;
        init(1,n,1);
        //int N,Q;
        //scanf("%d %d",&N,&Q);
        for(int i=1;i<=m;++i){
            int l,r,bonus;
            scanf("%d %d %d",&l,&r,&bonus);
            update(l,r,1,n,1,bonus);
           // cout<<"update hoise\n";
        }
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;++i){
            int p;
            scanf("%d",&p);
            //int i,j;
            //scanf("%d%d",&i,&j);
            int tot=query(p,p,1,n,1,0);
            //cout<<"query hoise\n";
            printf("%d\n",tot);

        }


    }
    return 0;
}
